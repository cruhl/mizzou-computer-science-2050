/*
	Header: 
		Conner Ruhl
		ID: 14226013
		11/18/2014
		Lab Section C
		Code: Attack on Titan
*/

#include <stdlib.h>
#include <stdio.h>

// node struct
typedef struct node_ {
	int data;
	struct node_* left;
	struct node_* right;
} bst;

// function prototypes
bst* build_balanced_tree(int array[], int low, int high);
bst* delete_node(bst* tree, int data);
bst* minimum(bst* tree);
void reverse(bst* tree);
void destroy(bst* tree);

void padding(char character, int n);
void structure(bst* tree, int level);
void print(bst* tree);