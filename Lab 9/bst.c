/*
	Header: 
		Conner Ruhl
		ID: 14226013
		11/4/2014
		Lab Section C
		Code: Euphonium
*/

#include "bst.h"

BST* insert(BST* tree, int data) {
	if (!tree) {
		// malloc space for new node
		BST* new_node = (BST*)malloc(sizeof(BST));
		if (!new_node) return NULL;

		// set members
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->data = data;

		// end recursion
		return new_node;
	} else {
		// recursively go through tree
		if (data < tree->data) {
			tree->left = insert(tree->left, data);
		} else {
			tree->right = insert(tree->right, data);
		}
		return tree;
	}
}

BST* find(BST* tree, int data) {
	if (!tree) {
		// not found, end recursion
		return NULL;
	} else {
		// found, end recursion
		if (data == tree->data) return tree;

		// recursively go through tree
		if (data < tree->data) {
			find(tree->left, data);
		} else {
			find(tree->right, data);
		}
	}
}

BST* closest(BST* tree, int data) {
	BST* closest_node = NULL;

	int distance;
	int smallest_distance = INT_MAX;

	BST* current_node = tree;
	while (current_node) {
		// check if current node is closer, if so, update closest node and smallest distance
		distance = abs(current_node->data - data);
		if (distance < smallest_distance) {
			smallest_distance = distance;
			closest_node = current_node;
		}

		// values are equal, return
		if (distance == 0) return closest_node;

		// traversal makes it O(log(n))
		if (data < current_node->data) {
			current_node = current_node->left;
		} else {
			current_node = current_node->left;
		}
	}

	return closest_node;
}

void inorder(BST* tree) {
	if (!tree) return;
	
	inorder(tree->left);
	printf(" %d", tree->data);
	inorder(tree->right);
}

void destroy(BST* tree) {
	if (!tree) return;

	destroy(tree->left);
	destroy(tree->right);

	free(tree);
}