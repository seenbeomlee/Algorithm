#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N;
int arr[2] = {0, };

// 8
// 1 1 0 0 0 0 1 1
// 1 1 0 0 0 0 1 1
// 0 0 0 0 1 1 0 0
// 0 0 0 0 1 1 0 0
// 1 0 0 0 1 1 1 1
// 0 1 0 0 1 1 1 1
// 0 0 1 1 1 1 1 1
// 0 0 1 1 1 1 1 1

void find(int startRow, int startCol, int length, int** board) {
  //search
  bool search = true;
  int topLeft = board[startRow][startCol];
  for(int i = startRow; i < startRow + length; i++) {
    for(int j = startCol; j < startCol + length; j++) {
      if(board[i][j] != topLeft) {
        search = false;
        break;
      }
    }
    if(!search) break;
  }
  if(search) arr[topLeft]++;
  else {
    find(startRow, startCol, length / 2, board);
    find(startRow, startCol + length / 2,length / 2, board);
    find(startRow + length / 2, startCol, length / 2, board);
    find(startRow + length / 2, startCol + length / 2, length / 2, board);
  }
}

int main() {
  cin >> N;

  int** board = new int*[N];
  for(int i = 0; i < N; i++) board[i] = new int[N];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  //find(startRow, startCol, length, board)
  //search -> W+, B+ -> else find()

  int startRow = 0;
  int startCol = 0;
  int length = N;
  
  find(startRow, startCol, length, board);

  cout << arr[0] << endl;
  cout << arr[1] << endl;
} 