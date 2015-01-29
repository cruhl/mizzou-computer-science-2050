/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/07/2014
		Lab Section C
		Code: Rick and Marty
*/

// node struct
typedef struct node_ {
	int data;
	struct node_* next;
} node;

#include <stdlib.h>
#include <stdio.h>

// function prototypes
node* insert_at_head(node* list, int data);
void reverse_list(node** list_start_pointer);
void print_list(node* list);
void free_list(node* list);