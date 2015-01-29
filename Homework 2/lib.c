#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num) {
	// allocate memory for a seat
	Seat* seat = (Seat*)malloc(sizeof(Seat));
	if (!seat) return NULL;

	// set up seat strings
	seat->fName = (char*)malloc(strlen(fName) * sizeof(char) + 1);
	strcpy(seat->fName, fName);

	seat->lName = (char*)malloc(strlen(lName) * sizeof(char) + 1);
	strcpy(seat->lName, lName);

	seat->destination = (char*)malloc(strlen(dest) * sizeof(char) + 1);
	strcpy(seat->destination, dest);

	int origin_length = strlen(origin) - 4; // remove txt
	seat->origin = (char*)malloc(origin_length * sizeof(char) + 1);
	strncpy(seat->origin, origin, origin_length);

	// assign seat number
	seat->seatNumber = num;

	// return a pointer to the seat
	return seat;
}

void empty_seat(Seat** seat) {
	// print exit
	printf("%s %s left the plane in %s.\n", (*seat)->fName, (*seat)->lName, (*seat)->destination);
	
	
	// free all parts of struct
	free((*seat)->fName);
	free((*seat)->lName);
	free((*seat)->destination);
	free((*seat)->origin);
	
	*seat = NULL;
	
}


Seat* check_in(Seat* plane, Seat* seat) {
	// if no plane pointer or seat number is less than plane seat number
	if (!plane || seat->seatNumber < plane->seatNumber) {
		plane = seat;
	} else { // update plane pointer
		plane->next = check_in(plane->next, seat);
	}
	return plane;
}

Seat* land(Seat* plane, char* location) {
	if (plane) {
		if (strstr(location, plane->destination)) {
			Seat* next = plane->next;
			empty_seat(&plane);
			plane = land(next, location);
		} else {
			plane->next = land(plane->next, location);
		}
	}
	return plane;
}