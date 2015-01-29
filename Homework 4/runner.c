#include "print.h"

#define MAX_NUMBER_OF_NODES 250

// function prototypes for main
tree* read_file_into_tree(char* file);

int main(int argc, char* argv[]) {

	// read file data into a new bst
	tree* balanced_tree = read_file_into_tree(argv[1]);

	// program logic
	printf("\nbalanced tree:\n\n");
	print_tree(balanced_tree);

	// inorder prints
	printf("\ntraversed inorder (iteratively):  ");
	print_tree_inorder(balanced_tree);
	printf("\ntraversed inorder (recursively):  ");
	print_tree_inorder_recursively(balanced_tree);

	// preorder prints
	printf("\ntraversed preorder (iteratively):  ");
	print_tree_preorder(balanced_tree);
	printf("\ntraversed preorder (recursively):  ");
	print_tree_preorder_recursively(balanced_tree);

	// breadth first print
	printf("\ntraversed breadth first (iteratively):  ");
	print_tree_breadth_first(balanced_tree);

	// padding
	printf("\n\n");

	// kill the tree's memory
	tree_destroy(balanced_tree);

	return 0;
}

tree* read_file_into_tree(char* file) {
	// create file pointer
	FILE *data_file = fopen(file, "r");
	if (data_file == NULL) printf("File \"%s\" not found!\n", file);

	// read file into array
	int length = 0;
	int array[MAX_NUMBER_OF_NODES];
	while (fscanf(data_file, "%d", &array[length]) == 1) {
		length++;
	}

	// close file
	fclose(data_file);

	// create and return bst
	return tree_new_balanced(array, 0, length - 1);
}