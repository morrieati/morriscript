#ifndef PRIVATE_MORRISCRIPT_H_INCLUDED
#define PRIVATE_MORRISCRIPT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MS_TRUE = 1,
    MS_FALSE = 0,
} MS_Boolean;

typedef struct MS_String_tag MS_String;

typedef enum {
    MS_BOOLEAN_VALUE = 1,
    MS_INT_VALUE,
    MS_DOUBLE_VALUE,
    MS_STRING_VALUE,
    MS_NULL_VALUE
} MS_ValueType;

typedef struct
{
    MS_ValueType type;
    union {
        MS_Boolean boolean_value;
        int int_value;
        double double_value;
        MS_String *string_value;
    } u;
} MS_Value;

typedef struct Expression_tag Expression;

typedef enum {
    BOOLEAN_EXPRESSION = 1,
    INT_EXPRESSION,
    DOUBLE_EXPRESSION,
    STRING_EXPRESSION,
    IDENTIFIER_EXPRESSION,
    ASSIGN_EXPRESSION,
    ADD_EXPRESSION,
    SUB_EXPRESSION,
    MUL_EXPRESSION,
    DIV_EXPRESSION,
    MOD_EXPRESSION,
    EQ_EXPRESSION,
    NE_EXPRESSION,
    GT_EXPRESSION,
    GE_EXPRESSION,
    LT_EXPRESSION,
    LE_EXPRESSION,
    LOGICAL_AND_EXPRESSION,
    LOGICAL_OR_EXPRESSION,
    MINUS_EXPRESSION,
    FUNCTION_CALL_EXPRESSION,
    ARRAY_USE_EXPRESSION,
    CLASS_USE_EXPRESSION,
    CLASS_NEW_EXPRESSION,
    NULL_EXPRESSION,
    CLOSURE_EXPRESSION,
    EXPRESSION_TYPE_COUNT_PLUS_1
} ExpressionType;

typedef struct ArgumentList_tag
{
    Expression *expression;
    int line_number;
    struct ArgumentList_tag *next;
} ArgumentList;

typedef struct
{
    char *variable;
    Expression *operand;
} AssignExpression;

typedef struct
{
    Expression *left;
    Expression *right;
} BinaryExpression;

typedef struct
{
    char *identifier;
    ArgumentList *argument;
} FunctionCallExpression;

typedef struct
{
    char *identifier;
    char *member;
} ClassUseExpression;

typedef struct
{
    char *identifier;
} ClassNewExpression;

typedef struct FunctionDefinition_tag FunctionDefinition;

typedef struct
{
    FunctionDefinition *function_definition;
} ClosureExpression;

typedef struct
{
    char *identifier;
} ArrayUseExpression;

struct Expression_tag
{
    ExpressionType type;
    int line_number;
    union {
        MS_Boolean boolean_value;
        int int_value;
        double double_value;
        char *string_value;
        char *identifier;
        AssignExpression assign_expression;
        BinaryExpression binary_expression;
        Expression *minus_expression;
        FunctionCallExpression function_call_expression;
        ArrayUseExpression array_use_expression;
        ClassUseExpression class_use_expression;
        ClassNewExpression class_new_expression;
        ClosureExpression closure;
    } u;
};

typedef struct Statement_tag Statement;

typedef struct StatementList_tag
{
    Statement *statement;
    int line_number;
    struct StatementList_tag *next;
} StatementList;

typedef struct
{
    StatementList *statement_list;
    int line_number;
} Block;

typedef enum {
    VARIABLE_IDENTIFIER = 1,
    IDENTIFIER_TYPE_COUNT_PLUS_1
} IdentifierType;

typedef struct IdentifierList_tag
{
    IdentifierType type;

    char *name;
    int line_number;
    MS_Boolean isObject;
    MS_Boolean isArray;
    struct IdentifierList_tag *next;
} IdentifierList;

typedef struct
{
    IdentifierList *identifier_list;
} GlobalStatement;

