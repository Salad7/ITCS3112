#include <iostream>

using namespace std;

void draw (char* ttt);
void playTicTacToe(char *ttt);
bool gameComplete (char *ttt);
bool checkIfThrees (char *ttt,int a,int  b, int c);
bool checkIfWinner (char *ttt);



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
    int spots = 0;
    int validMoves = 0;
    //Loop through 
    while(!checkIfWinner(ttt) && spots < 9){
         int num;
        if(i % 2 == 0){
        cout << "Player 1's turn, where would you like to place X (0-8)? " << endl;
        cin >> num;
        }
        else{
        cout << "Player 2's turn, where would you like to place 0 (0-8)? " << endl;
        cin >> num;
        }
        if(num > -1 && num < 9  && ttt[num] == '-' ){
            if(i % 2 == 0){
                ttt[num] = 'X';
            }
            else{
                 ttt[num] = '0';

            }
			        
			        draw(ttt);
			        //if(checkIfWinner(ttt)){
			            //break;
			           
			        //}
			        spots++;
        }
        else{
            cout << " You lost your turn for entering number out range! or entering a postion thats already taken " << num << " ";
        }
        i++;
         if(spots == 9){
    cout << "Game ended in a tie" << endl;
    break;
    }
}
    //Check if value is between 1-9
    //Check if there isn't already a spot there, if there is u lose your turn
    //Check if user has won
   

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
    if(ttt[a] == ttt[b] && ttt[b] == ttt[c] && ttt[a] != '-' && ttt[b] != '-' && ttt[c] != '-'){
        
        //cout << "true";
        //if(checkIfWinner(ttt)){
			    cout <<"Player " << ttt[a] << " wins" << endl;
		//	}
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
}


// This function determines if the game has ended - either a row, column or
// a diagonal should be filled with the same character for it to be complete.
bool gameComplete(char *ttt) {
}
