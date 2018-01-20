%{
	int valid=0;
%}

DIGIT    [0-9]

%%
^{DIGIT}*	{ECHO;printf(" is not a digit");} {valid=1;}
[-,+]?{DIGIT}*        {ECHO;printf(" is a Integer");} {valid=1;}
[-/+]?{DIGIT}*?\.{DIGIT}*    {ECHO;printf(" is a Floating point number ");} {valid=1;}
%%

int main()
{	
	yyin=fopen("identify.txt","r");
    yylex();
    return 0;
}

int yywrap()
{
return (1);
}
