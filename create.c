#include "morriscript.h"
extern char *yytext;

MS_Interpreter *ms_get_interpreter()
{
    return interpreter;
}

MS_Interpreter *ms_create_interpreter()
{
    interpreter = (MS_Interpreter *)malloc(sizeof(MS_Interpreter));

    interpreter->variable = NULL;
    interpreter->function_list = NULL;
    interpreter->statement_list = NULL;
    interpreter->class_list = NULL;
    interpreter->current_line_number = 1;

    return interpreter;
}

void ms_create_function(MS_Boolean isClosure, char *identifier, ParameterList *parameter_list, Block *block)
{
    FunctionDefinition *f;

    // if (ms_search_function(identifier))
    // {
    //     ms_compile_error(FUNCTION_MULTIPLE_DEFINE_ERR,
    //                       STRING_MESSAGE_ARGUMENT, "name", identifier,
    //                       MESSAGE_ARGUMENT_END);
    //     return;
    // }
    FunctionDefinition *fl = ms_get_interpreter()->function_list;
    FunctionDefinition *p = fl;

    while (p != NULL)
    {
        if (strcmp(p->name, identifier) == 0 && isClosure == MS_FALSE)
        {
            printf("Error type 4 at Line %d: Redefined function \"%s\".\n", ms_get_interpreter()->current_line_number, yytext);
            return;
        }
        p = p->next;
    }

    f = (FunctionDefinition *)malloc(sizeof(FunctionDefinition));
    f->isClosure = isClosure;
    f->name = identifier;
    f->type = MS_FUNCTION_DEFINITION;
    f->parameter = parameter_list;
    f->block = block;
    f->line_number = ms_get_interpreter()->current_line_number;
    f->next = ms_get_interpreter()->function_list;
    ms_get_interpreter()->function_list = f;
}

void ms_create_class(char *identifier, Block *block)
{
    ClassDefinition *c;

    ClassDefinition *cl = ms_get_interpreter()->class_list;
    ClassDefinition *p = cl;

    while (p != NULL)
    {
        if (strcmp(p->name, identifier) == 0)
        {
            printf("Error type 16 at Line %d: Duplicated name \"Position\".\n", ms_get_interpreter()->current_line_number);
            return;
        }
        p = p->next;
    }

    c = (ClassDefinition *)malloc(sizeof(ClassDefinition));
    c->name = identifier;
    c->block = block;
    c->line_number = ms_get_interpreter()->current_line_number;
    c->next = ms_get_interpreter()->class_list;
    ms_get_interpreter()->class_list = c;
}

void ms_create_variable(char *name, MS_Boolean isObject, MS_Boolean isArray)
{
    // Search name in Variable List, if exist, error.
    Variable *vl = ms_get_interpreter()->variable;
    Variable *p = vl;

    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", ms_get_interpreter()->current_line_number, yytext);
            return;
        }
        p = p->next;
    }

    Variable *v;
    v = (Variable *)malloc(sizeof(Variable));
    v->name = name;
    v->isArray = isArray;
    v->isObject = isObject;
    v->next = ms_get_interpreter()->variable;
    v->value.type = MS_NULL_VALUE;
    ms_get_interpreter()->variable = v;
}

ParameterList *ms_create_parameter(char *identifier, MS_Boolean isObject, MS_Boolean isArray)
{
    ParameterList *pl;

    pl = (ParameterList *)malloc(sizeof(ParameterList));
    pl->name = identifier;
    pl->line_number = ms_get_interpreter()->current_line_number;
    pl->next = NULL;

    ms_create_variable(identifier, isObject, isArray);

    return pl;
}
ParameterList *ms_chain_parameter(char *identifier, ParameterList *list)
{
    ParameterList *pos;

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = ms_create_parameter(identifier, MS_FALSE, MS_FALSE);

    return list;
}
ArgumentList *ms_create_argument_list(Expression *expression)
{
    ArgumentList *al;

    al = (ArgumentList *)malloc(sizeof(ArgumentList));
    al->expression = expression;
    al->line_number = ms_get_interpreter()->current_line_number;
    al->next = NULL;

    return al;
}
ArgumentList *ms_chain_argument_list(ArgumentList *list, Expression *expr)
{
    ArgumentList *pos;

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = ms_create_argument_list(expr);

    return list;
}
StatementList *ms_create_statement_list(Statement *statement)
{
    StatementList *sl;

    sl = (StatementList *)malloc(sizeof(StatementList));
    sl->statement = statement;
    sl->line_number = ms_get_interpreter()->current_line_number;
    sl->next = NULL;

    return sl;
}
StatementList *ms_chain_statement_list(StatementList *list, Statement *statement)
{
    StatementList *pos;

    if (list == NULL)
    {
        return ms_create_statement_list(statement);
    }

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = ms_create_statement_list(statement);

    return list;
}

