%{
	#include<stdio.h>
	# include <string.h>
	# include <stdlib.h>
	
	extern int yylineno;
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	void check(int a, int b){
	if(a==3 || b == 3){
	printf("Semantic error at line no\t-\t%d\n",yylineno);
	printf("Cannot add character type variables\n\n");
}
	 else if(a!=b){
	printf("Semantic error at line no\t-\t%d\n",yylineno);
	printf("Cannot add different type variables\n\n");
	}
	}
	void checkAssign(int a, int b){
	
	if(a== b-10){}
	else{
	printf("Semantic error at line no- %d\n",yylineno);
	printf("Cannot assign different variables variables\n\n");
	}
	}
%}

%token int_const char_const float_const id int_id float_id char_id string enumeration_const storage_const type_const qual_const struct_const enum_const DEFINE
%token IF FOR DO WHILE BREAK SWITCH CONTINUE RETURN CASE DEFAULT GOTO SIZEOF PUNC or_const and_const eq_const shift_const rel_const inc_const
%token point_const param_const ELSE HEADER
%left '+' '-'
%left '*' '/'
%nonassoc "then"
%nonassoc ELSE
%define parse.error verbose
%start program_unit

%%

program_unit				: 	HEADER program_unit                               
							| DEFINE primary_exp program_unit                 	
							| translation_unit	 {$$ = $1; } 									
							;
translation_unit			: external_decl {$$ = $1; }									
							| translation_unit external_decl					
							;
external_decl				: function_definition
							| decl	{$$ = $1; }
							;
function_definition			: decl_specs declarator decl_list compound_stat 	
							| declarator decl_list compound_stat
							| decl_specs declarator	compound_stat 				
							| declarator compound_stat
							;
decl						: decl_specs init_declarator_list ';' 	{$$ = $1; }				
							| decl_specs ';'
							;
decl_list					: decl
							| decl_list decl
							;
decl_specs					: storage_class_spec decl_specs
							| storage_class_spec
							| type_spec decl_specs								
							| type_spec 										
							| type_qualifier decl_specs
							| type_qualifier
							;
storage_class_spec			: storage_const
							;
type_spec					: type_const										
							| struct_or_union_spec
							| enum_spec
							| typedef_name
							;
type_qualifier				: qual_const
							;
struct_or_union_spec		: struct_or_union id '{' struct_decl_list '}'
							| struct_or_union int_id '{' struct_decl_list '}'
							| struct_or_union float_id '{' struct_decl_list '}'
							| struct_or_union char_id '{' struct_decl_list '}'
							| struct_or_union '{' struct_decl_list '}'
							| struct_or_union id
							| struct_or_union int_id
							| struct_or_union float_id
							| struct_or_union char_id
							;
struct_or_union				: struct_const
							;
struct_decl_list			: struct_decl
							| struct_decl_list struct_decl
							;
init_declarator_list		: init_declarator	{$$ = $1; }
							| init_declarator_list ',' init_declarator
							;
init_declarator				: declarator	{$$ = $1; }
							| declarator '=' initializer {  checkAssign($1,$3);}
							;
struct_decl					: spec_qualifier_list struct_declarator_list ';'
							;
spec_qualifier_list			: type_spec spec_qualifier_list
							| type_spec
							| type_qualifier spec_qualifier_list
							| type_qualifier
							;
struct_declarator_list		: struct_declarator
							| struct_declarator_list ',' struct_declarator
							;
struct_declarator			: declarator	{$$ = $1; }
							| declarator ':' const_exp
							| ':' const_exp
							;
enum_spec					: enum_const id '{' enumerator_list '}'
							| enum_const int_id '{' enumerator_list '}'
							| enum_const float_id '{' enumerator_list '}'
							| enum_const char_id '{' enumerator_list '}'
							| enum_const '{' enumerator_list '}'
							| enum_const id
							| enum_const int_id
							| enum_const float_id
							| enum_const char_id
							;
