#include "list.h"

void list_pop(list** root) {
	// stack is empty
	if (!*root) return;

	// delete top and update stack
	list* old_root = *root;
	*root = old_root->next;
	free(old_root);
}

void list_prepend(list** root, tree* node) {
	// create new node
	list* new_item = (list*)malloc(sizeof(list));
	new_item->node = node;
	new_item->next = *root;

	// update the list
	*root = new_item;
}

void list_append(list** root, tree* node) {
	// go to last element
	if (*root) {
		// create new item with NULL list
		list* new_item = NULL;
		list_prepend(&new_item, node);

		// find end and set it's next member to be the new item
		list* current_node = *root;
		while (current_node->next) {
			current_node = current_node->next;
		}
		current_node->next = new_item;

	} else {
		// if list is empty, behavior is identical to prepend
		list_prepend(root, node);
	}
}