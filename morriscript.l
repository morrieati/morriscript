%{
    #include <stdio.h>
    #include <string.h>
    #include "morriscript.h"
    #include "morriscript.tab.h"

    int yywrap(void) {
        return 1;
    }

    static void increment_line_number(void) {
        ms_get_interpreter()->current_line_number++;
    }

    int yylexIsOk = 1;
%}

%start LINE_COMMENT BLOCK_COMMENT STRING_LITERAL_STATE
%%
 /* 定义保留字 */
<INITIAL>"global" {
    return GLOBAL_T;
}
<INITIAL>"let" {
    return LET;
}
<INITIAL>"function" {
    return FUNCTION;
}
<INITIAL>"class" {
    return CLASS;
}
<INITIAL>"new" {
    return NEW;
}
<INITIAL>"return" {
    return RETURN_T;
}

<INITIAL>"if" {
    return IF;
}
<INITIAL>"else" {
    return ELSE;
}
<INITIAL>"elsif" {
    return ELSIF;
}

<INITIAL>"true" {
    return TRUE_T;
}
<INITIAL>"false" {
    return FALSE_T;
}
<INITIAL>"null" {
    return NULL_T;
}

<INITIAL>"for" {
    return FOR;
}
<INITIAL>"while" {
    return WHILE;
}
<INITIAL>"break" {
    return BREAK;
}
<INITIAL>"continue" {
    return CONTINUE;
}

 /* 定义符号 */
<INITIAL>"(" {
    return LP;
}
<INITIAL>")" {
    return RP;
}
<INITIAL>"[" {
    return LB;
}
<INITIAL>"]" {
    return RB;
}
<INITIAL>"{" {
    return LC;
}
<INITIAL>"}" {
    return RC;
}
<INITIAL>";" {
    return SEMICOLON;
}
<INITIAL>"," {
    return COMMA;
}
<INITIAL>"&&" {
    return LOGICAL_AND;
}
<INITIAL>"||" {
    return LOGICAL_OR;
}
<INITIAL>"=" {
    return ASSIGN;
}
<INITIAL>"==" {
    return EQ;
}
<INITIAL>"!=" {
    return NE;
}
<INITIAL>">" {
    return GT;
}
<INITIAL>">=" {
    return GE;
}
<INITIAL>"<" {
    return LT;
}
<INITIAL>"<=" {
    return LE;
}
<INITIAL>"+" {
    return ADD;
}
<INITIAL>"-" {
    return SUB;
}
<INITIAL>"*" {
    return MUL;
}
<INITIAL>"/" {
    return DIV;
}
<INITIAL>"%" {
    return MOD;
}
<INITIAL>"=>" {
    return CLOSURE;
}
<INITIAL>"." {
    return DOT;
}

 /* 定义标识符 */
<INITIAL>[A-Za-z_][A-Za-z_0-9]* {
    yylval.identifier = strdup(yytext);

    return IDENTIFIER;
}

 /* 定义数值 */
<INITIAL>([1-9][0-9]*)|"0" {
    Expression  *expression = ms_alloc_expression(INT_EXPRESSION);
    sscanf(yytext, "%d", &expression->u.int_value);
    yylval.expression = expression;

    return INT_LITERAL;
}
<INITIAL>([0-9]+\.[0-9]+) {
    Expression  *expression = ms_alloc_expression(DOUBLE_EXPRESSION);
    sscanf(yytext, "%lf", &expression->u.double_value);
    yylval.expression = expression;

    return DOUBLE_LITERAL;
}

 /* 处理空白字符 */
<INITIAL>[ \t] ;

 /* 处理换行 */
<INITIAL>\n {
    increment_line_number();
}

 /* 定义字符串的开始 */
<INITIAL>\" {
    ms_open_string_literal();
    BEGIN STRING_LITERAL_STATE;
}

 /* 定义注释的开始 */
<INITIAL>"//" {
    BEGIN LINE_COMMENT;
}
<INITIAL>"/*" {
    BEGIN BLOCK_COMMENT;
}

 /* 若不符合上述定义，则为非法字符，并显示错误信息 */
<INITIAL>. {
    printf("Error type A at Line %d, invalid character \'%s\'\n", ms_get_interpreter()->current_line_number, yytext);
    yylexIsOk = 0;
}

<LINE_COMMENT>\n {
    increment_line_number();
    BEGIN INITIAL;
}
<LINE_COMMENT>. ;

<BLOCK_COMMENT>\n {
    increment_line_number();
}
<BLOCK_COMMENT>"*/" {
    BEGIN INITIAL;
}
<BLOCK_COMMENT>. ;

<STRING_LITERAL_STATE>\" {
    Expression *expression = ms_alloc_expression(STRING_EXPRESSION);
    expression->u.string_value = ms_close_string_literal();
    yylval.expression = expression;

    BEGIN INITIAL;
    return STRING_LITERAL;
}
<STRING_LITERAL_STATE>\n {
    ms_add_string_literal('\n');
    increment_line_number();
}
<STRING_LITERAL_STATE>\\\" {
    ms_add_string_literal('"');
}
<STRING_LITERAL_STATE>\\n {
    ms_add_string_literal('\n');
}
<STRING_LITERAL_STATE>\\t {
    ms_add_string_literal('\t');
}
<STRING_LITERAL_STATE>\\\\ {
    ms_add_string_literal('\\');
}
<STRING_LITERAL_STATE>. {
    ms_add_string_literal(yytext[0]);
}
%%
