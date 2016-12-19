#include "morriscript.h"

void ms_traverse(MS_Interpreter *interpreter, int blank)
{
    if (interpreter != NULL)
    {
        create_blank(blank);
        printf("Interpreter (1)\n");
        ms_traverse_variable(interpreter->variable, blank + 2);
        ms_traverse_function(interpreter->function_list, blank + 2);
        ms_traverse_statement_list(interpreter->statement_list, blank + 2);
    }
}

void ms_traverse_variable(Variable *variable, int blank)
{
    if (variable != NULL)
    {
        create_blank(blank);
        printf("%s: ", variable->name);
        switch (variable->value.type)
        {
        case MS_BOOLEAN_VALUE:
            if (variable->value.u.boolean_value == MS_TRUE)
            {
                printf("TRUE");
            }
            else
            {
                printf("FALSE");
            }
            break;
        case MS_INT_VALUE:
            printf("%d", variable->value.u.int_value);
            break;
        case MS_DOUBLE_VALUE:
            printf("%f", variable->value.u.double_value);
            break;
        case MS_STRING_VALUE:
            printf("%s", variable->value.u.string_value->string);
            break;
        default:
            break;
        }
        printf("\n");
        ms_traverse_variable(variable->next, blank);
    }
}

void ms_traverse_function(FunctionDefinition *func, int blank)
{
    if (func != NULL)
    {
        create_blank(blank);
        printf("Function: %s (%d)\n", func->name, func->line_number);
        ms_traverse_parameter_list(func->parameter, blank + 2);
        ms_traverse_block(func->block, blank + 2);
        ms_traverse_function(func->next, blank);
    }
}

void ms_traverse_statement_list(StatementList *stmtList, int blank)
{
    if (stmtList != NULL)
    {
        create_blank(blank);
        printf("StatementList (%d)\n", stmtList->line_number);
        ms_traverse_statement(stmtList->statement, blank + 2);
        ms_traverse_statement_list(stmtList->next, blank);
    }
}

void ms_traverse_parameter_list(ParameterList *paraList, int blank)
{
    if (paraList != NULL)
    {
        create_blank(blank);
        printf("Parameter: %s (%d)\n", paraList->name, paraList->line_number);
        ms_traverse_parameter_list(paraList->next, blank);
    }
}
void ms_traverse_argument_list(ArgumentList *agmtList, int blank)
{
    if (agmtList != NULL)
    {
        create_blank(blank);
        printf("ArgumentList (%d)\n", agmtList->line_number);
        ms_traverse_expression(agmtList->expression, blank + 2);
        ms_traverse_argument_list(agmtList->next, blank);
    }
}

