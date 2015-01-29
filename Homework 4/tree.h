#include <stdlib.h>

// node struct
typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
} tree;

// function prototypes
tree* tree_new_balanced(int array[], int low, int high);
void tree_destroy(tree* tree);