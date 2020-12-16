#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;
int minn = 1000000000;

void findMin(int** board, vector<int> A) {
  int totalA = 0;
  int totalB = 0;
  
  vector<int> B;
  for(int i = 0; i < N; i++) {
    bool is = false;
    for(int j = 0; j < A.size(); j++) {
      if(i == A[j]) {
        is = true;
        break;
      }
    }
    if(!is) {
      B.push_back(i);
    }
  }

  for(int i = 0; i < A.size() - 1; i++) {
    for(int j = i; j < N; j++) {
      totalA = totalA + board[A[i]][A[j]] + board[A[j]][A[i]];
      totalB = totalB + board[B[i]][B[j]] + board[B[j]][B[i]];
    }
  }

  minn = min(minn, abs(totalA - totalB));
}

void find(int** board, vector<int> A) {
  if(A.size() == N / 2) {
    //for(int i = 0; i < N / 2; i++) cout << A[i] << endl;
    findMin(board, A);

    return;
  }

  for(int i = A[0] + 1; i < N; i++) {
    A.push_back(i);
    find(board, A);
    A.pop_back();
  }
}

int main() {
  scanf("%d", &N);

  int** board = new int*[N];
  for(int i = 0; i < N; i++) {
    board[i] = new int[M];
  }

  for(int i = 0 ; i < N; i++) {
    for(int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  vector<int> A;
  for(int i = 0; i < N; i++) {
    A.push_back(i);
    find(board, A);
    A.pop_back();
  }

  printf("%d", minn);
}