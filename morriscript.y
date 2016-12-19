%{
    #include "morriscript.h"
    #define YYDEBUG 1

    void yyerror(char *);
    int yylex();
%}

%union {
    char                *identifier;
    ParameterList       *parameter_list;
    ArgumentList        *argument_list;
    Expression          *expression;
    Statement           *statement;
    StatementList       *statement_list;
    Block               *block;
    Elsif               *elsif;
    IdentifierList      *identifier_list;
}

 /* 终结符 */
%token  <expression> INT_LITERAL
%token  <expression> DOUBLE_LITERAL
%token  <expression> STRING_LITERAL
%token  <identifier> IDENTIFIER
%token  GLOBAL_T LET FUNCTION RETURN_T IF ELSE ELSIF TRUE_T FALSE_T NULL_T
        FOR WHILE BREAK CONTINUE LP RP LB RB LC RC SEMICOLON COMMA ARROW
        LOGICAL_AND LOGICAL_OR ASSIGN EQ NE GT GE LT LE ADD SUB MUL DIV MOD
 /* 非终结符 */

%type   <parameter_list> parameter_list
%type   <argument_list> argument_list
%type   <expression> expression expression_opt
        logical_and_expression logical_or_expression
        equality_expression relational_expression
        additive_expression multiplicative_expression
        unary_expression primary_expression
%type   <statement> statement global_statement let_statement
        if_statement while_statement for_statement
        return_statement break_statement continue_statement
%type   <statement_list> statement_list
%type   <block> block
%type   <elsif> elsif elsif_list
%type   <identifier_list> identifier_list

%%
translation_unit
    : definition_or_statement
    | translation_unit definition_or_statement
    ;
definition_or_statement
    : function_definition
    | anonymous_definition
    | statement
    {
        MS_Interpreter *inter = ms_get_interpreter();
        inter->statement_list = ms_chain_statement_list(inter->statement_list, $1);
    }
    ;
function_definition
    : FUNCTION IDENTIFIER LP parameter_list RP block
    {
        ms_create_function($2, $4, $6);
    }
    | FUNCTION IDENTIFIER LP RP block
    {
        ms_create_function($2, NULL, $5);
    }
    ;
anonymous_definition
    : LP parameter_list RP ARROW block
    {
        ms_create_anonymous($2, $5);
    }
    | LP RP ARROW block
    {
        ms_create_anonymous(NULL, $4);
    }
    | error SEMICOLON
    {
        yyerrok;
    }
    ;
parameter_list
    : LET IDENTIFIER
    {
        $$ = ms_create_parameter($2);
    }
    | LET IDENTIFIER COMMA parameter_list
    {
        $$ = ms_chain_parameter($4, $2);
    }
    ;
argument_list
    : expression
    {
        $$ = ms_create_argument_list($1);
    }
    | argument_list COMMA expression
    {
        $$ = ms_chain_argument_list($1, $3);
    }
    ;
statement_list
    : statement
    {
        $$ = ms_create_statement_list($1);
    }
    | statement_list statement
    {
        $$ = ms_chain_statement_list($1, $2);
    }
    ;
expression
    : logical_or_expression
    | IDENTIFIER ASSIGN expression
    {
        $$ = ms_create_assign_expression($1, $3);
    }
    | error RP
    {
        yyerrok;
    }
    ;
logical_or_expression
    : logical_and_expression
    | logical_or_expression LOGICAL_OR logical_and_expression
    {
        $$ = ms_create_binary_expression(LOGICAL_OR_EXPRESSION, $1, $3);
    }
    ;
logical_and_expression
    : equality_expression
    | logical_and_expression LOGICAL_AND equality_expression
    {
        $$ = ms_create_binary_expression(LOGICAL_AND_EXPRESSION, $1, $3);
    }
    ;
equality_expression
    : relational_expression
    | equality_expression EQ relational_expression
    {
        $$ = ms_create_binary_expression(EQ_EXPRESSION, $1, $3);
    }
    | equality_expression NE relational_expression
    {
        $$ = ms_create_binary_expression(NE_EXPRESSION, $1, $3);
    }
    ;
relational_expression
    : additive_expression
    | relational_expression GT additive_expression
    {
        $$ = ms_create_binary_expression(GT_EXPRESSION, $1, $3);
    }
    | relational_expression GE additive_expression
    {
        $$ = ms_create_binary_expression(GE_EXPRESSION, $1, $3);
    }
    | relational_expression LT additive_expression
    {
        $$ = ms_create_binary_expression(LT_EXPRESSION, $1, $3);
    }
    | relational_expression LE additive_expression
    {
        $$ = ms_create_binary_expression(LE_EXPRESSION, $1, $3);
    }
    ;
