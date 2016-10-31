#include <stdio.h>
#include "ttt.h"
#include "ttt.c"

int main(int argc, char ** argv){
	tttBoard * b = buildBoard();
	char player = X;
	char pos;

	while (getWinner(b) == EMPTY && numSpacesLeft(b) > 0){

		player = switchPlayers(player);
		// give some spacing between printing boards
		printf("\n\n\n\n\n\n\n");
		printBoard(b);
		printf("Where would you like to go, %c?\n", (player == X)?'X':'O');
		pos = readInput();
		while (!available(pos, b)){
			printf("That spot is not available, please enter another one\n");
			pos = readInput();
		}
		
		b = addPiece(b, pos,player);
	}

	printBoard(b);
	if (getWinner(b) != EMPTY)
		printf("Contratulations, %c, you won!\n", player==X?'X':'O');
	else printf("TIE\n");

	free(b);
	return 0;
}