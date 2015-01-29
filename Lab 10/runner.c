#include "bst.h"

// function prototype for main
bst* read_file_into_bst(char* file);

int main(int argc, char* argv[]) {
	// read file data into a new BbstST
	bst* tree = read_file_into_bst(argv[1]);

	// program logic
	printf("Original Tree:\n");
	print(tree);

	// kill the tree's memory
	destroy(tree);

	return 0;
}

bst* read_file_into_bst(char* file) {
	// create file pointer
	FILE *data_file = fopen(file, "r");
	if (data_file == NULL) printf("File \"%s\" not found!\n", file);

	// read file into array
	int length;
	fscanf(data_file, "%d", &length);

	int array[length];
	int i;
	for (i = 0; i < length; i++) {
		fscanf(data_file, "%d", &array[i]);
	}

	// close file
	fclose(data_file);

	// create and return bst
	merge_sort(array, 0, length - 1);
	return build_balanced_tree(array, 0, length - 1);
}