additive_expression
    : multiplicative_expression
    | additive_expression ADD multiplicative_expression
    {
        $$ = ms_create_binary_expression(ADD_EXPRESSION, $1, $3);
    }
    | additive_expression SUB multiplicative_expression
    {
        $$ = ms_create_binary_expression(SUB_EXPRESSION, $1, $3);
    }
    ;
multiplicative_expression
    : unary_expression
    | multiplicative_expression MUL unary_expression
    {
        $$ = ms_create_binary_expression(MUL_EXPRESSION, $1, $3);
    }
    | multiplicative_expression DIV unary_expression
    {
        $$ = ms_create_binary_expression(DIV_EXPRESSION, $1, $3);
    }
    | multiplicative_expression MOD unary_expression
    {
        $$ = ms_create_binary_expression(MOD_EXPRESSION, $1, $3);
    }
    ;
unary_expression
    : primary_expression
    | SUB unary_expression
    {
        $$ = ms_create_minus_expression($2);
    }
    ;
primary_expression
    : IDENTIFIER LP argument_list RP
    {
        $$ = ms_create_function_call_expression($1, $3);
    }
    | IDENTIFIER LP RP
    {
        $$ = ms_create_function_call_expression($1, NULL);
    }
    | LP expression RP
    {
        $$ = $2;
    }
    | IDENTIFIER
    {
        $$ = ms_create_identifier_expression($1);
    }
    | INT_LITERAL
    | DOUBLE_LITERAL
    | STRING_LITERAL
    | TRUE_T
    {
        $$ = ms_create_boolean_expression(MS_TRUE);
    }
    | FALSE_T
    {
        $$ = ms_create_boolean_expression(MS_FALSE);
    }
    | NULL_T
    {
        $$ = ms_create_null_expression();
    }
    ;
statement
    : expression SEMICOLON
    {
        $$ = ms_create_expression_statement($1);
    }
    | global_statement
    | let_statement
    | if_statement
    | while_statement
    | for_statement
    | return_statement
    | break_statement
    | continue_statement
    ;
global_statement
    : GLOBAL_T identifier_list SEMICOLON
    {
        $$ = ms_create_global_statement($2);
    }
    ;
let_statement
    : LET identifier_list SEMICOLON
    {
        $$ = ms_create_let_statement($2);
    }
    ;
identifier_list
    : IDENTIFIER
    {
        $$ = ms_create_global_identifier($1, NULL);
    }
    | IDENTIFIER LB INT_LITERAL RB
    {
        $$ = ms_create_global_identifier($1, $3);
    }
    | identifier_list COMMA IDENTIFIER
    {
        $$ = ms_chain_identifier($1, $3);
    }
    ;
if_statement
    : IF LP expression RP block
    {
        $$ = ms_create_if_statement($3, $5, NULL, NULL);
    }
    | IF LP expression RP block ELSE block
    {
        $$ = ms_create_if_statement($3, $5, NULL, $7);
    }
    | IF LP expression RP block elsif_list
    {
        $$ = ms_create_if_statement($3, $5, $6, NULL);
    }
    | IF LP expression RP block elsif_list ELSE block
    {
        $$ = ms_create_if_statement($3, $5, $6, $8);
    }
    ;
elsif_list
    : elsif
    | elsif_list elsif
    {
        $$ = ms_chain_elsif_list($1, $2);
    }
    ;
elsif
    : ELSIF LP expression RP block
    {
        $$ = ms_create_elsif($3, $5);
    }
    ;
while_statement
    : WHILE LP expression RP block
    {
        $$ = ms_create_while_statement($3, $5);
    }
    ;
for_statement
    : FOR LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP block
    {
        $$ = ms_create_for_statement($3, $5, $7, $9);
    }
    ;
expression_opt
    : /* empty */
    {
        $$ = NULL;
    }
    | expression
    ;
return_statement
    : RETURN_T expression_opt SEMICOLON
    {
        $$ = ms_create_return_statement($2);
    }
    ;
break_statement
    : BREAK SEMICOLON
    {
        $$ = ms_create_break_statement();
    }
    ;
continue_statement
    : CONTINUE SEMICOLON
    {
        $$ = ms_create_continue_statement();
    }
    ;
block
    : LC statement_list RC
    {
        $$ = ms_create_block($2);
    }
    | LC RC 
    {
        $$ = ms_create_block(NULL);
    }
    | error RC
    {
        yyerrok;
    }
    ;
%%
