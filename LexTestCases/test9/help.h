


char* everything[11][50];
int i,count[10] = {0};


void namethe(int no){

switch(no){

case 1: printf("\n|\n|  Real_Number        ");
		break;
case 2: printf("\n|\n|  String_Literal     ");
		break;
case 3: printf("\n|\n|  Separator          ");
		break;
case 4:	printf("\n|\n|  HeaderFile         ");
		break;
case 5: printf("\n|\n|  printf 	       ");
		break;
case 6: printf("\n|\n|  Key_Word 	      ");
		break;
case 7: printf("\n|\n|  Identifier 	      ");
		break;
case 8: printf("\n|\n|  Operator 	      ");
		break;
case 9: printf("\n|\n|  Format_Specifier   ");
		break;
case 10:printf("\n|\n|  Constants          ");
		break;
case 11:printf("\n|\n|  Comment_Lines      "); 
		break;

default: break;
}

}

void the_medium_to_display(char* word, int no){

if(no==1){

the_medium_to_display(word,10);

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
   	fp = fopen ("/home/ubuntu/Desktop/correctTestCase/test3/output.txt","w");

		for(h=0;h<20;h++){
	printf("___");	
	}


	for(m=1;m<11;m++){
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
