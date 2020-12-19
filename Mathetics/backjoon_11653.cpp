#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  cin >> N;

  int now = 2;
  while(N > 1) {
    if(N % now == 0) {
      cout << now << endl;
      N /= now;
    } else {
      now++;
    }
  }
} 