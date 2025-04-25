#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "tic_tac_toe a.h" 

#define HUMAN_X 'X'
#define HUMAN_O 'O'

int main() {
	int size;
	printf("Tic-Tac-Toe\n\n"); //Display welcome message 
	printf("Enter the Tic Tac Toe board size (3 < N < 10): "); //user to enter the Board size
    scanf("%d", &size);
    
    //Allocate memory for the Tic Tac Toe baord using the initializeBoard function
    char** board = initializeBoard(size);
    
    //calls the writeOnTextFile with the initial state of the board to a text file
    writeOnTextFile(size, board);
    
    if (size > 3 && size < 10) { //checks the board size is within a valid range  4 - 9
    	playTicTacToe(size);
	} 
	else {
		printf("Invalid board size.Please enter a board size between '4 and 9'\n");	
	}
	
	//Free the board allocated memory for the board
	freeBoard(board, size);
	return 0;
}
 //IT23231528 R.M.Chamudi Sashanka Rathnayaka 