typedef struct
{
    IdentifierList *identifier_list;
} LetStatement;

typedef struct Elsif_tag
{
    Expression *condition;
    Block *block;
    int line_number;
    struct Elsif_tag *next;
} Elsif;

typedef struct
{
    Expression *condition;
    Block *then_block;
    Elsif *elsif_list;
    Block *else_block;
} IfStatement;

typedef struct
{
    Expression *condition;
    Block *block;
} WhileStatement;

typedef struct
{
    Expression *init;
    Expression *condition;
    Expression *post;
    Block *block;
} ForStatement;

typedef struct
{
    Expression *return_value;
} ReturnStatement;

typedef enum {
    EXPRESSION_STATEMENT = 1,
    GLOBAL_STATEMENT,
    LET_STATEMENT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    RETURN_STATEMENT,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,
    STATEMENT_TYPE_COUNT_PLUS_1
} StatementType;

struct Statement_tag
{
    StatementType type;
    int line_number;
    union {
        Expression *expression_s;
        GlobalStatement global_s;
        LetStatement let_s;
        IfStatement if_s;
        WhileStatement while_s;
        ForStatement for_s;
        ReturnStatement return_s;
    } u;
};

typedef struct ParameterList_tag
{
    char *name;
    int line_number;
    struct ParameterList_tag *next;
} ParameterList;

typedef enum {
    MS_FUNCTION_DEFINITION = 1,
} FunctionDefinitionType;

typedef struct FunctionDefinition_tag
{
    char *name;
    FunctionDefinitionType type;
    MS_Boolean isClosure;

    ParameterList *parameter;
    Block *block;

    int line_number;

    struct FunctionDefinition_tag *next;
} FunctionDefinition;

typedef struct ClassDefinition_tag
{
    char *name;

    Block *block;

    int line_number;
    struct ClassDefinition_tag *next;
} ClassDefinition;

typedef struct Variable_tag
{
    char *name;
    MS_Boolean isObject;
    MS_Boolean isArray;
    MS_Value value;
    struct Variable_tag *next;
} Variable;

typedef enum {
    NORMAL_STATEMENT_RESULT = 1,
    RETURN_STATEMENT_RESULT,
    BREAK_STATEMENT_RESULT,
    CONTINUE_STATEMENT_RESULT,
    STATEMENT_RESULT_TYPE_COUNT_PLUS_1
} StatementResultType;

typedef struct
{
    StatementResultType type;
    union {
        MS_Value return_value;
    } u;
} StatementResult;

typedef struct GlobalVariableRef_tag
{
    Variable *variable;
    struct GlobalVariableRef_tag *next;
} GlobalVariableRef;

typedef struct
{
    Variable *variable;
    GlobalVariableRef *global_variable;
} LocalEnvironment;

struct MS_String_tag
{
    int ref_count;
    char *string;
    MS_Boolean is_literal;
};

typedef struct
{
    MS_String *strings;
} StringPool;

typedef struct MS_Interpreter_tag
{
    Variable *variable;
    FunctionDefinition *function_list;
    StatementList *statement_list;
    ClassDefinition *class_list;
    int current_line_number;
} MS_Interpreter;

static MS_Interpreter *interpreter;
MS_Interpreter *ms_get_interpreter();
MS_Interpreter *ms_create_interpreter();

void ms_create_function(MS_Boolean isClosure, char *identifier, ParameterList *parameter_list, Block *block);
void ms_create_class(char *identifier, Block *block);
void ms_create_variable(char *name, MS_Boolean isObject, MS_Boolean isArray);
ParameterList *ms_create_parameter(char *identifier, MS_Boolean isObject, MS_Boolean isArray);
ParameterList *ms_chain_parameter(char *identifier, ParameterList *list);
ArgumentList *ms_create_argument_list(Expression *expression);
ArgumentList *ms_chain_argument_list(ArgumentList *list, Expression *expr);
StatementList *ms_create_statement_list(Statement *statement);
StatementList *ms_chain_statement_list(StatementList *list, Statement *statement);

