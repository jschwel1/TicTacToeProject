#include "ttt.h"
#include "AI.h"
#include <stdlib.h>

/* bestMove(tttBoard * b, char p, char o);
 * parameters:	tttBoard * b - a pointer to the board being played on
 * 		char p - the char corresponding to the current player
 * 		char o - the char corresponding to the opponent
 * NOTE: this only works on a 3x3 board
 *
 */
char bestMove(tttBoard * b, char p){
	boardTree * bt = buildTree(b, p);
	char val[ROWS*COLUMNS] = {0};
	char maxIdx;

	boardTree * ptr = bt->child;
	
	while (ptr != NULL){
		val[(int)(ptr->spot)] = analyzeTree(ptr, p);
		ptr = ptr->next;
	}
	
	// get the index with the maximum value;
	maxIdx = 0;
	int i;
	for (i = 1; i < ROWS*COLUMNS; i++){
		if (val[i] > val[(int)maxIdx]) maxIdx = i;
	}
	return maxIdx;
	
}

boardTree * buildTree(boardTree * r, char player){
	int i;
	boardTree * p = r->child;

	if (getWinner(r->b) != EMPTY) return r;

	// first populate this node with all possible children
	for (i = 1; i <= (ROWS*COLUMNS); i++){

		if (available(i)){
			// if the spot is available,
			// create a new boardTree with the same board plus the extra piece
			if(r->child = NULL) {
				r->child = newNode(r->b, i, switchPlayer(player), 0);
				p = r->child;
			}
			else{
				p->next = newNode(r->b, i, switchPlayer(player), 0);
				p = p->next;
			}
			p->b = addPiece(p->b, i, player);
			
		}
	}
	// We should now have r->child pointing to the first element in a linked-list
	// of boardTrees--each with a piece placed in the next available spot.
		
	// Now delve into each child and populate their trees
	p = r->child; // set p to point to the first element in the list
	while (p != NULL){
		if (numSpacesLeft(p->b) == 0) {
			p = p->next;
			continue;
		}
		p = buildTree(p, p->player);
		p = p->next;
	}
	return r;

}
/*

boardTree * newNode(tttBoard * b, char spot, char player, char depth, char winCount){
	bt = (boardTree *)malloc(sizeof(boardTree));
	if (bt == NULL) exit(1);
	
	// initialize everything in bt
	&(bt->b) = &(b);
	bt->next = NULL;
	bt->child = NULL;
	bt->spot = spot;
	bt->player = player;
	bt->depth = depth;
	char wincCount = 0;

}

char analyzeTree(boardTree * b, char player){
	char count = 0;
	p = b;

	if (b == NULL) return 0;
	while (p != NULL){
		char w = getWinner(b->b);
		if (w == EMPTY){
			count+=analyzeTree(p, player);
		}
		else if (w == player){
			count+=(10-numSpacesLeft(p->b))*1;
		}
		else {
			count+=(10-numSpacesLeft(p->b))*-1;
		}
		p = p->next;
	}
	return count;
}

char freeTree(boardTree * b){

	// go to the bottom (no children)
	if (b->child != NULL){
		freeTree(b->child);
	}
	// once b's children are freed, we must free everything else in b's list
	// recursively to free their children and subsequent lists too.

	if (b->next != NULL){
		freeTree(b->next);
	}
	// now that everything else in the list has been cleared along with b's children,
	// we can free be and return
	
	free(b);
	return;

}*/
