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
/* Tokens.  */
#define INT_LITERAL 258
#define DOUBLE_LITERAL 259
#define STRING_LITERAL 260
#define IDENTIFIER 261
#define GLOBAL_T 262
#define LET 263
#define FUNCTION 264
#define CLASS 265
#define RETURN_T 266
#define IF 267
#define ELSE 268
#define ELSIF 269
#define TRUE_T 270
#define FALSE_T 271
#define NULL_T 272
#define FOR 273
#define WHILE 274
#define BREAK 275
#define CONTINUE 276
#define LP 277
#define RP 278
#define LB 279
#define RB 280
#define LC 281
#define RC 282
#define SEMICOLON 283
#define COMMA 284
#define CLOSURE 285
#define DOT 286
#define LOGICAL_AND 287
#define LOGICAL_OR 288
#define ASSIGN 289
#define EQ 290
#define NE 291
#define GT 292
#define GE 293
#define LT 294
#define LE 295
#define ADD 296
#define SUB 297
#define MUL 298
#define DIV 299
#define MOD 300
#define NEW 301




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
#line 153 "morriscript.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

