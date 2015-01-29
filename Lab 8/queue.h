/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/28/2014
		Lab Section C
		Code: Hookah
*/

// node struct
typedef struct node_ {
	char* data;
	struct node_* next;
} Queue;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// function prototypes
Queue* enqueue(Queue* queue, char* data);
char* dequeue(Queue** queue);
int size(Queue* queue);
Queue* print(Queue* queue);