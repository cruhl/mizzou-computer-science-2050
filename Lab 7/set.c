/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/21/2014
		Lab Section C
		Code: Charizard
*/

#include "set.h"

// add something to a list
Set* set_insert(Set* set, int data) {
	// avoid duplicates
	Set* current_set = set;
	while (current_set) {
		if (current_set->data == data) return set;
		current_set = current_set->next;
	}

	// allocate memory for new node
	Set* new_head = (Set*)malloc(sizeof(Set));
	if (!new_head) return NULL;

	// set up node
	new_head->data = data;
	new_head->next = set;

	// return the new list start pointer
	return new_head;
}

// remove sets with certain number
Set* set_remove(Set* set, int data) {
	Set* set_start;

	if (set->data == data) {
		Set* set_start = set->next;
		free(set);
		return set_start;
	}

	set_start = set;
	Set* previous = NULL;
	while (set) {
		if (set->data == data) {
			if (previous) {
				previous->next = set->next;
			}
			free(set);
		}
		previous = set;
		set = set->next;
	}
	return set_start;
}

// find intersection
Set* set_intersection(Set* first, Set* second) {
	Set* intersection_set_start = NULL;
	Set* second_start = second;

	// loop though and check for equalities
	while (first) {
		while (second) {
			if (first->data == second->data) {
				// update intersection
				intersection_set_start = set_insert(intersection_set_start, first->data);
			}
			second = second->next;
		}
		second = second_start;
		first = first->next;
	}

	// return set pointer
	return intersection_set_start;
}

// show the list
void print_list(Set* list) {
	// loop through list and print
	Set* next_set = NULL;
	while (list) {
		next_set = list->next;
		printf("%d -> %s", list->data, next_set ? "" : "NULL\n");
		list = list->next;
	}
}

// give space back
void free_list(Set* list) {
	// loop through list and free
	Set* current_set = list;
	while (list) {
		list = list->next;
		free(current_set);
		current_set = list;
	}
}