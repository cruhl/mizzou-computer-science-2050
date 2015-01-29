#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char* argv[]) {
	// pad
	printf("\n");

	// go through files
	int current_file_index = 1;
	Seat* current_seat = NULL;
	Seat* plane = NULL;

	while (current_file_index < argc) {
		// land the last plane
		if (plane) plane = land(plane, argv[current_file_index]);

		// load the plane
		FILE *data_file = fopen(argv[current_file_index], "r");
		if (data_file == NULL) {
			printf("File \"%s\" not found!\n", argv[current_file_index]);
		} else {
			// set up pointers
			Seat* new_seat = NULL;

			// read in data and create linked list
			char fName[STRING_SIZE];
			char lName[STRING_SIZE];
			char dest[STRING_SIZE];
			int num;
			while (fscanf(data_file, "%s %s %s %d", fName, lName, dest, &num) == 4) {
				new_seat = create_seat(fName, lName, argv[current_file_index], dest, num);
				printf("%s %s got on the plane in %s.\n", new_seat->fName, new_seat->lName, new_seat->origin);
				plane = check_in(plane, new_seat);
			}

			// close file
			fclose(data_file);
		}

		current_file_index++;
	}

	// pad
	printf("\n");
}