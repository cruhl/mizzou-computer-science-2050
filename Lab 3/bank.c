/*
	Header: 
		Conner Ruhl
		ID: 14226013
		09/16/2014
		Lab Section C
		Code: A Day To Rememeber
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX_ACCOUNTS 20

// account struct
typedef struct {
	int accountId;
	float balance;
} Account;

// function prototypes
int load_accounts(Account accounts[], char* fileName);
void sort(Account accounts[], int length);
Account* find_account(Account accounts[], int low, int high, int id);
void run_transactions(Account accounts[], int length, char* fileName);
void print(Account accounts[], int length);

// main function
int main(int argc, char* argv[]) {
	// create empty library array
	Account accounts[MAX_ACCOUNTS];

	// try to populate the array
	int length = load_accounts(accounts, argv[1]);

	// sort the library
	sort(accounts, length);

	printf("\n");
	// run transactions
	run_transactions(accounts, length, argv[2]);

	// print the accounts
	print(accounts, length);	

	return 0;
}

// populate accounts array
int load_accounts(Account accounts[], char* fileName) {
	// create file pointer
	FILE *data_file = fopen(fileName, "r");
	if (data_file == NULL) {
		printf("File \"%s\" not found!\n", fileName);
		exit(EXIT_FAILURE);
	}

	// populate empty structs with data
	int length = 0;
	while (length < MAX_ACCOUNTS && fscanf(data_file, "%d %f", &accounts[length].accountId, &accounts[length].balance) == 2) {
		length++;
	}

	// close file and return length
	fclose(data_file);
	return length;
}

// populate accounts array
void run_transactions(Account accounts[], int length, char* fileName) {
	// create file pointer
	FILE *data_file = fopen(fileName, "r");
	if (data_file == NULL) {
		printf("File \"%s\" not found!\n", fileName);
		exit(EXIT_FAILURE);
	}

	// run through transactions file
	int accountId;
	float transactionAmount;
	while (fscanf(data_file, "%d %f", &accountId, &transactionAmount) == 2) {
		// execute transaction
		Account* account = find_account(accounts, 0, length, accountId);
		if (account != NULL) {
			if (account->balance + transactionAmount > 0) {
				account->balance += transactionAmount;
			} else {
				printf("Bad Transaction: Insufficient funds!\n");
			}
		} else {
			printf("Bad Transaction: Account with ID \"%d\" not found!\n", accountId);
		}
	}

	// close file and return length
	fclose(data_file);
}

// bubble sort (sorry)
void sort(Account accounts[], int length) {
	// loop through all accounts
	int current_indice;
	for (current_indice = 0; current_indice < length; current_indice++) {
		// test current movie against all movies to its right
		int test_indice;
		for (test_indice = current_indice + 1; test_indice < length; test_indice++) {
			// test if current movie is larger than the test movie
			if (accounts[current_indice].accountId > accounts[test_indice].accountId) {
				// swap books
				Account temporary = accounts[current_indice];
				accounts[current_indice] = accounts[test_indice];
				accounts[test_indice] = temporary;
			}
		}
	}
}

// recursive binary search function
Account* find_account(Account accounts[], int low, int high, int id) {
	// no result has been found if the bounds overlap
	if (high < low) return NULL;

	// find the midpoint between the high and low bounds
	int midpoint = (high + low) / 2;

	// check if the value at the midpoint equals the key, if so return the midpoint
	if (accounts[midpoint].accountId == id) return &accounts[midpoint];

	// set up bounds for next recursion
	accounts[midpoint].accountId > id ? (high = midpoint - 1) : (low = midpoint + 1);

	// recursively call the search function until return conditions are met
	return find_account(accounts, low, high, id);
}

// function to show the accounts
void print(Account accounts[], int length) {
	// loop through accounts and display properties
	printf("Final Balance Sheet:\n");
	int i;
	for (i = 0; i < length; i++) {
		printf(
			"%d $%.2f\n",
			accounts[i].accountId,
			accounts[i].balance
		);
	}
	printf("\n");
}