enumerator_list				: enumerator
							| enumerator_list ',' enumerator
							;
enumerator					: id
							| int_id

							| float_id

							| char_id

							| id '=' const_exp	{  checkAssign($1,$3);}

							| int_id '=' const_exp	{  checkAssign($1,$3);}

							| float_id '=' const_exp	{  checkAssign($1,$3);}

							| char_id '=' const_exp	{ checkAssign($1,$3);}
							;
declarator					: pointer direct_declarator
							| direct_declarator {$$ = $1; }
							;
direct_declarator			: id 
							| int_id {$$ = 1; }

							| float_id {$$ = 2; }

							| char_id { $$ = 3; }
												
							| '(' declarator ')'									
							| direct_declarator '[' const_exp ']'							
							| direct_declarator '['	']'
							| direct_declarator '(' param_type_list ')' 			
							| direct_declarator '(' id_list ')' 					
							| direct_declarator '('	')' 							
							;
pointer						: '*' type_qualifier_list
							| '*'
							| '*' type_qualifier_list pointer
							| '*' pointer
							;
type_qualifier_list			: type_qualifier
							| type_qualifier_list type_qualifier
							;
param_type_list				: param_list
							| param_list ',' param_const
							;
param_list					: param_decl
							| param_list ',' param_decl
							;
param_decl					: decl_specs declarator
							| decl_specs abstract_declarator
							| decl_specs
							;
id_list						: id
							| int_id

							| float_id

							| char_id

							| id_list ',' id

							| id_list ',' int_id

							| id_list ',' float_id

							| id_list ',' char_id
							;
initializer					: assignment_exp
							| '{' initializer_list '}'
							| '{' initializer_list ',' '}'
							;
initializer_list			: initializer
							| initializer_list ',' initializer
							;
type_name					: spec_qualifier_list abstract_declarator
							| spec_qualifier_list
							;
abstract_declarator			: pointer
							| pointer direct_abstract_declarator
							|	direct_abstract_declarator
							;
direct_abstract_declarator	: '(' abstract_declarator ')'
							| direct_abstract_declarator '[' const_exp ']'
							| '[' const_exp ']'
							| direct_abstract_declarator '[' ']'
							| '[' ']'
							| direct_abstract_declarator '(' param_type_list ')'
							| '(' param_type_list ')'
							| direct_abstract_declarator '(' ')'
							| '(' ')'
							;
typedef_name				: 't'
							;
stat						: labeled_stat 									      	
							| exp_stat	{$$ = $1; } 											  	
							| compound_stat	{$$ = $1; } 									  	
							| selection_stat  									  
							| iteration_stat
							| jump_stat
							;
labeled_stat				: id ':' stat
							| int_id ':' stat
							| float_id ':' stat
							| char_id ':' stat
							| CASE const_exp ':' stat
							| DEFAULT ':' stat
							;
exp_stat					: exp ';'	{$$ = $1; }
							| ';'
							;
compound_stat				: '{' decl_list stat_list '}'   						
							| '{' stat_list '}' {$$ = $2; } 									
							| '{' decl_list	'}'										
							| '{' '}'												
							;
stat_list					: stat   {$$ = $1; } 												
							| stat_list stat  										
							;
selection_stat				: IF '(' exp ')' stat 									%prec "then"
							| IF '(' exp ')' stat ELSE stat
							| SWITCH '(' exp ')' stat
							;
iteration_stat				: WHILE '(' exp ')' stat
							| DO stat WHILE '(' exp ')' ';'
							| FOR '(' exp ';' exp ';' exp ')' stat
							| FOR '(' exp ';' exp ';'	')' stat
							| FOR '(' exp ';' ';' exp ')' stat
							| FOR '(' exp ';' ';' ')' stat
							| FOR '(' ';' exp ';' exp ')' stat
							| FOR '(' ';' exp ';' ')' stat
							| FOR '(' ';' ';' exp ')' stat
							| FOR '(' ';' ';' ')' stat
							;
