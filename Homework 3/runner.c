#include <stdio.h>
#include <string.h>
#include "calculator.h"

#define BUFFERSIZE 100

int main(int argc, char* argv[]) {

	char buffer[BUFFERSIZE];

	// check for correct format
	if (argc != 2) {
		printf("correct ussage: %s <input file>\n", argv[0]);
		return 1;
	}

	// try to open file
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("unable to open file: %s\n", argv[1]);
		return 1;
	}
	
	// read in expressions and evaluate them
	char* postfix;
	while (fgets(buffer, BUFFERSIZE, fp)) {
		if (buffer[strlen(buffer) - 1] == '\n') {
			buffer[strlen(buffer) - 1] = '\0';
		}

		postfix = to_postfix(buffer);
		printf("%s = %d\n", buffer, eval(postfix));

		free(postfix);
	}

	return 0;
}