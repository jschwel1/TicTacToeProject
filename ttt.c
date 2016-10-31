#include <stdio.h>
#include <stdlib.h>
#include "ttt.h"

tttBoard * buildBoard(){
	tttBoard * b = (tttBoard *)malloc(sizeof(tttBoard));
	int r, c;
	
	if (b == NULL){
		fprintf(stderr, "Error getting memory allocation!\n");
		exit(1);
	}
	
	// Add empty spaces to the board
	for (r = 0; r <ROWS; r++){
		for (c = 0; c < COLUMNS; c++){
			b->board[r][c] = EMPTY;
		}
	}
	
	// set the player
	
	return b;
}

char getWinner(tttBoard * b){
	int r, c;
	// Check for horizontal wins
	
	for (r = 0; r < ROWS; r++){
		for (c = 0; c < COLUMNS-1; c++){
			// if this spot is not the same as the one next to it
			// there cannot be a horizontal win in this row
			if (b->board[r][c] != b->board[r][c+1]) break;
			// If we are checking the second to last against the 
			// last column and they are the same (just like all 
			// previous values in the row), then that value is 
			// the winner of this row!
			else if (c == COLUMNS-2) return b->board[r][c];
		}
	}


	// Check for vertrical wins
	// do the same thing as the horizontal win check, pretty much
	for (c = 0; c < COLUMNS; c++){
		for (r = 0; r < ROWS-1; r++){
			if (b->board[r][c] != b->board[r+1][c]) break;
			else if (r == ROWS-2) return b->board[r][c];
		}
	}	



	// check for diagonal wins
	// The easy diagonal r == c
	for (r = 0; r < ROWS-1; r++){
		// This is just a safety check since we use #defines for the lengths
		if (r >= COLUMNS-1) break;
		
		if (b->board[r][r] !=b->board[r+1][r+1]) break;
		if (r == ROWS-2) return b->board[r][r];
	}

	// the other diagonal
	for (r = ROWS-1; r > 0; r--){
		c = ROWS-1-r;
		if (c >= COLUMNS) break;
		if (c < 0) break;

		if (b->board[r][c] != b->board[r-1][c+1]) break;
	
		if (r == 1) return b->board[r][c];
		
	}
	return EMPTY;
}

/*
 *
 *     1|2|3
 *     -+-+-
 *     4|5|6
 *     -+-+-
 *     7|8|9
 *
 *
 */
void printBoard(tttBoard * b){
	int r, c;

	for (r = 0; r < ROWS; r++){
		for (c = 0; c < COLUMNS; c++){
			if (b->board[r][c] == EMPTY) printf("%d", r*COLUMNS+c+1);
			else printf("%c",b->board[r][c]);
			if (c < COLUMNS-1) printf("|");
		}
		printf("\n");
		
		if (r < ROWS-1) {	
			for (c = 0; c < COLUMNS-1; c++) printf("-+");
			printf("-\n");
		}
	}
}

char readInput(){
	char input;
	int temp;

	if (0 == scanf("%d", &temp)) return -1;
	input = (char)temp;

	return input;
}

char switchPlayers(char player){
	if (player == X) player = O;
	else player = X;

	return player;
}

void freeBoard(tttBoard * b){
	free(b);
}

char available(char pos, tttBoard * b){
	int c = (pos-1) % ROWS;
	int r = (pos-1) / COLUMNS;
	if (c < 0 || c >= COLUMNS) return 0;
	if (r < 0 || r >= COLUMNS) return 0;
	if (b->board[r][c] != EMPTY) return 0;
	return 1;
}

tttBoard * addPiece(tttBoard * b, char pos, char player){
	int c = (pos-1)%ROWS;
	int r = (pos-1)/COLUMNS;
	char piece = (player == X)?'X':'O';

	b->board[r][c] = piece;

	return b;
}


char numSpacesLeft(tttBoard * b){
	char n = 0; 
	int r, c;

	for (r = 0; r < ROWS; r++){
		for (c = 0; c < COLUMNS; c++){
			if (b->board[r][c] == EMPTY) n++;
		}
	}
	return n;
}

