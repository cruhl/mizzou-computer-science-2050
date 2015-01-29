/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/07/2014
		Lab Section C
		Code: Rick and Marty
*/

#include "list.h"

node* create_list(char* file);

int main(int argc, char* argv[]) {
	// create list from file
	node* list_start = create_list(argv[1]);

	// pad dis program son
	printf("\n");

	// print the list
	print_list(list_start);

	// reverse the list
	reverse_list(&list_start);

	// print the list
	print_list(list_start);
	
	// pad again
	printf("\n");

	// return the memory to the OS
	free_list(list_start);

	return 0;
}

node* create_list(char* file) {
	// create file pointer
	FILE *data_file = fopen(file, "r");
	if (data_file == NULL) {
		printf("File \"%s\" not found!\n", file);
		return NULL;
	}

	// read file into linked list
	int data;
	node* current_node = NULL;
	while (fscanf(data_file, "%d", &data) == 1) {
		current_node = insert_at_head(current_node, data);
	}

	// close file and return length
	fclose(data_file);
	return current_node;
}