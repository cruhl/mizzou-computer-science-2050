#include <stdlib.h>
#include "stack.h"

stack* create_stack() {
	// create space for stack
	stack* new_stack = (stack*)malloc(sizeof(stack));
	new_stack->stack = NULL;
	new_stack->size = 0;

	return new_stack;
}

void push(stack *s, int val) {
	// create new node
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = val;
	new_node->next = s->stack;

	// update the stack
	s->stack = new_node; 
	s->size++;
}

void pop(stack *s) {
	// stack is empty
	if (!s->stack) return;

	// delete top and update stack
	node* top = s->stack;
	s->stack = top->next;
	s->size--;
	free(top);
}

int top(stack *s) {
	// return data if exists or 0
	return s->stack ? s->stack->data : 0;
}

int isEmpty(stack *s) {
	// if empty return 0 else return 1
	return s->stack == NULL ? 1 : 0;
}