// Expression
Expression *ms_alloc_expression(ExpressionType type);
Expression *ms_create_assign_expression(Expression *priExp, Expression *operand);
Expression convert_value_to_expression(MS_Value *v);
Expression *ms_create_binary_expression(ExpressionType operator, Expression *left, Expression *right);
Expression *ms_create_minus_expression(Expression *operand);
Expression *ms_create_identifier_expression(char *identifier);
Expression *ms_create_function_call_expression(char *func_name, ArgumentList *argument);
Expression *ms_create_boolean_expression(MS_Boolean value);
Expression *ms_create_null_expression(void);
Expression *ms_create_array_use_expression(char *identifier, Expression *priExp);
Expression *ms_create_class_use_expression(char *class_name, char *member);
Expression *ms_create_class_new_expression(char *class_name);
Expression *ms_create_closure_definition(ParameterList *parameter_list, Block *block);

// Statement
static Statement *ms_alloc_statement(StatementType type);
Statement *ms_create_global_statement(IdentifierList *identifier_list);
Statement *ms_create_let_statement(IdentifierList *identifier_list);
IdentifierList *ms_create_global_identifier(char *identifier, MS_Boolean isObject, MS_Boolean isArray);
IdentifierList *ms_chain_identifier(IdentifierList *list, char *identifier);
Statement *ms_create_if_statement(Expression *condition, Block *then_block, Elsif *elsif_list, Block *else_block);
Elsif *ms_chain_elsif_list(Elsif *list, Elsif *add);
Elsif *ms_create_elsif(Expression *expr, Block *block);
Statement *ms_create_while_statement(Expression *condition, Block *block);
Statement *ms_create_for_statement(Expression *init, Expression *cond, Expression *post, Block *block);
Block *ms_create_block(StatementList *statement_list);
Statement *ms_create_expression_statement(Expression *expression);
Statement *ms_create_return_statement(Expression *expression);
Statement *ms_create_break_statement(void);
Statement *ms_create_continue_statement(void);

// string.c
void ms_open_string_literal();
void ms_add_string_literal(int letter);
void ms_reset_string_literal_buffer();
char *ms_close_string_literal();

// tree.c
void ms_traverse(MS_Interpreter *interpreter, int blank);
void ms_traverse_variable(Variable *variable, int blank);
void ms_traverse_function(FunctionDefinition *func, int blank);
void ms_traverse_statement_list(StatementList *stmtList, int blank);
void ms_traverse_parameter_list(ParameterList *paraList, int blank);
void ms_traverse_argument_list(ArgumentList *agmtList, int blank);
void ms_traverse_expression(Expression *expression, int blank);
void ms_traverse_statement(Statement *statement, int blank);
void ms_traverse_block(Block *block, int blank);
void ms_traverse_elsif(Elsif *elsif, int blank);
void ms_traverse_identifier_list(IdentifierList *idList, int blank);
void ms_traverse_assign_expression(AssignExpression asnExp, int blank);
void ms_traverse_binary_expression(BinaryExpression binExp, int blank);
void ms_traverse_function_call_expression(FunctionCallExpression funcCall, int blank);
void ms_traverse_if_statement(IfStatement ifStmt, int blank);
void ms_traverse_while_statement(WhileStatement whileStmt, int blank);
void ms_traverse_for_statement(ForStatement forStmt, int blank);
void ms_traverse_return_statement(ReturnStatement returnStmt, int blank);
void ms_traverse_array_use_expression(ArrayUseExpression arrUse, int blank);
void ms_traverse_class_new_expression(ClassNewExpression cnExp, int blank);
void ms_traverse_class_use_expression(ClassUseExpression cuExp, int blank);
void create_blank(int blank);

#endif /* PRIVATE_CROWBAR_H_INCLUDED */
