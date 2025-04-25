#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HUMAN_X 'X'
#define HUMAN_O 'O'

void showBoard(char **board, int size);
void showInstructions(int size);
int rowCrossed(char **board, int size, char player);
int columnCrossed(char **board, int size, char player);
int diagonalCrossed(char **board, int size, char player);
int gameOver(char **board, int size, char player);
char** initializeBoard(int size);
void freeBoard(char **board, int size);
void playTicTacToe(int size);
void writeOnTextFile(int size, char **board);

void showBoard(char **board, int size) {
	printf("\n\n");
	for (int i = 0; i < size; i++){
		for ( int j = 0; j < size; j++) { //The board's rows and columns are cycled through twice using loops 
		int cellNumber = i * size + j + 1; //Calculates the cell number based on the current row and column
		printf("\t");
		
		if (board[i][j] == ' ') { //Checks if the current cell is empty (' ')
			printf("%d", cellNumber); //If current cell is empty , prints the cell number
		} else {
			printf("%c", board[i][j]); //prints the player symbol ('X' or 'O')
		}
	
	if (j < size - 1){
		printf("|"); //print a vertical bar (|) between cell if the current cell is not the last in therow
	}
	}
	printf("\n");
	
	if (i < size -1) {
		for ( int k = 0; k < size; k++) { //this loop is responsible for printing the horizontal line between row
			printf("--------"); 
		}
		printf("\n");
		}
	}
	printf("\n");
}

void showInstructions(int size){
	printf("\nChoose a cell number from 1 to %d as below""and play\n\n", size * size);
	
	for (int i = 0, count = 1; i < size; i++){ ///outer loop iterates over each row of the board
		for (int j = 0; j < size; j++, count++){  //inner loop iterates over each column of the board
			printf("\t%d", count); // print the current cell number 
			if (j < size - 1){ //print a vertical bar (|) after each cell except the last one in a row 
				printf("|");
			}
		}
		printf("\n"); //moves to the next line after printing all cell in a row 
		if (i < size -1) {
			for ( int k = 0; k < size; k++) { /* print a horizontal line between rows*/
			printf("--------");	                 
			}
			printf("\n"); //move to the next line after printing the horizontal line
		}
	}
	printf("\n"); //print the additional newline  after completing the board display
	}
	
int rowCrossed(char **board, int size, char player){ // takes 2D array(board)
	for ( int i = 0; i < size; i++) { //loop through each row of the board
		int count = 0; //initialize a counter to 0 for each row to count the occurrences of the player's symbol
		for ( int j = 0; j < size; j++) { //loop through each column of the board
			if (board[i][j] == player) { 
		        count++; // if the current cell in the row contains the playerr's symbol increment the counter 
			}
		}
		if (count == size) { // if counter equals the size of the row
			return 1; // it means the entir row is filled with the player's symbol.return 1
		}
   	}
   	return 0; //if no row is found where all cells are filled with the player's symbol then return 0
}	
	
int columnCrossed(char **board, int size, char player){
	for ( int i = 0; i < size; i++) { //loop through each column of the board
		int count = 0; //initialize a counter to 0 for each column to count the occurrences of the player's symbol
		for ( int j = 0; j < size; j++) { //loop through each row of the board
			 if (board[j][i] == player) {   
					count++; // if the current cell in the column contains the playerr's symbol increment the counter
				}
			}
			if (count == size) { // if counter equals the size of the column
				return 1; //it means the entir column is filled with the player's symbol.return 1
	    	}
		}
		return 0; //if no column is found where all cells are filled with the player's symbol then return 0
   }

int diagonalCrossed(char **board, int size, char player){
	int count = 0; //initialize a counter to 0 to count the occurrences of the player's symbol in each diagonal
	for ( int i = 0; i < size; i++) { //check the main diagonal (top -left to bottom -right
		 if (board[i][i] == player) { // if the current cell in the main diagonal contains the playerr's symbol increment the counter
					count++;
		    	}
		    }
		    if (count == size) { //if the counter equals the size of the diagonal 
		    	return 1; //it means the entir main diagonal is filled with the player's symbol.return 1
			}
			
			count = 0; // reset the counter for the other diagonal
			for ( int i = 0; i < size; i++) { //check the main diagonal (top -right  to bottom -left
			if (board[i][size - 1 -i] == player){ // if the current cell in the other diagonal contains the player's symbol and increment it 
				count++;
			}
		}
	    return (count == size); //return whether the entire other diagonal is filled with the player's symbol 
    }

