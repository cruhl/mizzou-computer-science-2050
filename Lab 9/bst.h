/*
	Header: 
		Conner Ruhl
		ID: 14226013
		11/4/2014
		Lab Section C
		Code: Euphonium
*/

// node struct
typedef struct node_ {
	int data;
	struct node_* left;
	struct node_* right;
} BST;

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

// function prototypes
BST* insert(BST* tree, int data);
BST* find(BST* tree, int data);
BST* closest(BST* tree, int data);
void inorder(BST* tree);
void destroy(BST* tree);