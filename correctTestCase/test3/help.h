

char* everything[10][50];
int i,count[10] = {0};


void namethe(int no){

switch(no){

case 1: printf("\n\nReal_Number     ");
		break;
case 2: printf("\n\nString_Literal  ");
		break;
case 3: printf("\n\nSeparator       ");
		break;
case 4:	printf("\n\nHeaderFile      ");
		break;
case 5: printf("\n\nprintf 			");
		break;
case 6: printf("\n\nKey_Word 		");
		break;
case 7: printf("\n\nIdentifier 		");
		break;
case 8: printf("\n\nOperator 		");
		break;
case 9: printf("\n\nFormat_Specifier");
		break;
case 10:printf("\n\nComment_Lines 	"); 
		break;

default: break;
}

}

void the_medium_to_display(char* word, int no){

 everything[no][count[no]] = word;
 count[no] = count[no]+1;
 namethe(no);
 printf(":\t%s\n",  everything[no][count[no]-1]);


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
