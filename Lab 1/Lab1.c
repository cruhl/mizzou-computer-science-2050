/*
	Conner Ruhl - 14226013/ctr9rc
	Lab 1 - 08/26/2014
*/

#include <stdio.h>

// movie struct
typedef struct {
	char title[20];
	int yearReleased;
	int sales;
	int ticketsSold;
} Movie;

#define MAX_ARR_LEN 20

Movie movie_catalog[MAX_ARR_LEN];

// prototypes
int populate_movie_catalog();
float average_ticket_price(int length);
int find_highest_grossing_movie(int length);
void print_catalog();
void sort(int length);

int main(void) {
	// create movie_catalog array
	int number_of_movies = populate_movie_catalog();
	sort(number_of_movies);

	// show the catalog
	print_catalog(number_of_movies);

	// show the average ticket price
	float the_average_ticket_price = average_ticket_price(number_of_movies);
	printf("Average ticket price: $%f\n", the_average_ticket_price);

	// show the highest grossing movie
	int highest_grossing_movie = find_highest_grossing_movie(number_of_movies);
	printf("Highest grossing movie: \"%s\"\n\n", movie_catalog[highest_grossing_movie].title);

	// good run
	getchar();
	return 0;
}

int populate_movie_catalog() {
	// create file pointer
	FILE *data_file;
	data_file = fopen("data.txt", "r");

	// get number of movies and correct if needed
	int length;
	fscanf(data_file, "%d", &length);
	if (length > MAX_ARR_LEN) length = MAX_ARR_LEN;

	// populate empty structs with data
	for (int i = 0; i < length; i++) {
		fscanf(
			data_file,
			"%s %d %d %d",
			movie_catalog[i].title,
			&movie_catalog[i].yearReleased,
			&movie_catalog[i].sales,
			&movie_catalog[i].ticketsSold
		);
	}

	// close file and return length
	fclose(data_file);
	return length;
}

float average_ticket_price(int length) {
	// keep a sum
	float sum = 0;

	// loop through movies
	for (int i = 0; i < length; i++) {
		// add the current movie's ticket price
		sum += (float)movie_catalog[i].sales / (float)movie_catalog[i].ticketsSold;
	}
	// return mean
	return sum / length;
}

int find_highest_grossing_movie(int length) {
	// keep track of the highest known sales amount
	int max_value = movie_catalog[0].sales;
	int max_indice = 0;

	// loop through movies
	for (int i = 0; i < length; i++) {
		// compare known max to current movie
		if (movie_catalog[i].sales > max_value) {
			// set the new max
			max_value = movie_catalog[i].sales;
			max_indice = i;
		}
	}

	// return the indice of the movie with the most sales
	return max_indice;
}

// function to show the catalog
void print_catalog(int length) {
	printf("Movie Catalog:\n");
	// loop through moviesand display properties
	for (int i = 0; i < length; i++) {
		printf(
			"\"%s\" - %d\n",
			movie_catalog[i].title,
			movie_catalog[i].yearReleased
		);
	}
	printf("\n");
}

// bubble sort (sorry)
void sort(int length) {
	// loop through all movies
	for (int current_indice = 0; current_indice < length; current_indice++) {
		// test current movie against all movies to its right
		for (int test_indice = current_indice + 1; test_indice < length; test_indice++) {
			// test if current movie is larger than the test movie
			if (movie_catalog[current_indice].yearReleased > movie_catalog[test_indice].yearReleased) {
				// swap movies
				Movie temporary = movie_catalog[current_indice];
				movie_catalog[current_indice] = movie_catalog[test_indice];
				movie_catalog[test_indice] = temporary;
			}
		}
	}
}