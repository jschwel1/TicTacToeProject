#ifndef AI_H
#define AI_H

#include "ttt.h"

struct boardTree_n {
	// each node will have a board
	tttBoard b;
	// each node will also be part of a list of nodes
	struct boardTree_n * next;
	struct boardTree_n * child;
	// each node will have a value for which piece on the board was taken and by which player
	char spot;
	char player;
	// each node will have a value for win/lose
	char winCount;

};

typedef struct boardTree_n boardTree;

boardTree * buildTree(boardTree * b, char p);

boardTree * newNode(tttBoard * b, char spot, char player);

char analyzeTree(boardTree * b, char player);

char freeTree(boardTree * b);

char getBestMove(tttBoard * b);


#endif
