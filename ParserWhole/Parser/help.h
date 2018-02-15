
char* everything[36][50];
int i,count[36] = {0};


void namethe(int no){

switch(no){

case 1: printf("\n|\n|  Header_File        ");
		break;
case 2: printf("\n|\n|  Define     ");
		break;
case 3: printf("\n|\n|  Storage_Constant         ");
		break;
case 4:	printf("\n|\n|  Type_Constant         ");
		break;
case 5: printf("\n|\n|  Qual_Constant 	       ");
		break;
case 6: printf("\n|\n|  Enum_Constant 	      ");
		break;
case 7: printf("\n|\n|  Case 	      ");
		break;
case 8: printf("\n|\n|  Default 	      ");
		break;
case 9: printf("\n|\n|  If   ");
		break;
case 10:printf("\n|\n|  Switch          ");
		break;
case 11:printf("\n|\n|  Else      "); 
		break;
case 12:printf("\n|\n|  For      "); 
		break;
case 13:printf("\n|\n|  Do      "); 
		break;
case 14:printf("\n|\n|  While      "); 
		break;

case 15:printf("\n|\n|  Goto      "); 
		break;

case 16:printf("\n|\n|  Continue      "); 
		break;

case 17:printf("\n|\n|  Break      "); 
		break;

case 18:printf("\n|\n|  Struct_Constant      "); 
		break;

case 19:printf("\n|\n|  Return      "); 
		break;

case 20:printf("\n|\n|  Size_Of      "); 
		break;

case 21:printf("\n|\n|  Or_Const      "); 
		break;
case 22:printf("\n|\n|  And_Const      "); 
		break;
case 23:printf("\n|\n|  Param_Const      "); 
		break;
case 24:printf("\n|\n|  Equi_Const      "); 
		break;
case 25:printf("\n|\n|  Rel_Const      "); 
		break;
case 26:printf("\n|\n|  Shift_Const      "); 
		break;
case 27:printf("\n|\n|  Inc_Const      "); 
		break;
case 28:printf("\n|\n|  Point_Const      "); 
		break;

case 29:printf("\n|\n|  Just_Symbol      "); 
		break;

case 30:printf("\n|\n|  Punc      "); 
		break;
case 31:printf("\n|\n|  int_Const      "); 
		break;
case 32:printf("\n|\n|  float_Const      "); 
		break;
case 33:printf("\n|\n|  Char_Const      "); 
		break;
case 34:printf("\n|\n|  id      "); 
		break;
case 35:printf("\n|\n|  string      "); 
		break;

default: break;
}

}

void the_medium_to_display(char* word, int no){


if(no==1){

the_medium_to_display(word,35);

}

 int y = strlen(word);
 
everything[no][count[no]] = (char*)malloc(y*sizeof(char));
int g;

 	for(g=0;g<y;g++){
	
	everything[no][count[no]][g] = word[g];
	}

 count[no] = count[no]+1;
 //namethe(no);


 //printf(":\t%s\n", everything[no][count[no]-1]);


}



void theTable(){

	int m,n;
 	FILE * fp;
	int h;

   /* open the file for writing*/
   	//fp = fopen ("/home/ubuntu/Desktop/correctTestCase/test3/output.txt","w");

		for(h=0;h<20;h++){
	printf("___");	
	}


	for(m=1;m<36;m++){
;
	if(count[m]>0){
	
			
	namethe(m);
	for(n=0;n<count[m];n++)
		{
		int p = strlen(everything[m][n]);
		if(n==0 && n==count[m]-1){
		printf("  | %s\n",everything[m][n]);
		}
		else if(n==0)
		{printf("  | %s\n",everything[m][n]);}
		else if(n== count[m]-1)
		{printf("|\t\t\t| %s\n|",everything[m][n]);
		}
		else{
		printf("|\t\t\t| %s\n",everything[m][n]);	
		}

		}
	if(count[m]==1){
	printf("|");
	}
	for(h=0;h<20;h++){
	printf("___");	
	}

	}


	}

printf("\n\n\n");

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
