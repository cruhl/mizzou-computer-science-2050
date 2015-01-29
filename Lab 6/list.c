/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/07/2014
		Lab Section C
		Code: Rick and Marty
*/

#include "list.h"

node* insert_at_head(node* list, int data) {
	// allocate memory for new node
	node* new_head = (node*)malloc(sizeof(node));
	if (!new_head) return NULL;

	// set up node
	new_head->data = data;
	new_head->next = list;

	// return the new list start pointer
	return new_head;
}

/*
	node* reverse_list(node* list) {
		node* new_head = NULL;
		node* next = NULL;

		while (list) {
			next = list->next;
			list->next = new_head;
			new_head = list;
			list = next;
		}
		return new_head;
	}

	^ NOTE: Recursion has no benefit here, a while
	would have sufficed since both are O(n) and a
	non-recursive function is simpler to implement.

	Moving on...
*/
void reverse_list(node** list_start_pointer) {
	// list doesn't exist, done
	if (!list_start_pointer) return;

	// use the next node
	node* next = (*list_start_pointer)->next;

	// only one item, done
	if (!next) return;

	// recursively shift nodes
	reverse_list(&next);

	// update nodes
	((*list_start_pointer)->next)->next = *list_start_pointer;  
	(*list_start_pointer)->next = NULL;

	*list_start_pointer = next;
}

void print_list(node* list) {
	// loop through list and print
	node* next_node = NULL;
	while (list) {
		next_node = list->next;
		printf("%d -> %s", list->data, next_node ? "" : "tis' NULL!");
		list = list->next;
	}

	// pad that fella
	printf("\n");
}

void free_list(node* list) {
	// loop through list and free
	node* current_node = list;
	while (list) {
		free(list);
		list = list->next;
	}
}