int gameOver(char **board, int size, char player){
	return (rowCrossed(board, size, player) || columnCrossed(board, size, player)|| diagonalCrossed(board, size, player));
//checks the player has achieved victory in any row ,column, diagonal 
}

char** initializeBoard(int size) {
	char**board = (char**)malloc(size * sizeof(char*)); // allocate memory for an array of size pointers to char
	for (int i = 0; i < size; i++){ //to iterate over each  row of the 2d array
		board[i] = (char*)malloc(size * sizeof(char)); //board[i] now points to the memory block for the row 
		for (int j =0; j < size; j++) { // to iterate over each column of the current row
			board[i][j] = ' '; // initialize each character in the array to a space ('')
		}
	}
	return board; // return the pointer to the allocated memory 
}

void freeBoard(char **board, int size) {
	for (int i = 0; i < size; i++) { // iterate over each row of the 2D array
		free(board[i]); //free the memory allocated for each row 
	}
	free(board); //Free the memory allocated for the array of pointers( row )
}

void playTicTacToe(int size) {
	char** board = initializeBoard(size); // alocate memory for tht tic tac toe board
	int moves[size * size]; // creat and array to store moves from 1 to size*size
	
	for (int i = 0; i < size * size; i++) { //initialize the moves array with value from 1 to size*size
		moves[i] = i + 1;
	}
	
	for (int i = 0; i < size * size; i++){  // randomizes the other of possible moves 
		int randIndex = rand() % (size * size);
		int temp = moves[i];
		moves[i] = moves[randIndex];
		moves[randIndex] = temp;
	}
	
showInstructions(size);

int moveIndex = 0, x, y;
char currentPlayer = HUMAN_X;

while (!gameOver(board, size, HUMAN_X) && !gameOver(board, size, HUMAN_O) && moveIndex != size * size) { // total number of moves is less than the size of the board squarded
	printf("Player %c,Enter your move (1-%d): ", currentPlayer, size * size); // input from the user and present chosen cell number
	int move;
	scanf("%d", &move); //stored in the variable move 
	
	if (move < 1 || move > size * size || board[(move - 1) / size][(move - 1) % size] != ' ') { //check the if the entered move is valid, move is within the vaild range and chosen ceell is not already occupied
		printf("\n'Invalid input!Please enter a valid move'\n\n");
		continue;
	}
	
	x = (move - 1) / size; 
	y = (move - 1 ) % size; // calcuates the corresponding row (x) and column (y) indices based on the entered move number  
	board[x][y] = currentPlayer; //updates the current player's symbol
	
	showBoard(board, size); // displays the updated board 
	moveIndex++;
	
	if (gameOver(board, size, currentPlayer)) {
		printf("'Player %c has won!!'\n", currentPlayer);
		freeBoard(board, size); // check the current players has won the game 
		return;
	}

currentPlayer = (currentPlayer == HUMAN_X) ? HUMAN_O : HUMAN_X; // switches the current players 
}

if (!gameOver(board, size, HUMAN_X) && !gameOver(board, size, HUMAN_O) && moveIndex == size * size) {
//check if the game is not over for the (x) also (Y) and total number of moves is equal to the size of the board squared
	printf("It's a draw!\n"); 
}

freeBoard(board, size);
}
void writeOnTextFile(int size, char **board) {
	
	FILE *file;
	file = fopen("Tic Tac Toe.text", "a"); //fopen function is used to open a file named 
	// if the file does not exist  ,it will be created
	// if the file already exists ,new data will be appended to the end of it 
	if (file == NULL) { // if the file opening operation was successful , null means there was an issue opening the file .
		printf("Unable to open the file.\n");
		return;
	}
	
	
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			(j < size - 1) ?
			fprintf(file, " %c |", (board[i][j] == 'X' || board[i][j] == 'O') ? board[i][j] : ' ')  
			: //  fprintf function to format the output ,board [i][j] is x or o , print characters ,print spaces , print (|)
			fprintf(file, " %c ", (board[i][j] == 'X' || board[i][j] == 'O') ? board[i][j] : ' ');
		}
		fprintf(file, "\n\n");
	}
	
	fclose(file); // changes are saved and file is relesed 
}

#endif

//IT23231528 R.M.Chamudi Sashanka Rathnayaka 