void ms_traverse_expression(Expression *expression, int blank)
{
    if (expression != NULL)
    {
        create_blank(blank);
        printf("EXPRESSION: ");
        switch (expression->type)
        {
        case BOOLEAN_EXPRESSION:
            if (expression->u.boolean_value == MS_TRUE)
            {
                printf("TRUE");
            }
            else
            {
                printf("FALSE");
            }
            printf(" (%d)\n", expression->line_number);
            break;
        case INT_EXPRESSION:
            printf("%d (%d)\n", expression->u.int_value, expression->line_number);
            break;
        case DOUBLE_EXPRESSION:
            printf("%f (%d)\n", expression->u.double_value, expression->line_number);
            break;
        case STRING_EXPRESSION:
            printf("%s (%d)\n", expression->u.string_value, expression->line_number);
            break;
        case IDENTIFIER_EXPRESSION:
            printf("%s (%d)\n", expression->u.identifier, expression->line_number);
            break;
        case ASSIGN_EXPRESSION:
            printf("= (%d)\n", expression->line_number);
            ms_traverse_assign_expression(expression->u.assign_expression, blank);
            break;
        case ADD_EXPRESSION:
            printf("+ (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case SUB_EXPRESSION:
            printf("- (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case MUL_EXPRESSION:
            printf("* (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case DIV_EXPRESSION:
            printf("/ (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case MOD_EXPRESSION:
            printf("% (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case EQ_EXPRESSION:
            printf("== (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case NE_EXPRESSION:
            printf("!= (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case GT_EXPRESSION:
            printf("> (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case GE_EXPRESSION:
            printf(">= (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case LT_EXPRESSION:
            printf("< (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case LE_EXPRESSION:
            printf("<= (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case LOGICAL_AND_EXPRESSION:
            printf("&& (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case LOGICAL_OR_EXPRESSION:
            printf("|| (%d)\n", expression->line_number);
            ms_traverse_binary_expression(expression->u.binary_expression, blank);
            break;
        case MINUS_EXPRESSION:
            printf("- (%d)\n", expression->line_number);
            ms_traverse_expression(expression->u.minus_expression, blank);
            break;
        case FUNCTION_CALL_EXPRESSION:
            printf("(%d)\n", expression->line_number);
            ms_traverse_function_call_expression(expression->u.function_call_expression, blank);
            break;
        default:
            break;
        }
    }
}
void ms_traverse_statement(Statement *statement, int blank)
{
    if (statement != NULL)
    {
        create_blank(blank);
        printf("STATEMENT: ");
        switch (statement->type)
        {
        case EXPRESSION_STATEMENT:
            printf("(%d)\n", statement->line_number);
            ms_traverse_expression(statement->u.expression_s, blank + 2);
            break;
        case GLOBAL_STATEMENT:
            printf("Global (%d)\n", statement->line_number);
            ms_traverse_identifier_list(statement->u.global_s.identifier_list, blank + 2);
            break;
        case LET_STATEMENT:
            printf("Let (%d)\n", statement->line_number);
            ms_traverse_identifier_list(statement->u.let_s.identifier_list, blank + 2);
            break;
        case IF_STATEMENT:
            printf("If (%d)\n", statement->line_number);
            ms_traverse_if_statement(statement->u.if_s, blank);
            break;
        case WHILE_STATEMENT:
            printf("While (%d)\n", statement->line_number);
            ms_traverse_while_statement(statement->u.while_s, blank);
            break;
        case FOR_STATEMENT:
            printf("For (%d)\n", statement->line_number);
            ms_traverse_for_statement(statement->u.for_s, blank);
            break;
        case RETURN_STATEMENT:
            printf("Return (%d)\n", statement->line_number);
            ms_traverse_return_statement(statement->u.return_s, blank);
            break;
        case BREAK_STATEMENT:
            printf("Break (%d)\n", statement->line_number);
            break;
        case CONTINUE_STATEMENT:
            printf("Continue (%d)\n", statement->line_number);
            break;
        default:
            break;
        }
    }
}

void ms_traverse_block(Block *block, int blank)
{
    if (block != NULL)
    {
        create_blank(blank);
        printf("Block (%d)\n", block->line_number);
        ms_traverse_statement_list(block->statement_list, blank + 2);
    }
}

void ms_traverse_elsif(Elsif *elsif, int blank)
{
    if (elsif != NULL)
    {
        create_blank(blank);
        printf("Elsif (%d)\n", elsif->line_number);
        ms_traverse_expression(elsif->condition, blank + 2);
        ms_traverse_block(elsif->block, blank + 2);
        ms_traverse_elsif(elsif->next, blank);
    }
}

void ms_traverse_identifier_list(IdentifierList *idList, int blank)
{
    if (idList != NULL)
    {
        create_blank(blank);
        printf("Identifier: %s (%d)\n", idList->name, idList->line_number);
        ms_traverse_identifier_list(idList->next, blank);
    }
}

void ms_traverse_assign_expression(AssignExpression asnExp, int blank)
{
    create_blank(blank + 2);
    printf("Variable: %s\n", asnExp.variable);
    ms_traverse_expression(asnExp.operand, blank + 2);
}

void ms_traverse_binary_expression(BinaryExpression binExp, int blank)
{
    // create_blank(blank);
    ms_traverse_expression(binExp.left, blank + 2);
    ms_traverse_expression(binExp.right, blank + 2);
}
void ms_traverse_function_call_expression(FunctionCallExpression funcCall, int blank)
{
    create_blank(blank);
    printf("CALL: %s\n", funcCall.identifier);
    ms_traverse_argument_list(funcCall.argument, blank + 2);
}

void ms_traverse_if_statement(IfStatement ifStmt, int blank)
{
    // create_blank(blank);
    ms_traverse_expression(ifStmt.condition, blank + 2);
    ms_traverse_block(ifStmt.then_block, blank + 2);
    ms_traverse_elsif(ifStmt.elsif_list, blank + 2);
    ms_traverse_block(ifStmt.else_block, blank + 2);
}
void ms_traverse_while_statement(WhileStatement whileStmt, int blank)
{
    // create_blank(blank);
    ms_traverse_expression(whileStmt.condition, blank + 2);
    ms_traverse_block(whileStmt.block, blank + 2);
}
void ms_traverse_for_statement(ForStatement forStmt, int blank)
{
    // create_blank(blank);
    ms_traverse_expression(forStmt.init, blank + 2);
    ms_traverse_expression(forStmt.condition, blank + 2);
    ms_traverse_expression(forStmt.post, blank + 2);
    ms_traverse_block(forStmt.block, blank + 2);
}
void ms_traverse_return_statement(ReturnStatement returnStmt, int blank)
{
    // create_blank(blank);
    ms_traverse_expression(returnStmt.return_value, blank + 2);
}
void create_blank(int blank)
{
    while (blank-- > 0)
    {
        printf(" ");
    }
}