jump_stat					: GOTO id ';'
							| GOTO int_id ';'
							| GOTO float_id ';'
							| GOTO char_id ';'
							| CONTINUE ';'
							| BREAK ';'
							| RETURN exp ';'
							| RETURN ';'
							;
exp							: assignment_exp	{$$ = $1; }
							| exp ',' assignment_exp
							;
assignment_exp				: conditional_exp	{$$ = $1; }
							| unary_exp assignment_operator assignment_exp	{  checkAssign($1,$3);}		
							;
assignment_operator			: PUNC
							| '='
							;
conditional_exp				: logical_or_exp	{$$ = $1; }
							| logical_or_exp '?' exp ':' conditional_exp
							;	
const_exp					: conditional_exp
							;
logical_or_exp				: logical_and_exp	{$$ = $1; }
							| logical_or_exp or_const logical_and_exp
							;
logical_and_exp				: inclusive_or_exp	{$$ = $1; }
							| logical_and_exp and_const inclusive_or_exp
							;
inclusive_or_exp			: exclusive_or_exp	{$$ = $1; }
							| inclusive_or_exp '|' exclusive_or_exp
							;
exclusive_or_exp			: and_exp	{$$ = $1; }
							| exclusive_or_exp '^' and_exp
							;
and_exp						: equality_exp	{$$ = $1; }
							| and_exp '&' equality_exp
							;
equality_exp				: relational_exp	{$$ = $1; }
							| equality_exp eq_const relational_exp
							;
relational_exp				: shift_expression	{$$ = $1; }
							| relational_exp '<' shift_expression
							| relational_exp '>' shift_expression
							| relational_exp rel_const shift_expression
							;
shift_expression			: additive_exp	{$$ = $1; }
							| shift_expression shift_const additive_exp
							;
additive_exp				: mult_exp	{$$ = $1; }
							| additive_exp '+' mult_exp {  check($1,$3);}
							| additive_exp '-' mult_exp { check($1,$3);}
							;
mult_exp					: cast_exp {$$ = $1; }
							| mult_exp '*' cast_exp
							| mult_exp '/' cast_exp
							| mult_exp '%' cast_exp
							;
cast_exp					: unary_exp {$$ = $1; }
							| '(' type_name ')' cast_exp
							;
unary_exp					: postfix_exp {$$ = $1; }
							| inc_const unary_exp
							| unary_operator cast_exp
							| SIZEOF unary_exp
							| SIZEOF '(' type_name ')'
							;
unary_operator				: '&' | '*' | '+' | '-' | '~' | '!' 				
							;
postfix_exp					: primary_exp 	{$$ = $1; }									
							| postfix_exp '[' exp ']'
							| postfix_exp '(' argument_exp_list ')'
							| postfix_exp '(' ')'
							| postfix_exp '.' id
							| postfix_exp '.' int_id
							| postfix_exp '.' float_id
							| postfix_exp '.' char_id
							| postfix_exp point_const id
							| postfix_exp point_const int_id
							| postfix_exp point_const float_id
							| postfix_exp point_const char_id
							| postfix_exp inc_const
							;
primary_exp					: id {$$ = $1; }
							| int_id { $$ = 1;}

							| float_id { $$ = 2;}

							| char_id { $$ = 3;} 													
							| consts {$$ = $1; } 												
							| string 												
							| '(' exp ')'
							;
argument_exp_list			: assignment_exp
							| argument_exp_list ',' assignment_exp
							;
consts						: int_const {$$ = 11;}										
							| char_const {$$ = 12;}
							| float_const {$$ = 13;}
							| enumeration_const
							;
%%

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("There is an error and failed to parse.\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	return 0;
}



int main()
{
    yyparse();
    if(success)
    	printf("\n\n\nParsing Successful\n");
theTable();
    return 0;
}



