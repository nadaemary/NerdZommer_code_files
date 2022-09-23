#include <cstdlib>              // system definitions
#include <iostream>             // I/O definitions
using namespace std;            // make std:: accessible

const int X = 1, O = -1, EMPTY = 0;  // possible marks
int board[3][3];                     // playing board
int currentPlayer;                   // current plaryer

void clearBoard() {
  for (int i = 0; i< 3; i++){
    for (int j =0; j < 3; j++){
      board[i][j] = EMPTY;
    }
  }
  currentPlayer = X;
}

void inputMark(int i, int j){
  board[i][j] = currentPlayer;
  currentPlayer = -currentPlayer;
}

bool isWin(int mark) {                             // is mark the winner
  int win = 3*mark;                               // +3 for X and -3 for O
  return ((board[0][0] + board[0][1] + board[0][2] == win) // row 0
|| (board[1][0] + board[1][1] + board[1][2] == win) // row 1
|| (board[2][0] + board[2][1] + board[2][2] == win) // row 2
|| (board[0][0] + board[1][0] + board[2][0] == win) // column 0
|| (board[0][1] + board[1][1] + board[2][1] == win) // column 1
|| (board[0][2] + board[1][2] + board[2][2] == win) // column 2
|| (board[0][0] + board[1][1] + board[2][2] == win) // diagonal
|| (board[2][0] + board[1][1] + board[0][2] == win) // diagonal
);
}

void getWinner() {
  if (isWin(X)) cout<<"Player X won"<< endl;
  else if (isWin(O)) cout<<"Player O won"<< endl;
  else cout<<"Tie"<< endl;
}

void printBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      switch (board[i][j]) {
        case X: cout<< "X"; break;
        case O: cout<< "O"; break;
        case EMPTY: cout<< " "; break;
      }
      if (j < 2) cout<< "|";
    }
    if (i < 2) cout<< "\n-+-+-\n";
  }
  cout<<endl;
}

int main() {
  clearBoard();
  inputMark(0,0);
  inputMark(1,1);
  inputMark(0,1);
  inputMark(0,2);
  inputMark(2,0);
  inputMark(1,2);
  inputMark(2,2);
  inputMark(2,1);
  inputMark(1,0);
  printBoard();
  getWinner();
}
