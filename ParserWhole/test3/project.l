%option yylineno

%{
	#include<stdio.h>
	#include"y.tab.h"
	#include<math.h>
	#include "help.h"

%}

space[ ]
openArrow[<]
onlyAlphabets[a-zA-Z]
closeArrow[>]
dot[.]

%%

"#include"([ ]+)?((<(\\.|[^>])+>)|(\"(\\.|[^"])+\"))  { the_medium_to_display(yytext, 1);return HEADER;}

"#define"[ ]+[a-zA-z_][a-zA-z_0-9]* {the_medium_to_display(yytext, 2); return DEFINE; }

"auto"|"register"|"static"|"extern"|"typedef"		{ the_medium_to_display(yytext, 3); return storage_const;}

"void"|"char"|"short"|"int"|"long"|"float"|"double"|"signed"|"unsigned"		{ the_medium_to_display(yytext, 4); return type_const;}	

"const"|"volatile" { the_medium_to_display(yytext, 5); return qual_const;}

"enum"		{the_medium_to_display(yytext, 6); return enum_const; }

"case"		{ the_medium_to_display(yytext, 7); return CASE;}	

"default"	{ the_medium_to_display(yytext, 8); return DEFAULT;}

"if"	{ the_medium_to_display(yytext, 9); return IF;}

"switch" {the_medium_to_display(yytext, 10); return SWITCH; }

"else"	{ the_medium_to_display(yytext, 11);return ELSE;}

"for"	{ the_medium_to_display(yytext, 12); return FOR;}

"do" { the_medium_to_display(yytext, 13); return DO;}

"while"	{ the_medium_to_display(yytext, 14); return WHILE;}

"goto"		{ the_medium_to_display(yytext, 15); return GOTO;}

"continue"	{the_medium_to_display(yytext, 16); return CONTINUE; }

"break"		{ the_medium_to_display(yytext, 17); return BREAK;}

"struct"|"union"	{ the_medium_to_display(yytext, 18); return struct_const;}

"return"	{the_medium_to_display(yytext, 19); return RETURN; }

"sizeof"	{ the_medium_to_display(yytext, 20); return SIZEOF;}

"||"  {the_medium_to_display(yytext, 21); return or_const; }

"&&"	{the_medium_to_display(yytext, 22); return and_const; }

"..."	{ the_medium_to_display(yytext, 23); return param_const;}

"=="|"!="	{ the_medium_to_display(yytext, 24); return eq_const;}

"<="|">="	{the_medium_to_display(yytext, 25); return rel_const; }

">>"|"<<"	{ the_medium_to_display(yytext, 26); return shift_const;}

"++"|"--"	{ the_medium_to_display(yytext, 27); return inc_const;}

"->"		{the_medium_to_display(yytext, 28); return point_const; }

";"|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">"	{ the_medium_to_display(yytext, 29); return yytext[0];}

"*="|"/="|"+="|"%="|">>="|"-="|"<<="|"&="|"^="|"|="	{the_medium_to_display(yytext, 30); return PUNC; }

[0-9]+	{ the_medium_to_display(yytext, 31); return int_const;}

[0-9]+"."[0-9]+	{the_medium_to_display(yytext, 32); return float_const; }	

"'"."'"|"'"[a-zA-z_][a-zA-z_0-9]*"'"	{ the_medium_to_display(yytext, 33); return char_const ;}

[a-zA-z_][a-zA-z_0-9]*	{ the_medium_to_display(yytext, 34); return id;}

\"(\\.|[^\"])*\"	{ the_medium_to_display(yytext, 35);  return string;}

"//"(\\.|[^\n])*[\n]		;
[/][*]([^*]|[*]*[^*/])*[*]+[/]  ;
[ \t\n]				;

%%

int yywrap(void)
{
    return 1;
}



