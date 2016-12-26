/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MORRISCRIPT_TAB_H_INCLUDED
# define YY_YY_MORRISCRIPT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_LITERAL = 258,
    DOUBLE_LITERAL = 259,
    STRING_LITERAL = 260,
    IDENTIFIER = 261,
    GLOBAL_T = 262,
    LET = 263,
    FUNCTION = 264,
    CLASS = 265,
    RETURN_T = 266,
    IF = 267,
    ELSE = 268,
    ELSIF = 269,
    TRUE_T = 270,
    FALSE_T = 271,
    NULL_T = 272,
    FOR = 273,
    WHILE = 274,
    BREAK = 275,
    CONTINUE = 276,
    LP = 277,
    RP = 278,
    LB = 279,
    RB = 280,
    LC = 281,
    RC = 282,
    SEMICOLON = 283,
    COMMA = 284,
    CLOSURE = 285,
    DOT = 286,
    LOGICAL_AND = 287,
    LOGICAL_OR = 288,
    ASSIGN = 289,
    EQ = 290,
    NE = 291,
    GT = 292,
    GE = 293,
    LT = 294,
    LE = 295,
    ADD = 296,
    SUB = 297,
    MUL = 298,
    DIV = 299,
    MOD = 300,
    NEW = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "morriscript.y" /* yacc.c:1909  */

    char                *identifier;
    ParameterList       *parameter_list;
    ArgumentList        *argument_list;
    Expression          *expression;
    Statement           *statement;
    StatementList       *statement_list;
    Block               *block;
    Elsif               *elsif;
    IdentifierList      *identifier_list;

#line 113 "morriscript.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MORRISCRIPT_TAB_H_INCLUDED  */
