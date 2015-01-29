#include "tree.h"

tree* tree_new_balanced(int array[], int low, int high) {
	// at end of branch
	if (low > high) return NULL;

	// get middle of array
	int middle = (high + low) / 2;

	// malloc space for new node
	tree* new_node = (tree*)malloc(sizeof(tree));
	if (!new_node) return NULL;

	// set members
	new_node->data = array[middle];
	new_node->left = tree_new_balanced(array, low, middle - 1);
	new_node->right = tree_new_balanced(array, middle + 1, high);

	return new_node;
}

void tree_destroy(tree* tree) {
	if (!tree) return;

	tree_destroy(tree->left);
	tree_destroy(tree->right);

	free(tree);
}