// Expression
Expression *ms_alloc_expression(ExpressionType type)
{
    Expression *exp;

    exp = (Expression *)malloc(sizeof(Expression));
    exp->type = type;
    exp->line_number = ms_get_interpreter()->current_line_number;

    return exp;
}
Expression *ms_create_assign_expression(Expression *priExp, Expression *operand)
{
    if (priExp->type != IDENTIFIER_EXPRESSION && priExp->type != ARRAY_USE_EXPRESSION)
    {
        printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", ms_get_interpreter()->current_line_number);
        return NULL;
    }

    if (operand->type == CLASS_NEW_EXPRESSION)
    {
        Variable *vl = ms_get_interpreter()->variable;
        Variable *p = vl;

        while (p != NULL)
        {
            if (strcmp(p->name, priExp->u.identifier) == 0)
            {
                break;
            }
            p = p->next;
        }
        p->isObject = MS_TRUE;
    }

    Expression *exp;

    exp = ms_alloc_expression(ASSIGN_EXPRESSION);
    exp->u.assign_expression.variable = priExp->u.identifier;
    exp->u.assign_expression.operand = operand;

    return exp;
}
Expression convert_value_to_expression(MS_Value *v)
{
    Expression expr;

    if (v->type == MS_INT_VALUE)
    {
        expr.type = INT_EXPRESSION;
        expr.u.int_value = v->u.int_value;
    }
    else if (v->type == MS_DOUBLE_VALUE)
    {
        expr.type = DOUBLE_EXPRESSION;
        expr.u.double_value = v->u.double_value;
    }
    else
    {
        expr.type = BOOLEAN_EXPRESSION;
        expr.u.boolean_value = v->u.boolean_value;
    }
    return expr;
}
Expression *ms_create_binary_expression(ExpressionType operator, Expression *left, Expression *right)
{
    if (left->type != right->type && left->type != CLASS_USE_EXPRESSION)
    {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n", ms_get_interpreter()->current_line_number);
        return NULL;
    }

    Expression *exp;

    exp = ms_alloc_expression(operator);
    exp->u.binary_expression.left = left;
    exp->u.binary_expression.right = right;

    return exp;
}
Expression *ms_create_minus_expression(Expression *operand)
{
    Expression *exp;

    exp = ms_alloc_expression(MINUS_EXPRESSION);
    exp->u.minus_expression = operand;

    return exp;
}
Expression *ms_create_identifier_expression(char *identifier)
{
    Expression *exp;

    exp = ms_alloc_expression(IDENTIFIER_EXPRESSION);
    exp->u.identifier = identifier;

    return exp;
}
Expression *ms_create_function_call_expression(char *func_name, ArgumentList *argument)
{
    Expression *exp;

    exp = ms_alloc_expression(FUNCTION_CALL_EXPRESSION);
    exp->u.function_call_expression.identifier = func_name;
    exp->u.function_call_expression.argument = argument;

    return exp;
}

Expression *ms_create_array_use_expression(char *identifier, Expression *priExp)
{
    if (priExp->type != INT_EXPRESSION)
    {
        printf("Error type 12 at Line %d: \"%s\" is not an integer.\n", ms_get_interpreter()->current_line_number, yytext);
    }

    Expression *exp;

    exp = ms_alloc_expression(ARRAY_USE_EXPRESSION);
    exp->u.array_use_expression.identifier = identifier;

    return exp;
}
Expression *ms_create_class_use_expression(char *class_name, char *member)
{
    Expression *exp;

    exp = ms_alloc_expression(CLASS_USE_EXPRESSION);
    exp->u.class_use_expression.identifier = class_name;
    exp->u.class_use_expression.member = member;

    return exp;
}
Expression *ms_create_class_new_expression(char *class_name)
{
    Expression *exp;

    exp = ms_alloc_expression(CLASS_NEW_EXPRESSION);
    exp->u.class_use_expression.identifier = class_name;

    return exp;
}
Expression *ms_create_boolean_expression(MS_Boolean value)
{
    Expression *exp;

    exp = ms_alloc_expression(BOOLEAN_EXPRESSION);
    exp->u.boolean_value = value;

    return exp;
}
Expression *ms_create_null_expression(void)
{
    Expression *exp;

    exp = ms_alloc_expression(NULL_EXPRESSION);

    return exp;
}
Expression *ms_create_closure_definition(ParameterList *parameter_list, Block *block)
{
    Expression *exp;

    exp = ms_alloc_expression(CLOSURE_EXPRESSION);
    ms_create_function(MS_TRUE, NULL, parameter_list, block);
    exp->u.closure.function_definition = ms_get_interpreter()->function_list;

    return exp;
}

