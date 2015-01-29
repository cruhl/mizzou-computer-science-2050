#include "print.h"

void print_tree_level(tree* root, int direction, int level) {
	if (!root) return;

	// recursively draw right side
	print_tree_level(root->right, 1, level + 1);

	// padding
	int i;
	for (i = 0; i < level; i++) {
		printf("     ");
	}

	// print data and connecting line
	printf("%s %d\n", direction == 0 ? "—" : (direction == 1 ? "/" : "\\"), root->data);
	
	// recursively draw left side
	print_tree_level(root->left, -1, level + 1);
}

void print_tree(tree* root) {
	if (!root) return;

	// set up recursive draw
	print_tree_level(root, 0, 0);
}

void print_tree_inorder(tree* root) {
	if (!root) return;

	list* stack = NULL;
	tree* current_node = root;

	// loop through until left side end reach, or stack emtpy
	while (stack || current_node) {

		// get to left side end
		if (current_node) {
			list_prepend(&stack, current_node);
			current_node = current_node->left;

		// go through stack and right side and print
		} else if (stack) {
			current_node = stack->node;
			printf("%d ", current_node->data);

			current_node = current_node->right;
			list_pop(&stack);
		}
	}
}
void print_tree_inorder_recursively(tree* root) {
	if (!root) return;

	// recursively traverse and print
	print_tree_inorder_recursively(root->left);
	printf("%d ", root->data);
    print_tree_inorder_recursively(root->right);
}

void print_tree_preorder(tree* root) {
	if (!root) return;

	list* stack = NULL;
	list_prepend(&stack, root);

	// while items are in the stack, keep building and print
	tree* current_node = NULL;
	while (stack) {
		current_node = stack->node;
		printf("%d ", current_node->data);
		list_pop(&stack);

		// add child nodes to stack
		if (current_node->right) list_prepend(&stack, current_node->right);
		if (current_node->left) list_prepend(&stack, current_node->left);
	}	
}
void print_tree_preorder_recursively(tree* root) {
	if (!root) return;

	// recursively traverse and print
	printf("%d ", root->data);
	print_tree_preorder_recursively(root->left);
    print_tree_preorder_recursively(root->right);
}

void print_tree_breadth_first(tree* root) {
	if (!root) return;

	list* queue = NULL;
	list_prepend(&queue, root);

	// while the queue exists, keep building and peint
	tree* current_node = NULL;
	while (queue) {
		current_node = queue->node;
		printf("%d ", current_node->data);

		// add chidren to queue
		list_pop(&queue);
		if (current_node->left) list_append(&queue, current_node->left);
		if (current_node->right) list_append(&queue, current_node->right);
	}
}