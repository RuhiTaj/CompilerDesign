%{

%}


letter[a-zA-Z]  
digit[0-9]
symbol[_]

%%  

{digit}+({symbol}|{letter}|{digit})+ printf("\n%s\tis not an identifier\n",yytext);
{digit}+("E"("+"|"-")?{digit}+)? printf("\n%s\tis real number\n",yytext);  
{digit}+"."{digit}+("E"("+"|"-")?{digit}+)? printf("\n%s\t is floating pt no\n",yytext);  
"if"|"else"|"int"|"char"|"scanf"|"printf"|"switch"|"return"|"struct"|"do"|"while"|"void"|"for"|"float" printf("\n%s\t is keywords\n",yytext);  
"\a"|"\\n"|"\\b"|"\t"|"\\t"|"\b"|"\\a" printf("\n%s\tis Escape sequences\n",yytext);  
({letter}|{symbol})({letter}|{digit})* printf("\n%s\tis identifier\n",yytext);  
"&&"|"<"|">"|"<="|">="|"="|"+"|"-"|"?"|"*"|"/"|"%"|"&"|"||" printf("\n%s\toperator",yytext);  
"{"|"}"|"["|"]"|"("|")"|"#"|"'"|"."|"\""|"\\"|";"|"," printf("\n%s\t is a special character\n",yytext);  
"%d"|"%s"|"%c"|"%f"|"%e" printf("\n%s\tis a format specifier\n",yytext);  
%%
  
int yywrap()  
 {  
 return 1;  
 }
int main()  
{  
yyin=fopen("cdTestCase2.c","r"); 
yylex();  
fclose(yyin);  
return 0; 
}
