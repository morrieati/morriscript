#include "morriscript.h"
#include "lex.yy.c"

extern char *yytext;

int main(int argc, char *argv[])
{
    MS_Interpreter *interpreter;
    interpreter = ms_create_interpreter();

    if (argc <= 1)
    {
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);

    if (yyparse() == 0 && yylexIsOk == 1)
    {
        ms_traverse(interpreter, 0);
    }

    return 0;
}

void yyerror(char *msg, int state)
{
    fprintf(stderr, "Error type B at Line %d, ", ms_get_interpreter()->current_line_number);
    // fprintf(stderr, "%s expected ", yyerrmtx[state]);
    fprintf(stderr, "missing character before \" %s \" \n", yytext);
}