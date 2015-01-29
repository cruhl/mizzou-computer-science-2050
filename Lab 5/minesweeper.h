/*
	Header: 
		Conner Ruhl
		ID: 14226013
		10/07/2014
		Lab Section C
		Code: Jace, the Mind Sculpter
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BoardSize 10

typedef enum {
	covered,
	uncovered,
	uncoveredWithNumber,
	coveredBomb,
	uncoveredBomb
} PositionType;

void setBoard(PositionType board[BoardSize][BoardSize], int numMines);
void displayBoard(PositionType board[BoardSize][BoardSize]);
int hasWon(PositionType board[BoardSize][BoardSize]);
int countBombs(PositionType board[BoardSize][BoardSize], int rowInitial, int columnInitial);
void showSpaces(PositionType board[BoardSize][BoardSize], int rowInitial, int columnInitial);
int processGuess(PositionType board[BoardSize][BoardSize], int testRow, int testColumn);