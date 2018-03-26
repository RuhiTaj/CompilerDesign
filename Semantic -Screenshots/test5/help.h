
char* everything[45][50];
int i,count[45] = {0};
char* dataType[50][20];
int lineNo[500];
int set=0;
float scope= 0.0 ;
int whoIsInSet[500] = {0};
int assign[500];
float IdScope[500] = {-1};
int lineNoOfId[600];
int Dim[700] = {-1};
int dimk[500];
int dimGlobe=-1;


char littleScope[500];
int scopeTrack = -1;

float sendToInc(float n){

return round(n)+1.000000;

}

void letsPush(){


scopeTrack = scopeTrack + 1;
littleScope[scopeTrack] = "{";


if(scopeTrack==0){


scope = sendToInc(scope);

}

scope = scope + 0.01;

}

void letsPop(){


scopeTrack = scopeTrack -1; 
scope = scope - 0.01;

}

int checkC(float a, float b){

if((round(a)== round(b)) && ( a >= b)){
return 1;
}

return -1;

}
/*

1. int
2. float
3. char
4. double
5. void
6. struct
7. union
8. int*
9. char*
10. float*
11. double*
12. struct*
13. int[]
14. float[]
15. char[]
16. double[]


void setLineNo(int line, char *word){

if(word == "int"){

lineNo[0]= line;

}
else if(word == "float"){

lineNo[1]= line;

}
else if(word == "char"){

lineNo[2]= line;

}
else if(word == "double"){

lineNo[3]= line;

}
else if(word == "void"){

lineNo[4]= line;

}

else if(word == "struct"){

lineNo[5] = line;

}

}

*/


void namethe(int no){

switch(no){

case 1: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Header_File            ");
		break;
case 2: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Define                 ");
		break;
case 3: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Storage_Constant       ");
		break;
case 4:	printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Type_Constant          ");
		break;
case 5: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Qual_Constant          ");
		break;
case 6: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Enum_Constant          ");
		break;
case 7: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Case                   ");
		break;
case 8: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Default                ");
		break;
case 9: printf("\n|\t\t\t    |\n|\t\t\t    |\n|  If                     ");
		break;
case 10:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Switch                 ");
		break;
case 11:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Else                   "); 
		break;
case 12:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  For                    "); 
		break;
case 13:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Do                     "); 
		break;
case 14:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  While                  "); 
		break;

case 15:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Goto                   "); 
		break;

case 16:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Continue               "); 
		break;

case 17:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Break                  "); 
		break;

case 18:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Struct_Constant        "); 
		break;

case 19:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Return                 "); 
		break;

case 20:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Size_Of                "); 
		break;

case 21:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Or_Const               "); 
		break;
case 22:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  And_Const              "); 
		break;
case 23:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Param_Const            "); 
		break;
case 24:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Equi_Const             "); 
		break;
case 25:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Rel_Const              "); 
		break;
case 26:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Shift_Const            "); 
		break;
case 27:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Inc_Const              "); 
		break;
case 28:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Point_Const            "); 
		break;

case 29:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Just_Symbol            "); 
		break;

case 30:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Punc                   "); 
		break;
case 31:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  int_Const              "); 
		break;
case 32:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  float_Const            "); 
		break;
case 33:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Char_Const             "); 
		break;
case 34:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  id                     "); 
		break;
case 35:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  string                 "); 
		break;
case 36:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Main_Function          "); 
		break;
case 37:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Array                  "); 
		break;
case 38:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Library_Function       "); 
		break;
case 39:printf("\n|\t\t\t    |\n|\t\t\t    |\n|  Incorrect Array        "); 
		break;
default: break;
}

}

void thename(int no){


printf("\n|\t\t\t    |\n|\t\t\t    |\n|  ");
int k  = strlen (everything[34][no]);
printf("%s",everything[34][no]);
for(i=0;i<25-k;i++){
printf(" ");}

}

void theScope(int n){



}


