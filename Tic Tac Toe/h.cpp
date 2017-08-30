#include <iostream>

using namespace std;

void draw (char* ttt);
void playTicTacToe(char *ttt);
bool gameComplete (char *ttt);

int main() {

					// define an array of 9 elements to hold the characters
					// in your tic-tac-toe square; assume a default character
					// like '-' or something
	char tic_tac_toe[9] = {'-','-','-','-','-','-','-','-','-'};
	
	//char ttt[9] = tic_tac_toe;

					// draw the array
	draw(&tic_tac_toe[0]);

	playTicTacToe(&tic_tac_toe[0]);	

	return 0;
}

void playTicTacToe (char *ttt) {
    //cout 
			// this function contains  the game logic
			// assume a move by player A, followed by player B
			// after each move, you must check if the respective player
			// has won, in which case the game is complete; use a separate
			// function to accomplish this.

			// players will enter the position where they want to enter in
			// the tic-tac-toe square. Assume the numbering from 1 to 9 
			// in row-major order 

			// use cin and cout for input and output

}

// This function draws the tic-tac-toe square after each move
void draw(char *ttt) {
	for (int k = 0; k < 9; k++) {
	    cout << " " << ttt[k];
	    if ((k+1) % 3 == 0 && k != 0){
	        cout << endl;
	    }
	}
}


// This function determines if the game has ended - either a row, column or
// a diagonal should be filled with the same character for it to be complete.

bool gameComplete(char *ttt) {
}
