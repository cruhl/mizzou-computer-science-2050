/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/21/2014
		Lab Section C
		Code: Charizard
*/

// node struct
typedef struct node_ {
	int data;
	struct node_* next;
} Set;

#include <stdlib.h>
#include <stdio.h>

// function prototypes
Set* set_insert(Set* set, int data);
Set* set_remove(Set* set, int data);
Set* set_intersection(Set* first, Set* second);
void print_list(Set* list);
void free_list(Set* list);