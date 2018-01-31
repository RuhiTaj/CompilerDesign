%{
    # include <stdio.h>
    # include <stdlib.h>
    # include "help.h"

    int headFiles=0;
    int keyWords=0;
    int line=0;




%}

onlyDigits[0-9]
dot[.]
onlyAlphabets[a-zA-Z]
qoutes["]
space[ ]
underScore[_]
openArrow[<]
closeArrow[>]
headerNames[stdio]
openBraces[(]
closeBraces[)]
percentage[%]
comma[,]
colon[:]
end[;]
symbol[/]
other[\]
sym[*]
flowerOpen[{]
flowerClose[}]
subtract[-]
addi[+]

%%

{onlyDigits}+({underScore}|{onlyAlphabets})+ {printf("\n\nImproper Identifier: %s\n\n", yytext);}

({addi}|{subtract})?({onlyDigits}+|{onlyDigits}*{dot}{onlyDigits}+) { the_medium_to_display(yytext, 1); } 

{qoutes}({onlyDigits}|{onlyAlphabets}|{underScore})+{qoutes} {the_medium_to_display(yytext, 10);}

(0x{onlyDigits}*{onlyAlphabets}*|{onlyDigits}*{onlyAlphabets}*{subtract}({onlyAlphabets}|{onlyDigits})*|{onlyDigits}*{onlyAlphabets}*{dot}{onlyDigits}+{onlyAlphabets}) the_medium_to_display(yytext, 2);

({flowerClose}|{flowerOpen}|{end}|{comma}) {the_medium_to_display(yytext,3);}

"#"{space}*"include"{space}*{openArrow}{onlyAlphabets}+{dot}h{closeArrow} {the_medium_to_display(yytext, 4); }

"#"{space}*"include"{space}*({openArrow}|{onlyAlphabets}|{dot}|h|{closeArrow})* { printf("\nImproper Header File: %s\n", yytext);}

("int"|"void")?{space}*main{space}*{openBraces}({space}?|"void"|""){closeBraces} { printf("\nThis is the main function: %s\n", yytext); }

main {printf("Improper main, please correct it!\n");}


"printf"{openBraces}{qoutes}({space}|{onlyAlphabets}|{onlyDigits}|{percentage}|{colon}|\\)*{qoutes}({space}*{comma}{space}*({onlyDigits}*|{onlyAlphabets}*){space}*)?{closeBraces}{end}  {the_medium_to_display(yytext, 5);}

auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while {the_medium_to_display(yytext, 6);}

({onlyAlphabets}|{underScore})({onlyAlphabets}|{underScore}|{onlyDigits})* { the_medium_to_display(yytext, 7);}
 
"+"|"-"|"%"|"="|"!="|"!"|"<"|">"|"^"|"~" { the_medium_to_display(yytext, 8);}

"%s"|"%c"|"%d"|"%e"|"%E"|"%f"|"%g"|"%G"|"%hi"|"%hu"|"%i"|"%l"|"%ld"|"%lld"|"%lf"|"%lF"|"%lu"|"%lli"|"%o"|"%p"|"%s"|"%u"|"%x"|"%X"|"%n" { the_medium_to_display(yytext, 9);}

"//"({onlyAlphabets}|{onlyDigits}|{space}|{underScore}|{end})* {printf("It is a Single Line Comment.\n");}

"/*"("\n"|{space}|{onlyAlphabets}|{onlyDigits}|{underScore}|{end}|"/*")*"*/" {printf("It is a Multi Line Comment.\n");}

"printf"({onlyAlphabets}|{onlyDigits}|{openBraces}|{space}|{qoutes}|{percentage}|{colon}|{comma}|{closeBraces}|{end}|\\)* {printf("\n\nThis statement is a Lexical Error: %s\n\n",yytext);}

("*/") {printf("\n\nThis is a lexical error, with improper commenting\n\n");}

"/" {printf("\n\nIllegal stray found in the program - /\n\n");}

{qoutes}({onlyDigits}|{onlyAlphabets}|{underScore})* {printf("\n\nThis is a Lexical Error- Improper qoutes: %s\n\n", yytext);}


%%

int yywrap(){
    
    return 1;

}

void displayNames(int no){



}

int main(){
    
    yyin=fopen("testCase.c","r"); 
    yylex();
    int k=1;
    fclose(yyin);
    while(k<10)
    {displayNames(k);
     k=k+1;
    }
    
    printf("\n\n\n\n\nThe total no of real numbers: %d\n", count[1]);
    printf("\n\nThe total no of string literals: %d\n", count[2]);
    printf("\n\nThe total no of Separators: %d\n", count[3]);
    printf("\n\nThe total no of Header Files: %d\n", count[4]);
    printf("\n\nThe total no of printf: %d\n", count[5]);
    printf("\n\nThe total no of key words: %d\n", count[6]);
    printf("\n\nThe total no of identifiers: %d\n", count[7]);
    printf("\n\nThe total no of format specifiers: %d\n\n\n", count[8]);
  //  printf("\n\nTotal no of Lines in program is : %d\n\n\n\n", line);
	

theTable();

    return 0;

}