void the_medium_to_display(char* word, int no, int lineAtCode){



 int y = strlen(word);
 
everything[no][count[no]] = (char*)malloc(y*sizeof(char));

int track = -1;

if(no == 39){

printf("Semantic Error\n");
printf("Illegal array- %s at line no - %d\n\n",word, lineAtCode);


}

if(no == 37){
the_medium_to_display( word, 34, lineAtCode);
track = 1;
}

int i,stop=0;

for(i=0;i<count[no];i++){

if( strcmp(everything[no][i], word) ==0 ){

if( no !=34){
stop=1;
break;
i=count[no];
}
else 

{
if(checkC(scope, IdScope[i])==1){

stop=1;
break;
i=count[no];


}

}

}

}



if(stop==0){

int g;

 	for(g=0;g<y;g++){
	
	everything[no][count[no]][g] = word[g];
	}

if (no == 34){


lineNo[count[no]] = set;
if(whoIsInSet[set] == 0){

printf("\n\nSemantic Error found at line No - %d!\n",lineAtCode);
printf("%s is not defined\n\n",word);

}

IdScope[count[no]] = scope;

if(count[no]!=0){

/*
if(IdScope[count[no]-1] > scope ){

scope = scope+1.0;
IdScope[count[no]] = scope;

}
*/

}

}

if(track == 1){

printf("\n\n\n\n");

int countIt = 0;
dimGlobe = dimGlobe+1;



for(int h=0;h<strlen(word);h++){

if(word[h] == '[' ){
printf("Hey");
countIt = countIt+1;

}

}

dimk[dimGlobe] = countIt;
printf("%d---%d\n",dimGlobe, dimk[dimGlobe]);

}

 count[no] = count[no]+1;
 //namethe(no);


 //printf(":\t%s\n", everything[no][count[no]-1]);
}

if(strcmp(word , "int") == 0){

whoIsInSet[set] = 1;

}
else if(strcmp(word , "float") == 0){

whoIsInSet[set] = 2;

}
else if(strcmp(word , "char") == 0){

whoIsInSet[set] = 3;

}
else if(strcmp(word , "double") == 0){

whoIsInSet[set] = 4;

}
else if(strcmp(word , "void") == 0){

whoIsInSet[set] = 5;

}
else if(strcmp(word , "struct") == 0){

whoIsInSet[set] = 6;

}
else if(strcmp(word , "union") == 0){

whoIsInSet[set] = 7;

}
else if(strcmp(word , "*") == 0){

 if(whoIsInSet[set] == 1){
	whoIsInSet[set] = 8;
 }
 else if(whoIsInSet[set] == 2){
	whoIsInSet[set] = 9;
}
  else if(whoIsInSet[set] == 3){
	whoIsInSet[set] = 10;
}
  else if(whoIsInSet[set] == 4){
	whoIsInSet[set] = 11;
}
  else if(whoIsInSet[set] == 6){
	whoIsInSet[set] = 12;
}

} 	

if(track == 1){

  if(whoIsInSet[set] == 1){
	whoIsInSet[set] = 13;
 }
 else if(whoIsInSet[set] == 2){
	whoIsInSet[set] = 14;
}
  else if(whoIsInSet[set] == 3){
	whoIsInSet[set] = 15;
}
  else if(whoIsInSet[set] == 4){
	whoIsInSet[set] = 16;
}


}


}

int DataType(int no){

switch(no){

case 1 : printf("integer"); return strlen("integer");
	break;
case 2 : printf("float"); return strlen("float");
	break;
case 3 : printf("character"); return strlen("character");
	break;
case 4 : printf("double"); return strlen("double");
	break;
case 5 : printf("void"); return strlen("void");
	break;
case 6 : printf("struct"); return strlen("struct");
	break;
case 7 : printf("union"); return strlen("union");
	break;
case 8 : printf("integer_pointer"); return strlen("integer_pointer");
	break;
case 9 : printf("float_pointer"); return strlen("float_pointer");
	break;
case 10 : printf("char_pointer"); return strlen("char_pointer");
	break;
case 11 : printf("double_pointer"); return strlen("double_pointer");
	break;
case 12 : printf("struct_pointer"); return strlen("struct_pointer");
	break;
case 13 : printf("integer_array"); return strlen("integer_array");
	break;
case 14 : printf("float_array"); return strlen("float_array");
	break;
case 15 : printf("char_array"); return strlen("char_array");
	break;
case 16 : printf("double_array"); return strlen("double_array");
	break;
default : printf("UNDEFINED_DATA_TYPE"); return strlen("UNDEFINED_DATA_TYPE");
	break;

}

}



