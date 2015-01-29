#ifndef STACK_H
#define STACK_H

// define stack and node structs
struct node_ {
	int data;
	struct node_ *next;
};
struct stack_ {
	unsigned int size;
	struct node_ *stack;
};
typedef struct stack_ stack;
typedef struct node_ node;

// function prototypes
stack* create_stack();
void push(stack* s, int val);
void pop(stack* s);
int top(stack* s);
int isEmpty(stack* s);
#endif