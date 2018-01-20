%{
 # include <stdio.h>
 # include <stdlib.h>
%}


letter[a-zA-Z]  
digit[0-9]
symbol[_]
qoute["]
openBracket[(]
comma[,]
closeBracket[)]
end[;]
perc[%]
dotted[:]
space[ ]
nextLine [\n]


%%  


"printf"{openBracket}{qoute}({space}|{letter}|{digit}|{perc}|{dotted}|\\)*{qoute}({space}*{comma}{space}*({digit}*|{letter}*){space}*)?{closeBracket}{end}  {printf("\n%s  is a proper print statement:  \n",yytext);}
 
%%
  
int yywrap()  
 {  
 return 1;  
 }
int main()  
{  
yyin=fopen("cdTestCase5.c","r"); 
yylex();  
fclose(yyin);  
return 0; 
}
