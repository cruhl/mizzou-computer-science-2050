/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/07/2014
		Lab Section C
		Code: Jace, the Mind Sculpter
*/

#include "minesweeper.h"

int main(int argc, char* argv[]) {
	// set up board
	PositionType board[BoardSize][BoardSize];
	int numberOfBombs = atoi(argv[1]);
	setBoard(board, numberOfBombs);

	// game loop
	int gameState, row, column;
	do {
		// ask for guess
		printf("Your move?: \n");
		scanf("%d %d", &row, &column);
		printf("\n");

		// process move
		gameState = processGuess(board, row - 1, column - 1);
		if (gameState == -1) {
			printf("Invalid move!\n\n");
		} else if (gameState == 0) {
			printf("You've already played there!\n\n");
		}

		// show the board
		displayBoard(board);
		printf("\n");
	} while (gameState != 2 && hasWon(board) == 0);

	// game over, check for win or lose
	if (gameState != 2) {
		printf("YOU WIN!\n\n");
	} else {
		printf("YOU LOSE!\n\n");
	}

	return 0;
}