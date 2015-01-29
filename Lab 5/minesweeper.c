/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/07/2014
		Lab Section C
		Code: Jace, the Mind Sculpter
*/

#include "minesweeper.h"

void setBoard(PositionType board[BoardSize][BoardSize], int numMines) {
	// seed random function
	srand(time(NULL));
	
	// set base board
	int row, column;
	for (row = 0; row < BoardSize; row++) {
		for (column = 0; column < BoardSize; column++) {
			board[row][column] = covered;
		}
	}

	// place bombs
	int i = 0;
	for (i = 0; i < numMines; i++) {
		do {
			row = rand() % BoardSize;
			column = rand() % BoardSize;
		} while (board[row][column] == uncoveredBomb);
		board[row][column] = coveredBomb;
	}
}

void displayBoard(PositionType board[BoardSize][BoardSize]) {
	char display;

	printf("    ");
	int i;
	for (i = 0; i < BoardSize; i++) {
		printf("%2d ", i + 1);
	}
	printf("\n\n");
	
	int row, column;
	for (row = 0; row < BoardSize; row++) {
		printf("%2d ", row + 1);
		for (column = 0; column < BoardSize; column++) {
			switch (board[row][column]) {
				case uncovered:
					display = ' ';
					break;
				case uncoveredBomb:
					display = '@';
					break;			
				case uncoveredWithNumber:
					display = (char)(((int)'0') + countBombs(board, row, column));
					break;
				default:
					display = '#';
					break;		
			}
			printf("  %c", display);
			if (column == BoardSize - 1) printf("\n");
		}
	}
}

int hasWon(PositionType board[BoardSize][BoardSize]) {
	int covereds = 0;
	int row, column;

	// count number of covered spaces, if zero, player wins
	for (row = 0; row < BoardSize; row++) {
		for (column = 0; column < BoardSize; column++) {
			if (board[row][column] == covered) covereds++;
		}
	}

	if (covereds == 0) return 1;
	return 0;
}

int countBombs(PositionType board[BoardSize][BoardSize], int rowInitial, int columnInitial) {
	int bombs = 0;
	int row, column, rowActual, columnActual;

	// loop through adjacent spaces
	for (row = -1; row < 2; row++) {
		rowActual = rowInitial + row;

		// make sure in bounds
		if (rowActual >= 0 && rowActual < BoardSize) {
			for (column = -1; column < 2; column++) {
				columnActual = columnInitial + column;

				// make sure in bounds
				if (columnActual >= 0 && columnActual < BoardSize) {
					// bomb found
					if (board[rowActual][columnActual] == coveredBomb) bombs++; 
				}
			}
		}
	}
	return bombs;
}

void showSpaces(PositionType board[BoardSize][BoardSize], int rowInitial, int columnInitial) {
	int row, column, rowActual, columnActual;

	// loop through adjacent spaces
	for (row = -1; row < 2; row++) {
		rowActual = rowInitial + row;

		// make sure in bounds
		if (rowActual >= 0 && rowActual < BoardSize) {
			for (column = -1; column < 2; column++) {
				columnActual = columnInitial + column;

				// make sure in bounds
				if (columnActual >= 0 && columnActual < BoardSize) {
					if (board[rowActual][columnActual] == covered) {
						// if empty recursively show spaces
						if (countBombs(board, rowActual, columnActual) == 0) {
							board[rowActual][columnActual] = uncovered;
							showSpaces(board, rowActual, columnActual);
						} else { // else show number of boms
							board[rowActual][columnActual] = uncoveredWithNumber;
						}
					}
				}
			}
		}
	}
}

int processGuess(PositionType board[BoardSize][BoardSize], int row, int col) {
	// check for bad move
	if (
		row >= BoardSize
		|| col >= BoardSize
		|| row < 0
		|| col < 0
	) return -1;

	// bomb found
	if (board[row][col] == uncoveredBomb) return 2;

	// move already made
	if (board[row][col] == uncovered) return -1;

	// good move
	if (countBombs(board, row, col) == 0) {
		board[row][col] = uncovered;
	} else {
		board[row][col] = uncoveredWithNumber;
	}
	showSpaces(board, row, col);
	return 1;
}