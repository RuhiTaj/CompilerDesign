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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    ID = 261,
    NUM = 262,
    REAL = 263,
    LE = 264,
    GE = 265,
    EQ = 266,
    NEQ = 267,
    AND = 268,
    OR = 269,
    WHILE = 270,
    IF = 271,
    RETURN = 272,
    PREPROC = 273,
    STRING = 274,
    PRINT = 275,
    FUNCTION = 276,
    DO = 277,
    ARRAY = 278,
    ELSE = 279,
    STRUCT = 280,
    STRUCT_VAR = 281,
    FOR = 282,
    UMINUS = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define LE 264
#define GE 265
#define EQ 266
#define NEQ 267
#define AND 268
#define OR 269
#define WHILE 270
#define IF 271
#define RETURN 272
#define PREPROC 273
#define STRING 274
#define PRINT 275
#define FUNCTION 276
#define DO 277
#define ARRAY 278
#define ELSE 279
#define STRUCT 280
#define STRUCT_VAR 281
#define FOR 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 170 "s_parser.y" /* yacc.c:1909  */

		int ival;
		char *str;
	

#line 116 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
