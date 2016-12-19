#include "morriscript.h"
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
    interpreter->current_line_number = 1;

    return interpreter;
}

void ms_create_function(char *identifier, ParameterList *parameter_list, Block *block)
{
    FunctionDefinition *f;

    // if (ms_search_function(identifier))
    // {
    //     ms_compile_error(FUNCTION_MULTIPLE_DEFINE_ERR,
    //                       STRING_MESSAGE_ARGUMENT, "name", identifier,
    //                       MESSAGE_ARGUMENT_END);
    //     return;
    // }

    f = (FunctionDefinition *)malloc(sizeof(FunctionDefinition));
    f->name = identifier;
    f->type = MS_FUNCTION_DEFINITION;
    f->parameter = parameter_list;
    f->block = block;
    f->line_number = ms_get_interpreter()->current_line_number;
    f->next = interpreter->function_list;
    interpreter->function_list = f;
}
void ms_create_anonymous(ParameterList *parameter_list, Block *block)
{
    FunctionDefinition *a;

    a = (FunctionDefinition *)malloc(sizeof(FunctionDefinition));
    a->name = NULL;
    a->type = MS_ANONYMOUS_DEFINITION;
    a->parameter = parameter_list;
    a->block = block;
    a->line_number = ms_get_interpreter()->current_line_number;
    a->next = interpreter->function_list;
    interpreter->function_list = a;
}
ParameterList *ms_create_parameter(char *identifier)
{
    ParameterList *pl;

    pl = (ParameterList *)malloc(sizeof(ParameterList));
    pl->name = identifier;
    pl->line_number = ms_get_interpreter()->current_line_number;
    pl->next = NULL;

    return pl;
}
ParameterList *ms_chain_parameter(ParameterList *list, char *identifier)
{
    ParameterList *pos;

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = ms_create_parameter(identifier);

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
Expression *ms_create_assign_expression(char *variable, Expression *operand)
{
    Expression *exp;

    exp = ms_alloc_expression(ASSIGN_EXPRESSION);
    exp->u.assign_expression.variable = variable;
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
    // MS_Value v;
    // if (left->type == INT_EXPRESSION && right->type == INT_EXPRESSION)
    // {
    //     v = crb_eval_binary_expression(ms_get_interpreter(), NULL, operator, left, right);
    //     *left = convert_value_to_expression(&v);
    //     return left;
    // }
    // else if (left->type == INT_EXPRESSION && right->type == DOUBLE_EXPRESSION)
    // {
    //     *left = convert_value_to_expression(&v);
    //     return left;
    // }
    // else if (left->type == DOUBLE_EXPRESSION && right->type == INT_EXPRESSION)
    // {
    //     *left = convert_value_to_expression(&v);
    //     return left;
    // }
    // else if (left->type == DOUBLE_EXPRESSION && right->type == INT_EXPRESSION)
    // {
    //     *left = convert_value_to_expression(&v);
    //     return left;
    // }
    // else
    // {
    Expression *exp;

    exp = ms_alloc_expression(operator);
    exp->u.binary_expression.left = left;
    exp->u.binary_expression.right = right;

    return exp;
    // }
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

    return st;
}
IdentifierList *ms_create_global_identifier(char *identifier, Expression *length)
{
    IdentifierList *i_list;

    i_list = (IdentifierList *)malloc(sizeof(IdentifierList));
    i_list->name = identifier;
    i_list->line_number = ms_get_interpreter()->current_line_number;
    i_list->next = NULL;

    if (length != NULL)
    {
        i_list->type = ARRAY_IDENTIFIER;
        i_list->length = length->u.int_value;
    }
    else
    {
        i_list->type = VARIABLE_IDENTIFIER;
        i_list->length = 0;
    }

    return i_list;
}
IdentifierList *ms_chain_identifier(IdentifierList *list, char *identifier)
{
    IdentifierList *pos;

    for (pos = list; pos->next; pos = pos->next)
        ;
    pos->next = ms_create_global_identifier(identifier, 0);

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