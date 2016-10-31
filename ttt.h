#ifndef TTT_H
#define TTT_H

#define X 1
#define O -1
#define EMPTY 0
#define ROWS 3
#define COLUMNS 3

typedef struct {
	char board [ROWS][COLUMNS];
} tttBoard;


tttBoard * buildBoard();

char getWinner(tttBoard * b);

char readInput();

tttBoard * addPiece(tttBoard * b, char pos, char player);

void printBoard(tttBoard * b);

char switchPlayers(char player);

void freeBoard(tttBoard * b);

char available(char pos, tttBoard * b);

char numSpacesLeft(tttBoard * b);

#endif
