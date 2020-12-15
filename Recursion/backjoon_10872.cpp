#include <iostream>

using namespace std;

int factorial(int N);

int main() {
  int N;
  cin >> N;

  int res = 1;
  for(int i = 1; i < N+1; i++) {
    res *= i;
  }

  cout << res;
}