/*
	Header: 
		Conner Ruhl
		ID: 14226013
		09/23/2014
		Lab Section C
		Code: Killswitch Engage
*/

#include <stdio.h>

#define MAX_ARR_LEN 1000

void merge_sort(int array[], int low, int high);
void merge(int array[], int low, int mid, int high);
int magic_index(int array[], int low, int high);
int populate_array(int array[], char* fileName);
int is_sorted(int array[], int length);

int main(int argc, char* argv[]) {
	// create array
	int array[MAX_ARR_LEN];
	int len = populate_array(array, argv[1]);

	// bad input
	if (len == 0) {
		printf("Invalid input!\n");
		return 1;
	}

	// sort
	merge_sort(array, 0, len);

	// check if sorted
	if (is_sorted(array, len) == 1) {
		printf("Array sorted...\n");
	} else {
		printf("Bad sort!\n");
		return 1;
	}

	// show magic index
	int magic = magic_index(array, 0, len);
	if (magic != -1) {
		printf("A magic index was found! (array[%d] == %d)\n", magic, magic);
	} else {
		printf("No magic index found!\n");
	}

	return 0;
}

void merge_sort(int array[], int low, int high) {
	// if in bounds
	if (low < high) {
		// calculate midpoint
		int midpoint = (high + low) / 2;

		// split array and sort halves
		merge_sort(array, low, midpoint);
		merge_sort(array, midpoint + 1, high);

		// merge results
		merge(array, low, midpoint, high);
	}
}

void merge(int array[], int low, int mid, int high) {
	int temp[MAX_ARR_LEN];

	// set up varibles for merge
	int first_index = low, second_index = mid + 1, current_index = 0;
  
  	// run comparisons while not out of bounds
	while (first_index <= mid && second_index <= high) {
		// comparison
		if (array[first_index] <= array[second_index]) {
			// swap first
			temp[current_index++] = array[first_index++];
		} else {
			// swap second
			temp[current_index++] = array[second_index++];
		}
	}
	// fix bounds for odd number arrays
	while (first_index <= mid) {
		temp[current_index++] = array[first_index++];
	}
	while (second_index <= high) {
		temp[current_index++] = array[second_index++];
	}
  	
  	// write merged array back into the initial array
	current_index--;
	while (current_index >= 0) {
		array[low + current_index] = temp[current_index];
		current_index--;
	}
}

int magic_index(int array[], int low, int high) {
	// no result has been found if the bounds overlap
	if (high < low) return -1;

	// find the midpoint between the high and low bounds
	int midpoint = (high + low) / 2;

	// check if the value at the midpoint equals the key, if so return the midpoint
	if (array[midpoint] == midpoint) return midpoint;

	// set up bounds for next recursion
	array[midpoint] > midpoint ? (high = midpoint - 1) : (low = midpoint + 1);

	// recursively call the search function until return conditions are met
	return magic_index(array, low, high);
}

int populate_array(int array[], char* fileName) {
	// create file pointer
	FILE *data_file = fopen(fileName, "r");
	if (data_file == NULL) return 0;

	// populate empty structs with data
	int length = 0;
	while (length < MAX_ARR_LEN && fscanf(data_file, "%d", &array[length]) == 1) {
		length++;
	}

	// close file and return length
	fclose(data_file);
	return length;
}

int is_sorted(int array[], int length) {
	int i;
	for (i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) return 0;
	}
	return 1;
}