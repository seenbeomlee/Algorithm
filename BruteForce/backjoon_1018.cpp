#include <cstdio>
#include <iostream>

using namespace std;

int M, N;

int find(int** board, int row, int col) {
  // int** Wboard = new int*[M];
  // int** Bboard = new int*[M];
  // for(int i = 0; i < M; i++) {
  //   Wboard[i] = new int[N];
  //   Bboard[i] = new int[N];
  // }

  // for(int i = 0; i <= M; i++) {
  //   for(int j = 0; j <= N; j++) {
  //     Wboard[i][j] = board[i][j];
  //     Bboard[i][j] = board[i][j];
  //   }
  // }

  // board[i][j] == white
  int white = 0;
  for(int i = row; i < row + 8; i++) {
    for(int j = col; j < col + 8; j++) {
      if((i % 2 == 0) && (j % 2 == 0)) { // 0 0
        if(board[i][j] != 0) white++;
      } else if((i % 2 == 0) && (j % 2 == 1)) { // 0 1
        if(board[i][j] != 1) white++;
      } else if((i % 2 == 1) && (j % 2 == 0)) { // 1 0
        if(board[i][j] != 1) white++;
      } else { // 1 1
        if(board[i][j] != 0) white++;
      }
    }
  }

  
  // board[i][j] == black
  int black = 0;
  for(int i = row; i < row + 8; i++) {
    for(int j = col; j < col + 8; j++) {
      if((i % 2 == 0) && (j % 2 == 0)) { // 0 0
        if(board[i][j] != 1) black++;
      } else if((i % 2 == 0) && (j % 2 == 1)) { // 0 1
        if(board[i][j] != 0) black++;
      } else if((i % 2 == 1) && (j % 2 == 0)) { // 1 0
        if(board[i][j] != 0) black++;
      } else { // 1 1
        if(board[i][j] != 1) black++;
      }
    }
  }

  return min(white, black);
}

int main() {
  int res = 64;
  //   N --
  // M
  // |
  // |

  scanf("%d %d", &M, &N);
  int** board = new int*[M];
  for(int i = 0; i < M; i++) {
    board[i] = new int[N];
  }

  char** temp = new char*[M];
  for(int i = 0; i < M; i++) {
    temp[i] = new char[N];
  }

  char trash;
  for(int i = 0; i < M; i++) {
    scanf("%c", &trash);
    for(int j = 0; j < N; j++) {
      scanf("%c", &temp[i][j]); 
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(temp[i][j] == 'W') board[i][j] = 0;
      else board[i][j] = 1;
    }
  }

  // W == 0, B == 1
  // cout << M << " " << N << endl;

  // for(int i = 0; i < M; i++) {
  //   for(int j = 0; j < N; j++) {
  //     cout << board[i][j];
  //   }
  //   cout << endl;
  // }

  for(int i = 0; i <= M - 8; i++) {
    for(int j = 0; j <= N - 8; j++) {
      //cout << i << " "  << j << endl;
      res = min(res, find(board, i, j));
    }
  }

  printf("%d", res);
}