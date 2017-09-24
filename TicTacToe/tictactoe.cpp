#include <iostream>

using namespace std;

void draw (char* ttt);
void playTicTacToe(char *ttt);
bool gameComplete (char *ttt);
bool checkIfThrees (char *ttt,int a,int  b, int c);



int main() {

					// define an array of 9 elements to hold the characters
					// in your tic-tac-toe square; assume a default character
					// like '-' or something
	char tic_tac_toe[9] = {'-','-','-','-','-','-','-','-','-'};

					// draw the array
	draw(&tic_tac_toe[0]);

	playTicTacToe(&tic_tac_toe[0]);	
    //char winner;
	return 0;
}

void playTicTacToe (char *ttt) {
    //variable that keeps track of whose turn it is
    int i = 0;
    //Keeps tract of number of legit moves made by user
    int spots = 0;
    
    //While a winner is not found and spots is less than 9
    while(!gameComplete(ttt) && spots < 9){
         //variable that keeps track ot the position the user enters
         int num;
         
         //If i % 2 is even, it's players ones turn
        if(i % 2 == 0){
        cout << "Player 1's turn, where would you like to place X (0-8)? " << endl;
        //get the user input of player one and store it in num
        cin >> num;
        }
        //otherwise it's players 2s turn
        else{
        cout << "Player 2's turn, where would you like to place 0 (0-8)? " << endl;        
        //get the user input of player one and store it in num
        cin >> num;
        }
        //Make sure the number is in the range of X and O
        if(num > -1 && num < 9  && ttt[num] == '-' ){
            //if it's user ones turn
            if(i % 2 == 0){
                //place X in the num
                ttt[num] = 'X';
            }
            else{
                 //place X in the num
                 ttt[num] = '0';

            }
			        //Update the Board
			        draw(ttt);
			        //Increase valid spots
			        spots++;
        }
        else{
            cout << " You lost your turn for entering number out range! or entering a postion thats already taken " << num << " ";
        }
        i++;
        //If there have been 9 moves, the game has ended in a tie
         if(spots == 9){
    cout << "Game ended in a tie" << endl;
    break;
    }
}
    //Check if value is between 1-9
    //Check if there isn't already a spot there, if there is u lose your turn
    //Check if user has won
   

}

//Bool method that checks if the board at certain postions all match the same letter


bool checkIfThrees(char* ttt, int a, int b, int c){
    //If 3 chars are all the same and the chars are not a dash, return true;
    if(ttt[a] == ttt[b] && ttt[b] == ttt[c] && ttt[a] != '-' && ttt[b] != '-' && ttt[c] != '-'){
        
			    cout <<"Player " << ttt[a] << " wins" << endl;
        return true;
    }
    return false;
}

// This function draws the tic-tac-toe square after each move
void draw(char *ttt) {
    //Update the board
	for (int k = 0; k < 9; k++) {
	    cout << " " << ttt[k];
	    if ((k+1) % 3 == 0 && k != 0){
	        cout << endl;
	    }
	}
cout << endl;
}

//Bool method that checks if the board at certain postions all match the same letter
// This function determines if the game has ended - either a row, column or
// a diagonal should be filled with the same character for it to be complete.
bool gameComplete(char *ttt) {
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
