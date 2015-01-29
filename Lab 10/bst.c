/*
	Header: 
		Conner Ruhl
		ID: 14226013
		11/18/2014
		Lab Section C
		Code: Attack on Titan
*/

#include "bst.h"

bst* build_balanced_tree(int array[], int low, int high) {
	// at end of branch
	if (low > high) return NULL;

	// get middle of array
	int middle = (high + low) / 2;

	// malloc space for new node
	bst* new_node = (bst*)malloc(sizeof(bst));
	if (!new_node) return NULL;

	// set members
	new_node->data = array[middle];
	new_node->left = build_balanced_tree(array, low, middle - 1);
	new_node->right = build_balanced_tree(array, middle + 1, high);

	return new_node;
}

bst* delete_node(bst* tree, int data) {
	
	// perform binary search
	if(!tree) {
		printf("Value \"%d\" not found in tree.\n");
	} else if(data < tree->data) {
		tree->left = delete_node(tree->left, data);
	} else if(data > tree->data) {
		tree->right = delete_node(tree->right, data);
	} else {

		// value found
		bst* temp = NULL;
		if (tree->right && tree->left) {
			temp = minimum(tree->right);
			tree->data = temp->data; 
			tree->right = delete_node(tree->right, temp->data);
		} else {
			
			if(tree->left == NULL) {
				temp = tree->right;
				free(tree);
				return temp;
			} else if (tree->right == NULL) {
				temp = tree->left;
				free(tree);
				return temp;
			}
		}
	}

	return tree;
}

bst* minimum(bst* tree) {
	if (!tree) return NULL;

	// iterate to the bottom
	while(tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}

void reverse(bst* tree) {
    bst* temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;

    if(tree->left) reverse(tree->left);
    if(tree->right) reverse(tree->right);
}

void destroy(bst* tree) {
	if (!tree) return;

	destroy(tree->left);
	destroy(tree->right);

	free(tree);
}

void padding(char character, int n) {
	int i;
	for (i = 0; i < n; i++) {
		putchar(character);
	}
}

void structure(bst* tree, int level) {
	int i;
	if (!tree) {
		padding('\t', level);
		puts("~");
	} else {
		structure(tree->right, level + 1);
		padding('\t', level);
		printf("%d\n", tree->data);
		structure(tree->left, level + 1);
	}
}

void print(bst* tree) {
	structure(tree, 0);
}