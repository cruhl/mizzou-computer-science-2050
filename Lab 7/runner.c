/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/21/2014
		Lab Section C
		Code: Charizard
*/

#include "set.h"

Set* create_set(char* file);

int main(int argc, char* argv[]) {
	// create lists from file
	Set* first_set_start = create_set(argv[1]);
	Set* second_set_start = create_set(argv[2]);

	// print the lists
	printf("\nSet A = ");
	print_list(first_set_start);

	printf("Set B = ");
	print_list(second_set_start);

	// do intersection
	Set* intersection_set_start = set_intersection(first_set_start, second_set_start);
	
	// print it
	printf("Intersection of Sets A & B = ");
	print_list(intersection_set_start);	

	// kill some number from list
	intersection_set_start = set_remove(intersection_set_start, atoi(argv[3]));
	printf("Intersection of Sets A & B without \"%s\" = ", argv[3]);
	print_list(intersection_set_start);

	// return the memory to the OS
	free_list(first_set_start);
	free_list(second_set_start);
	free_list(intersection_set_start);

	printf("\n");

	return 0;
}

Set* create_set(char* file) {
	// create file pointer
	FILE *data_file = fopen(file, "r");
	if (data_file == NULL) {
		printf("File \"%s\" not found!\n", file);
		return NULL;
	}

	// read file into linked list
	int data;
	Set* current_set = NULL;
	while (fscanf(data_file, "%d", &data) == 1) {
		current_set = set_insert(current_set, data);
	}

	// close file and return length
	fclose(data_file);
	return current_set;
}