%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sym.h"

int divby0 = 0;
struct sym * head = NULL;
%}

%union {
    double dval;
    struct sym * symptr;
}

%token <dval> CONS
%token <symptr> NAME
%token <dval> NUMBER
%nonassoc SYM_INV
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%type <dval> expression
%%
statement_list
    : statement '\n'
    | statement_list statement '\n'
    ;

statement
    : NAME '=' expression { $1->value = $3; }
    | CONS '=' expression { printf("assign to const\n"); }
    | expression { if(divby0 == 1) { printf("divide by zero\n"); divby0 = 0; } printf("= %g\n", $1); }
    | SYM_INV { print_list();}
    ;



expression
    : expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { if($3 == 0) {divby0 = 1; $$ = $1;} else $$ = $1 / $3; }
    | '-' expression %prec UMINUS { $$ = -$2; }
    | '(' expression ')' { $$ = $2; }
    | NUMBER
    | NAME { $$ = $1->value; }
    | CONS
    ;

%%

int list_length()
{
	if(head == NULL) 	/* (n == 0) */
		return 0;
	if(head->next == NULL) 	/* (n == 1) */
		return 1;
	int index = 0;
	struct sym * current = head;
	while(current != NULL) 	/* (n > 1) */
	{
		index++;
		current = current->next;		
	}
	return index;	
}

void print_list()
{
	int length = list_length();	
	printf("num-syms: %i\n\tPHI => 1.61803\n\tPI => 3.14159\n", 2 + length);

	if(head == NULL) 	/* Base Case 1 (n == 0) */
	{
		return;
	}
	if(head->next == NULL) 	/* Base Case 2 (n == 1) */
	{
		printf("\t%s => %d\n", head->name, head->value);
		return;
	}
	
	struct sym * current = head;
	struct sym * sym_to_print = head;
	struct sym * sym_last_printed = head;
	struct sym * largest = head;

	/* Find Nodes that have Smallest and Largest Name Lexicographically */
	while(current != NULL)
	{
		if(strcmp(current->name, sym_to_print->name) < 0)
			sym_to_print = current; 	
		if(strcmp(current->name, largest->name) > 0)
			largest = current;
		current = current->next;	
	}
	printf("\t%s => %f\n", sym_to_print->name, sym_to_print->value);
				
	int i;	
	for(i = 0; i < (length-1); i++) /* General Case (n > 1) */
	{
		current = head;			
		sym_last_printed = sym_to_print;
		sym_to_print = largest;
		while(current != NULL)
		{
			if(strcmp(sym_last_printed->name, current->name) < 0)
			{
				if(strcmp(current->name, sym_to_print->name) < 0)
				{
					sym_to_print = current;
				}
			}
			current = current->next;	
		}		
		printf("\t%s => %f\n", sym_to_print->name, sym_to_print->value);
	}
}

struct sym * sym_lookup(char * s)
{
	char * p; // I dont know the point of this C Style String. It was left unused in the given sym_lookup function so i left it here as well
	struct sym * temp = (struct sym *)malloc(sizeof(struct sym));

	temp->name = strdup(s);	// Declare Temp Node
	temp->next = NULL;
	
	if(head == NULL)		/* Base Case 1 (n == 0) */
	{
		head = temp;
	}
	else if(head->next == NULL)	/* Base Case 2 (n == 1) */
	{
		if(strcmp(head->name, s) == 0) // Case 1: Symbol Exists
			return head;
		head->next = temp; // Case 2: Symbol Doesn't Exist
	}
	else				/* General Case (n > 1) */
	{
		struct sym * current = head;
		while(1) 
		{
			if(strcmp(current->name, s) == 0) // Case 1: Symbol Exists
			{
				current->name = strdup(s);
				return current;  
			}
			if(current->next == NULL) // Case 2: Symbol Doesn't Exist
			{
				current->next = temp; 				
			}
			current = current->next;
		}	
	}
	return temp;
}
