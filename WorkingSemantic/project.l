%option yylineno

%{
	#include<stdio.h>
	# include <math.h>
	#include"y.tab.h"
	#include<math.h>
	#include "help.h"
	
%}

space[ ]
openBraces[(]
closeBraces[)]
openD[[]
closeD[]]

%%

("int"|"void")?{space}*main{space}*{openBraces}({space}?|"void"|""){closeBraces} {the_medium_to_display(yytext,36, yylineno); return id; }

"#include"([ ]+)?((<(\\.|[^>])+>)|(\"(\\.|[^"])+\"))  { the_medium_to_display(yytext, 1, yylineno);return HEADER;}

"#define"[ ]+[a-zA-z_][a-zA-z_0-9]* {the_medium_to_display(yytext, 2, yylineno); return DEFINE; }

"auto"|"register"|"static"|"extern"|"typedef"		{ the_medium_to_display(yytext, 3, yylineno); return storage_const;}

"short"|"long"|"signed"|"unsigned"		{ the_medium_to_display(yytext, 4, yylineno); return type_const;}	

"void"|"char"|"int"|"float"|"double" { int noT = the_medium_to_display(yytext, 4, yylineno); return type_const;}	

"const"|"volatile" { the_medium_to_display(yytext, 5, yylineno); return qual_const;}

"enum"		{the_medium_to_display(yytext, 6, yylineno); return enum_const; }

"case"		{ the_medium_to_display(yytext, 7, yylineno); return CASE;}	

"default"	{ the_medium_to_display(yytext, 8, yylineno); return DEFAULT;}

"if"	{ the_medium_to_display(yytext, 9, yylineno); return IF;}

"switch" {the_medium_to_display(yytext, 10, yylineno); return SWITCH; }

"else"	{ the_medium_to_display(yytext, 11, yylineno);return ELSE;}

"for"	{ the_medium_to_display(yytext, 12, yylineno); return FOR;}

"do" { the_medium_to_display(yytext, 13, yylineno); return DO;}

"while"	{ the_medium_to_display(yytext, 14, yylineno); return WHILE;}

"goto"		{ the_medium_to_display(yytext, 15, yylineno); return GOTO;}

"continue"	{the_medium_to_display(yytext, 16, yylineno); return CONTINUE; }

"break"		{ the_medium_to_display(yytext, 17, yylineno); return BREAK;}

"struct"|"union"	{ the_medium_to_display(yytext, 18, yylineno); return struct_const;}

"return"	{the_medium_to_display(yytext, 19, yylineno); return RETURN; }

"sizeof"	{ the_medium_to_display(yytext, 20, yylineno); return SIZEOF;}

"||"  {the_medium_to_display(yytext, 21, yylineno); return or_const; }

"&&"	{the_medium_to_display(yytext, 22, yylineno); return and_const; }

"..."	{ the_medium_to_display(yytext, 23, yylineno); return param_const;}

"=="|"!="	{ the_medium_to_display(yytext, 24, yylineno); return eq_const;}

"<="|">="	{the_medium_to_display(yytext, 25, yylineno); return rel_const; }

">>"|"<<"	{ the_medium_to_display(yytext, 26, yylineno); return shift_const;}

"++"|"--"	{ the_medium_to_display(yytext, 27, yylineno); return inc_const;}

"->"		{the_medium_to_display(yytext, 28, yylineno); return point_const; }

";" { the_medium_to_display(yytext, 29, yylineno);set = set + 1; return yytext[0];}

"="|","|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">"	{ the_medium_to_display(yytext, 29, yylineno); return yytext[0];}

"{" { letsPush(); the_medium_to_display(yytext, 29, yylineno); return yytext[0];}

"}" { letsPop(); the_medium_to_display(yytext, 29, yylineno); return yytext[0];}

"*="|"/="|"+="|"%="|">>="|"-="|"<<="|"&="|"^="|"|="	{the_medium_to_display(yytext, 30, yylineno); return PUNC; }

[0-9]+	{ the_medium_to_display(yytext, 31, yylineno); return int_const;}

[0-9]+"."[0-9]+	{the_medium_to_display(yytext, 32, yylineno); return float_const; }	

"'"."'"|"'"[a-zA-z_][a-zA-z_0-9]*"'"	{ the_medium_to_display(yytext, 33, yylineno);  return char_const ;}

[a-zA-z_][a-zA-z_0-9]*("["([1-9][0-9]+)|([a-zA-z_][a-zA-z_0-9]*)"]")+	{ int noT = the_medium_to_display(yytext, 37, yylineno); if(noT== 1){ return int_id; } else if(noT==2) {return float_id;} else if(noT==3){return char_id;} else {return id;} }

"printf"|"getchar" { the_medium_to_display(yytext, 38, yylineno); return id;}

[a-zA-z_][a-zA-z_0-9]*	{  int noT = the_medium_to_display(yytext, 34, yylineno); if(noT== 1){ return int_id; } else if(noT==2) {return float_id;} else if(noT==3){ return char_id;} else {return id;} }


\"(\\.|[^\"])*\"	{ the_medium_to_display(yytext, 35, yylineno);  return string;}

"//"(\\.|[^\n])*[\n]		;
[/][*]([^*]|[*]*[^*/])*[*]+[/]  ;
[ \t\n]				;

%%

int yywrap(void)
{
    return 1;
}



