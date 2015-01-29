/*
	Header: 
		Conner Ruhl
		ID: 14226013
		11/4/2014
		Lab Section C
		Code: Euphonium
*/

#include "bst.h"

BST* read_file_into_BST(char* file);

int main(int argc, char* argv[]) {
	// read file data into a new BST
	BST* bst = read_file_into_BST(argv[1]);

	printf("\nBST values in order:\n");
	inorder(bst);
	printf("\n");

	// search for value given by command, print results
	int value_to_find = atoi(argv[2]);
	BST* result = find(bst, value_to_find);
	if (result) {
		printf("Node with data \"%d\" found.\n", result->data);
	} else {
		printf("Node with data \"%d\" not found!\n", value_to_find);
	}

	// find node closest to value then print
	int second_value_to_find = atoi(argv[3]);
	result = closest(bst, second_value_to_find);
	if (result) {
		printf("Node with data \"%d\" is closest to \"%d\".\n\n", result->data, second_value_to_find);
	}


	// kill the tree's memory
	destroy(bst);

	return 0;
}

BST* read_file_into_BST(char* file) {
	// create file pointer
	FILE *data_file = fopen(file, "r");
	if (data_file == NULL) printf("File \"%s\" not found!\n", file);

	// read file into BST
	BST* bst = NULL;
	int data;
	while (fscanf(data_file, "%d", &data) == 1) {
		bst = insert(bst, data);
	}

	// close file and return root
	fclose(data_file);
	return bst;
}