// Statement
static Statement *ms_alloc_statement(StatementType type)
{
    Statement *st;

    st = (Statement *)malloc(sizeof(Statement));
    st->type = type;
    st->line_number = ms_get_interpreter()->current_line_number;

    return st;
}
Statement *ms_create_global_statement(IdentifierList *identifier_list)
{
    Statement *st;

    st = ms_alloc_statement(GLOBAL_STATEMENT);
    st->u.global_s.identifier_list = identifier_list;

    return st;
}
Statement *ms_create_let_statement(IdentifierList *identifier_list)
{
    Statement *st;

    st = ms_alloc_statement(LET_STATEMENT);
    st->u.let_s.identifier_list = identifier_list;

    IdentifierList *p = identifier_list;
    while (p != NULL)
    {
        ms_create_variable(p->name, p->isObject, p->isArray);
        p = p->next;
    }

    return st;
}
IdentifierList *ms_create_global_identifier(char *identifier, MS_Boolean isObject, MS_Boolean isArray)
{
    IdentifierList *i_list;

    i_list = (IdentifierList *)malloc(sizeof(IdentifierList));
    i_list->name = identifier;
    i_list->line_number = ms_get_interpreter()->current_line_number;
    i_list->isObject = isObject;
    i_list->isArray = isArray;
    i_list->next = NULL;
    i_list->type = VARIABLE_IDENTIFIER;

    return i_list;
}
IdentifierList *ms_chain_identifier(IdentifierList *list, char *identifier)
{
    IdentifierList *pos;

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = ms_create_global_identifier(identifier, MS_FALSE, MS_FALSE);

    return list;
}
Statement *ms_create_if_statement(Expression *condition, Block *then_block, Elsif *elsif_list, Block *else_block)
{
    Statement *st;

    st = ms_alloc_statement(IF_STATEMENT);
    st->u.if_s.condition = condition;
    st->u.if_s.then_block = then_block;
    st->u.if_s.elsif_list = elsif_list;
    st->u.if_s.else_block = else_block;

    return st;
}
Elsif *ms_chain_elsif_list(Elsif *list, Elsif *add)
{
    Elsif *pos;

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = add;

    return list;
}
Elsif *ms_create_elsif(Expression *expr, Block *block)
{
    Elsif *elsf;

    elsf = (Elsif *)malloc(sizeof(Elsif));
    elsf->condition = expr;
    elsf->block = block;
    elsf->line_number = ms_get_interpreter()->current_line_number;
    elsf->next = NULL;

    return elsf;
}
Statement *ms_create_while_statement(Expression *condition, Block *block)
{
    Statement *st;

    st = ms_alloc_statement(WHILE_STATEMENT);
    st->u.while_s.condition = condition;
    st->u.while_s.block = block;

    return st;
}
Statement *ms_create_for_statement(Expression *init, Expression *cond, Expression *post, Block *block)
{
    Statement *st;

    st = ms_alloc_statement(FOR_STATEMENT);
    st->u.for_s.init = init;
    st->u.for_s.condition = cond;
    st->u.for_s.post = post;
    st->u.for_s.block = block;

    return st;
}
Block *ms_create_block(StatementList *statement_list)
{
    Block *block;

    block = (Block *)malloc(sizeof(Block));
    block->statement_list = statement_list;
    block->line_number = ms_get_interpreter()->current_line_number;

    return block;
}
Statement *ms_create_expression_statement(Expression *expression)
{
    Statement *st;

    st = ms_alloc_statement(EXPRESSION_STATEMENT);
    st->u.expression_s = expression;

    return st;
}
Statement *ms_create_return_statement(Expression *expression)
{
    Statement *st;

    st = ms_alloc_statement(RETURN_STATEMENT);
    st->u.return_s.return_value = expression;

    return st;
}
Statement *ms_create_break_statement(void)
{
    return ms_alloc_statement(BREAK_STATEMENT);
}
Statement *ms_create_continue_statement(void)
{
    return ms_alloc_statement(CONTINUE_STATEMENT);
}