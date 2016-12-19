/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LITERAL = 258,
     DOUBLE_LITERAL = 259,
     STRING_LITERAL = 260,
     IDENTIFIER = 261,
     GLOBAL_T = 262,
     LET = 263,
     FUNCTION = 264,
     RETURN_T = 265,
     IF = 266,
     ELSE = 267,
     ELSIF = 268,
     TRUE_T = 269,
     FALSE_T = 270,
     NULL_T = 271,
     FOR = 272,
     WHILE = 273,
     BREAK = 274,
     CONTINUE = 275,
     LP = 276,
     RP = 277,
     LB = 278,
     RB = 279,
     LC = 280,
     RC = 281,
     SEMICOLON = 282,
     COMMA = 283,
     ARROW = 284,
     LOGICAL_AND = 285,
     LOGICAL_OR = 286,
     ASSIGN = 287,
     EQ = 288,
     NE = 289,
     GT = 290,
     GE = 291,
     LT = 292,
     LE = 293,
     ADD = 294,
     SUB = 295,
     MUL = 296,
     DIV = 297,
     MOD = 298
   };
#endif
/* Tokens.  */
#define INT_LITERAL 258
#define DOUBLE_LITERAL 259
#define STRING_LITERAL 260
#define IDENTIFIER 261
#define GLOBAL_T 262
#define LET 263
#define FUNCTION 264
#define RETURN_T 265
#define IF 266
#define ELSE 267
#define ELSIF 268
#define TRUE_T 269
#define FALSE_T 270
#define NULL_T 271
#define FOR 272
#define WHILE 273
#define BREAK 274
#define CONTINUE 275
#define LP 276
#define RP 277
#define LB 278
#define RB 279
#define LC 280
#define RC 281
#define SEMICOLON 282
#define COMMA 283
#define ARROW 284
#define LOGICAL_AND 285
#define LOGICAL_OR 286
#define ASSIGN 287
#define EQ 288
#define NE 289
#define GT 290
#define GE 291
#define LT 292
#define LE 293
#define ADD 294
#define SUB 295
#define MUL 296
#define DIV 297
#define MOD 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "morriscript.y"
{
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
/* Line 1529 of yacc.c.  */
#line 147 "morriscript.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

