/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/28/2014
		Lab Section C
		Code: Hookah
*/

#include "queue.h"

int main(int argc, char* argv[]) {
	// try to open the file
	FILE *data_file = fopen(argv[1], "r");
	if (data_file == NULL) {
		printf("File \"%s\" not found!\n", argv[1]);
		return 1;
	}

	// pad output
	printf("\n");

	// read file into linked list
	Queue* queue = NULL;
	char data[100];
	while (fgets(data, 100, data_file)) {
		queue = enqueue(queue, data);
		if (size(queue) >= 3) {
			queue = print(queue);
		}
	}
	queue = print(queue);
	// close file
	fclose(data_file);

	// pad output
	printf("\n\n");

	return 0;
}