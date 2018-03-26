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
    int_const = 258,
    char_const = 259,
    float_const = 260,
    int_id = 261,
    float_id = 262,
    char_id = 263,
    id = 264,
    string = 265,
    enumeration_const = 266,
    storage_const = 267,
    type_const = 268,
    qual_const = 269,
    struct_const = 270,
    enum_const = 271,
    DEFINE = 272,
    IF = 273,
    FOR = 274,
    DO = 275,
    WHILE = 276,
    BREAK = 277,
    SWITCH = 278,
    CONTINUE = 279,
    RETURN = 280,
    CASE = 281,
    DEFAULT = 282,
    GOTO = 283,
    SIZEOF = 284,
    PUNC = 285,
    or_const = 286,
    and_const = 287,
    eq_const = 288,
    shift_const = 289,
    rel_const = 290,
    inc_const = 291,
    point_const = 292,
    param_const = 293,
    ELSE = 294,
    HEADER = 295
  };
#endif
/* Tokens.  */
#define int_const 258
#define char_const 259
#define float_const 260
#define int_id 261
#define float_id 262
#define char_id 263
#define id 264
#define string 265
#define enumeration_const 266
#define storage_const 267
#define type_const 268
#define qual_const 269
#define struct_const 270
#define enum_const 271
#define DEFINE 272
#define IF 273
#define FOR 274
#define DO 275
#define WHILE 276
#define BREAK 277
#define SWITCH 278
#define CONTINUE 279
#define RETURN 280
#define CASE 281
#define DEFAULT 282
#define GOTO 283
#define SIZEOF 284
#define PUNC 285
#define or_const 286
#define and_const 287
#define eq_const 288
#define shift_const 289
#define rel_const 290
#define inc_const 291
#define point_const 292
#define param_const 293
#define ELSE 294
#define HEADER 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
