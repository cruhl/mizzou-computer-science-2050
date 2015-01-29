/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/21/2014
		Lab Section C
		Code: Charizard
*/

#include "queue.h"

// add something to a list
Queue* enqueue(Queue* queue, char* data) {
	// create new node
	Queue* new_node = malloc(sizeof(Queue));
	if (!new_node) return NULL;

	// copy data
	new_node->data = malloc(sizeof(char) * (strlen(data) + 1));
	strcpy(new_node->data, data);
	new_node->next = NULL;
	
	// make sure queue exists, if not start it
	if(!queue) return new_node;
	Queue* current_node = queue;
	while(current_node->next != NULL) {
		current_node = current_node->next;
	}
	current_node->next = new_node;

	return queue;
}

char* dequeue(Queue** queue) {

	if(!*queue) return NULL;

	// collect useful things
	Queue* next = (*queue);
	char* data = next->data;
	*queue = (next)->next;
	
	free(next);
	return data;
}

int size(Queue* queue) {
	// count nodes
	int length = 0;
	while (queue) {
		length++;
		queue = queue->next;
	}
	return length;
}

Queue* print(Queue* queue) {
	sleep(1);

	// loop through queue and dequeue
	char* data = NULL;
	while (queue) {
		data = dequeue(&queue);
		printf("%s", data);
		free(data);
	}

	return NULL;
}