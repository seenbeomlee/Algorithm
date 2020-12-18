#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  cin >> N >> M;

  int maxx = 1;
  int minn = 100000;

  int small = min(N, M);
  int big = max(N, M);
  for(int i = 1; ; i++) {
    int temp = small * i;
    if(temp % big == 0) {
      minn = temp;
      break;
    }
  }

  int i = 2;
  while(1) {
    if(N % i == 0 && M % i == 0) {
      maxx *= i;
      N /= i;
      M /= i;
    } else i++;

    if(i > N || i > M) break;
  }

  cout << maxx << endl;
  cout << minn << endl;
} 