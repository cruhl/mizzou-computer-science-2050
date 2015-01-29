#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100

static char prec(char operator) {
	// assign precedence based off of operator
	switch (operator) {
		case '*': return 5; break;
		case '/': return 4; break;
		case '%': return 3; break;
		case '+': return 2; break;
		case '-': return 1; break;
	}
	return 0;
}

static int isNumeric(char* num) {
	// check first char in num for numeric, program doesn send num with length > 1 by design
	return isdigit(num[0]) ? 1 : 0;
}

char* to_postfix(char* infix) {
	// output string
	char* postfix = (char*)malloc(MAX_EQU_LEN * sizeof(char));
	char* postfix_position = postfix;

	// stack for operators
	stack* operator_stack = create_stack();

	// variables for looping
	char token;
	char* infix_position = infix;
	while ((token = infix_position[0]) != '\0') {
		// if number, add to postfix string
		if (isNumeric(&token)) {
			*postfix_position++ = token;
			if (
				*(infix_position + 1) == '\0' 
				|| *(infix_position + 1) == ' '
				|| *(infix_position + 1) == ')'
			) {
				*postfix_position++ = ' ';
			}

		// if left parenthesis
		} else if (token == '(') {
			push(operator_stack, token);

		// if right parenthesis
		} else if (token == ')') {
			// push out remaining operators
			while (
				!isEmpty(operator_stack)
				&& top(operator_stack) != '('
			) {
				// add the current top to the postfix string
				*postfix_position++ = top(operator_stack);
				*postfix_position++ = ' ';

				// pop the old top
				pop(operator_stack);
			}

			// kill the left parenthesis
			pop(operator_stack);

		// if left parenthesis
		} else if (prec(token) != 0) {
			// while the stack isn't empty, and the current operator has precedence
			while (
				!isEmpty(operator_stack)
				&& prec(token) <= prec(top(operator_stack))
			) {
				// add the current top to the postfix string
				*postfix_position++ = top(operator_stack);
				*postfix_position++ = ' ';

				// pop the old top
				pop(operator_stack);
			}

			// add the current operator to the stack
			push(operator_stack, token);
		}
		
		// move to the next character
		infix_position++;
	}

	// for all remaining operators, add them to the postfix string
	while (!isEmpty(operator_stack)) {
		*postfix_position++ = top(operator_stack);
		pop(operator_stack);
		if (!isEmpty(operator_stack)) *postfix_position++ = ' ';
	}

	return postfix;
}

int eval(char* postfix) {
	stack *operand_stack = create_stack();

	// variables for looping
	int first_operand, second_operand, result;
	char* token = strtok(postfix, " \n");
	while (token) {
		
		// if digit, add to operands stack
		if (isNumeric(token)) {
			push(operand_stack, atoi(token));

		} else {
			// get operands
			second_operand = top(operand_stack);
			pop(operand_stack);
			first_operand = top(operand_stack);
			pop(operand_stack);

			// execute operation
			switch (token[0]) {
				case '+': result = first_operand + second_operand; break;
				case '-': result = first_operand - second_operand; break;
				case '*': result = first_operand * second_operand; break;
				case '/': result = first_operand / second_operand; break;
				case '%': result = first_operand % second_operand; break;
			}

			// add result to operands
			push(operand_stack, result);
		}

		// move to the next character
		token = strtok(NULL, " \n");
	}

	// get result
	result = top(operand_stack);

	// get back memory
	pop(operand_stack);
	free(operand_stack);

	return result;
}