void theTable(){

	int m,n;
 	FILE * fp;
	int h;
	

   /* open the file for writing*/
   	//fp = fopen ("/home/ubuntu/Desktop/correctTestCase/test3/output.txt","w");

   	printf("\n\n\n------------------------ Symbol Table -----------------------\n\n\n\n");


		for(h=0;h<20;h++){
	printf("___");	
	}


	for(m=1;m<39;m++){

	if(count[m]>0 && (m<30 || m>35) ){
	
			
	namethe(m);
	for(n=0;n<count[m];n++)
		{
		int p = strlen(everything[m][n]);
		if(n==0 && n==count[m]-1){
		printf("  | %s\n|\t\t\t    |\n|\t\t\t    |\n|\t\t\t    |\n",everything[m][n]);
		
		}
		else if(n==0)
		{printf("  | %s\n",everything[m][n]);}
		else if(n== count[m]-1)
		{printf("|\t\t\t    | %s\n|\t\t\t    |\n|\t\t\t    |\n|\t\t\t    |\n|",everything[m][n]);
		}
		else{
		printf("|\t\t\t    | %s\n",everything[m][n]);	
		}

		}
	if(count[m]==1){
	printf("|");
	}
	for(h=0;h<60;h++){
	if (h==27){
		printf("|");}
	else{
	printf("_");
	}	
	}

	}


	}

printf("\n\n\n\n\n\n");

printf("----------------------- Constant Table -----------------------\n\n\n\n");



		for(h=0;h<20;h++){
	printf("___");	
	}



		for(m=30;m<36;m++){

	if(count[m]>0){
	
			
	namethe(m);
	for(n=0;n<count[m];n++)
		{
		int p = strlen(everything[m][n]);
		if(n==0 && n==count[m]-1){
		printf("  | %s\n|\t\t\t    |\n|\t\t\t    |\n|\t\t\t    |\n",everything[m][n]);
		
		}
		else if(n==0)
		{printf("  | %s\n",everything[m][n]);}
		else if(n== count[m]-1)
		{printf("|\t\t\t    | %s\n|\t\t\t    |\n|\t\t\t    |\n|\t\t\t    |\n|",everything[m][n]);
		}
		else{
		printf("|\t\t\t    | %s\n",everything[m][n]);	
		}

		}
	if(count[m]==1){
	printf("|");
	}
	for(h=0;h<60;h++){
	if (h==27){
		printf("|");}
	else{
	printf("_");
	}	
	}

	}


	}

printf("\n\n\n\n");





printf("----------------------------- ID  ----------------------------\n\n\n\n");

		for(h=0;h<77;h++){
	printf("_");	
	}


m = 34;

int dimTrack = 0;

printf("\n|\t\t\t    |\t\t\t    |\t\t\t    |\n|        VALUE              |         SCOPE         |       DATA TYPE       |");
printf("\n|\t\t\t    |\t\t\t    |\t\t\t    |\n");
printf("|");
		
		
		for(h=0;h<76;h++){
			if(h==27 || h==51 || h==75)
			{printf("|");}
			else{
				printf("_");}	
	}
for(n=0;n<count[m];n++){

	if(count[m]>0){
	
	
printf("\n|\t\t\t    |\t\t\t    |\t\t\t    |\n|");
int slen = strlen(everything[m][n]);
printf("%s",everything[m][n]);

int j;
for(j=0;j<27-slen;j++){
printf(" ");
}

printf("|");

char buf[5];
gcvt (IdScope[n], 4,buf);
slen = strlen(buf);
printf("%s",buf);

for(j=0;j<23-slen;j++){
printf(" ");
}
printf("|");

/*
if(Dim[n]!=-1){
printf("%dD-",Dim[n]);
}
slen = 3;

*/

slen =0;

if( whoIsInSet[lineNo[n]] >= 13 && whoIsInSet[lineNo[n]] <= 16){

printf("%dD-",dimk[dimTrack]);
dimTrack = dimTrack +1;
slen =  3;

}

slen = slen + DataType(whoIsInSet[lineNo[n]]);



for(j=0;j<23-slen;j++){
printf(" ");
}
printf("|");


printf("\n|\t\t\t    |\t\t\t    |\t\t\t    |\n");
printf("|");
		

		for(h=0;h<76;h++){
			if(h==27 || h==51 || h==75)
			{printf("|");}
			else{
				printf("_");}	
	}
	

	}


	}


printf("\n\n\n\n");




}

// 1 Real Numbers
//2 String Literal
// 3 Separator
//4 Header Files
// 5 printf
// 6 keyWord
// 7 identifier
// 8 operator
// 9 format specifier
//     struct node{

//     	char* text;
//     	int type;
//     	struct node* link;
//     	struct node* down;

//     };


//     struct node* root = (struct node*) malloc(sizeof(struct node));
//     root->link = NULL;
//     root->down = NULL;


// void the_medium_to_display(char* the_text, int category, struct node* head){

// 	struct node* temp = (struct node*) malloc(sizeof(struct node));
	
// 	temp->text = the_text;
// 	temp->type = category;
// 	temp->link=NULL;
// 	temp->down=NULL;

// if(head->down == NULL){


// 	head->down = temp;

// }

// else{

// 	struct node* tmp;
// 	tmp = head;
// 	int note=0;

// 	while(tmp->down!=NULL){

// 		tmp = tmp->down;

// 		if(tmp->type==category){
// 			note=1;

// 			struct node* tempr;
// 			tempr = tmp;

// 			while(tempr->link!=NULL){
// 				tempr= tempr->link;
// 			}

// 			tempr->link = temp;

// 		}

// 	}

// 	if(note==0){
// 		tmp->down = temp;
// 	}

// }

// printf("%d : %s\n", category, the_text);


// }
