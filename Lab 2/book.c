/*
	Header: 
		Conner Ruhl
		ID: 14226013
		09/09/2014
		Lab Section C
		Code: Bullet For My Valentine
*/

#include <stdlib.h>
#include <stdio.h>

// book struct
typedef struct {
	char title[20];
	char author[20];
	int rating;
} Book;

#define MAX_LIBRARY_SIZE 30

// function prototypes
int populate_array(Book library[], char* input);
void sort(Book library[], int length);
int binary_search(Book library[], int low, int high, int key);
void print(Book library[], int length, int key);

// main function
int main(int argc, char* argv[]) {
	// create empty library array
	Book library[MAX_LIBRARY_SIZE];

	// try to populate the array
	int length = populate_array(library, argv[1]);

	// sort the library
	sort(library, length);

	// ask what to serch for
	printf("\nEnter a rating to search for: ");
	int value;
	scanf("%d", &value);
	printf("\n");

	// search for rating and display results
	int found_indice = binary_search(library, 0, length, value);
	if (found_indice != -1) {
		// found
		print(library, length, value);
	} else {
		// not found
		printf("No item was found with the rating \"%d\".\n", value);
	}
	printf("\n");

	return 0;
}

// populate book array
int populate_array(Book library[], char* input) {
	// create file pointer
	FILE *data_file = fopen(input, "r");
	if (data_file == NULL) {
		printf("File \"%s\" not found!\n", input);
		exit(EXIT_FAILURE);
	}

	// get number of books and correct if needed
	int length;
	fscanf(data_file, "%d", &length);
	if (length > MAX_LIBRARY_SIZE) length = MAX_LIBRARY_SIZE;

	// populate empty structs with data
	int i;
	for (i = 0; i < length; i++) {
		fscanf(
			data_file,
			"%s %s %d",
			library[i].title,
			library[i].author,
			&library[i].rating
		);
	}

	// close file and return length
	fclose(data_file);
	return length;
}

// bubble sort (sorry)
void sort(Book library[], int length) {
	// loop through all movies
	int current_indice;
	for (current_indice = 0; current_indice < length; current_indice++) {
		// test current movie against all movies to its right
		int test_indice;
		for (test_indice = current_indice + 1; test_indice < length; test_indice++) {
			// test if current movie is larger than the test movie
			if (library[current_indice].rating > library[test_indice].rating) {
				// swap books
				Book temporary = library[current_indice];
				library[current_indice] = library[test_indice];
				library[test_indice] = temporary;
			}
		}
	}
}

// recursive binary search function
int binary_search(Book library[], int low, int high, int key) {
	// no result has been found if the bounds overlap
	if (high < low) return -1;

	// find the midpoint between the high and low bounds
	int midpoint = (high + low) / 2;

	// check if the value at the midpoint equals the key, if so return the midpoint
	if (library[midpoint].rating == key) return midpoint;

	// set up bounds for next recursion
	library[midpoint].rating > key ? (high = midpoint - 1) : (low = midpoint + 1);

	// recursively call the search function until return conditions are met
	return binary_search(library, low, high, key);
}

// function to show the catalog
void print(Book library[], int length, int key) {
	// loop through library and display properties
	int i;
	for (i = 0; i < length; i++) {
		if (key == library[i].rating) printf("***");
		printf(
			"%s %s %d\n",
			library[i].title,
			library[i].author,
			library[i].rating
		);
	}
	printf("\n");
}