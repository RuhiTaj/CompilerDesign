%{
#include<stdio.h>
%}

symbol[/]
sym[*]
space[ ]
character[a-z]
bigChar[A-Z]
digit[0-9]

%%
({symbol}{symbol})({space}|{bigChar}|{character}|{digit})* {printf("It is a Single Line Comment:  %s\n",yytext);}
({symbol}{sym})({character}|{space}|{bigChar}|{digit}|{symbol}|{sym})*({sym}{symbol}) {printf(" It is a MultiLine Comment:  %s\n",yytext);}

%%
int yywrap()  
 {  
 return 1;  
 }
int main()  
{  
yyin=fopen("cdTestCase3.c","r"); 
yylex();  
fclose(yyin);  
return 0; 
}
