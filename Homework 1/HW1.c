#include <stdio.h>
#include <string.h>

#define STRING_LEN 20
#define PLAYLIST_LEN 20

typedef struct {
	char artist[STRING_LEN];
	char title[STRING_LEN];
	char album[STRING_LEN];
	int rating;
} Song;

int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles);
int is_member(Song playlist[], int len, char* title);
void sort(Song playlist[], int len);
int do_swap(Song first, Song second);
void print(Song playlist[], int len);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: %s <input 1> <input 2> . . . <input n>\n", argv[0]);
		return -1;
	}
	
	Song playlist[PLAYLIST_LEN];

	int len = build_playlist(playlist, argv + 1, argc - 1);

	if (len == -1) {
		printf("Invalid input: multiple songs with the same title.\n");
		return 0;
	}

	sort(playlist, len);
	print(playlist, len);
	
	return 0;
}

// function to read data from text files into an array of structs
int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles) {
	// index of the current song
	int file_index = 0;
	// songs added
	int number_of_songs = 0;

	// file pointer
	FILE* data_file = NULL;
	while (file_index < numInputFiles && number_of_songs < PLAYLIST_LEN) {
		// create file pointer
		data_file = fopen(inputFiles[file_index], "r");
		if (data_file == NULL) {
			printf("File \"%s\" not found!\n", *inputFiles);
		} else {
			// populate empty structs with data
			// while loop condition expanded for clarity
			while (
				number_of_songs < PLAYLIST_LEN
				&& fscanf(
					data_file, "%s %s %s %d",
					playlist[number_of_songs].artist,
					playlist[number_of_songs].album,
					playlist[number_of_songs].title,
					&playlist[number_of_songs].rating
				) == 4
			) {
				// check for duplicates
				if (is_member(playlist, number_of_songs, playlist[number_of_songs].title)) return -1;

				// update number of songs
				number_of_songs++;
			}

			// close file
			fclose(data_file);
		}

		// move to the next song
		file_index++;
	}

	// return length of playlist
	return number_of_songs;
}

// check if playlist contains title
int is_member(Song playlist[], int len, char* title) {
	int i;
	// loop through songs and check
	for (i = 0; i < len; i++) {
		if (strcmp(playlist[i].title, title) == 0) {
			// found
			return 1;
		}
	}
	// not found
	return 0;
}   

// sort playlist
void sort(Song playlist[], int len) { 
	// loop through all songs
	int current_indice;
	for (current_indice = 0; current_indice < len; current_indice++) {
		// test current movie against all movies to its right
		int test_indice;
		for (test_indice = current_indice + 1; test_indice < len; test_indice++) {
			// check if swap needed
			if (do_swap(playlist[current_indice], playlist[test_indice]) == 1) {
				// swap songs
				Song temporary = playlist[current_indice];
				playlist[current_indice] = playlist[test_indice];
				playlist[test_indice] = temporary;
			}
		}
	}

	// flip array
	Song temporary[len];
	int i;
	for (i = 0; i < len; i++) {
		temporary[i] = playlist[len - i - 1];
	}
	for (i = 0; i < len; i++) {
		playlist[i] = temporary[i];
	}
}

// check if swap is needed
int do_swap(Song first, Song second) {
	// compare artist, then album, and then title
	if (strcmp(first.artist, second.artist) < 0) return 1;
	if (strcmp(first.album, second.album) < 0) return 1;
	if (strcmp(first.title, second.title) < 0) return 1;
	return 0;
}

// print playlist
void print(Song playlist[], int len) { 
	printf("\nPlaylist:\n----------------------------------------------\n");

	// print each song
	int i;
	for (i = 0; i < len; i++) {
		printf("%10s%12s%10s%4d\n", playlist[i].artist, playlist[i].album, playlist[i].title, (char)playlist[i].rating);
	}

	printf("----------------------------------------------\n\n");
}