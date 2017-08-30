#include <iostream>

using namespace std;

void draw (char* ttt);
void playTicTacToe(char *ttt);
bool gameComplete (char *ttt);
bool checkIfThrees (char *ttt,int a,int  b, int c);
bool checkIfWinner (char *ttt);


/*
How games can end with a winner
0,1,2
3,4,5
6,7,8

2,4,6
0,4,8

0,3,6
1,4,7
2,5,8


*/

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
    cout << "Player 1's turn, where would you like to place X (1-9)? " << endl;
    //Check if value is between 1-9
    //Check if there isn't already a spot there, if there is u lose your turn
    //Check if user has won
    
    
			// this function contains  the game logic
			// assume a move by player A, followed by player B
			// after each move, you must check if the respective player
			// has won, in which case the game is complete; use a separate
			// function to accomplish this.

			// players will enter the position where they want to enter in
			// the tic-tac-toe square. Assume the numbering from 1 to 9 
			// in row-major order 

			// use cin and cout for input and output
			ttt[3] = 'X';
			ttt[4] = 'X';
			ttt[5] = 'X';
			draw(ttt);
			if(checkIfWinner(ttt)){
			    cout << "winner";
			}

}

bool checkIfWinner(char* ttt){
// 0,1,2
if(checkIfThrees(ttt,0,1,2)){
    return true;
}
// 3,4,5 
if(checkIfThrees(ttt,3,4,5)){
    return true;
}
// 6,7,8
if(checkIfThrees(ttt,6,7,8)){
    return true;
}
// 2,4,6
if(checkIfThrees(ttt,2,4,6)){
    return true;
}
// 0,4,8
if(checkIfThrees(ttt,0,4,8)){
    return true;
}
// 0,3,6
if(checkIfThrees(ttt,0,3,6)){
    return true;
}
// 1,4,7
if(checkIfThrees(ttt,1,4,7)){
    return true;
}
// 2,5,8
if(checkIfThrees(ttt,2,5,8)){
    return true;
}
return false;
}

bool checkIfThrees(char* ttt, int a, int b, int c){
    if(ttt[a] == ttt[b] && ttt[b] == ttt[c]){
        cout << "true";
        return true;
    }
    return false;
}

// This function draws the tic-tac-toe square after each move
void draw(char *ttt) {
	for (int k = 0; k < 9; k++) {
	    cout << " " << ttt[k];
	    if ((k+1) % 3 == 0 && k != 0){
	        cout << endl;
	    }
	}
cout << endl;
cout << endl;
cout << endl;
}


// This function determines if the game has ended - either a row, column or
// a diagonal should be filled with the same character for it to be complete.

bool gameComplete(char *ttt) {
}
