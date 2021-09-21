#include <iostream>
using namespace std;
#define N 24 //change N to number of queens to test



/* Solve the N Queens problem using the backtracking technique */

//Function for printing the  after the technique is performed
void printBoard(int board[N][N]) {
  for (int i=0; i < N; i++) {
    for (int j=0; j < N; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

/*
Function for confirming if a queen can be placed on the board
without conflicting with another queen

Function runs in O(n) for each "for" loop and overall
*/

bool checkIfQueenIsValid(int board[N][N], int row, int col) {
  for (int i = 0; i < col; i++)  //check row on left
    if (board[row][i])
      return false;

  for (int i=row, j=col; i>=0 && j>=0; i--,j--)  //check upper diagonal
    if (board[i][j])
      return false;

  for (int i=row, j=col; j>=0 && i<N; i++,j--)   //check lower diagonal
    if (board[i][j])
      return false;

  return true;
}

bool solveNQueen(int board[N][N], int col) {
  if (col >= N)     //base case for when all queens have been placed
    return true;

  for (int i=0; i < N; i++) {   //start from leftmost column
    if (checkIfQueenIsValid(board, i, col)) {   //verify if the queen can be placed here without clashing
      board[i][col] = 1;        //if true, mark this spot on the matrix with a 1
      if (solveNQueen(board,col+1))  //use recursion to move to the next column
        return true;
      board[i][col] = 0;        //backtrack if solution is not found
    }
  }
  return false;   //if no queens can be placed in this column
}

bool checkSolution() {

  int board[N][N];
  for (int i=0; i<N;i++)
  for (int j=0; j<N;j++)
  board[i][j] = 0;
  if(solveNQueen(board, 0) == false) {
    cout << N << "x" << N << " ";
    cout << "N-queen solution does not exist";
    return false;
  }
  printBoard(board);

  return true;
}


int main() {
  checkSolution();
  return 0;
}
