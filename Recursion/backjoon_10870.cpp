#include <iostream>

using namespace std;

int fibo(int N);

int main() {
  int N;
  cin >> N;

  int res = fibo(N);

  cout << res;
}

int fibo(int N) {
  if(N == 0) return 0;
  if(N == 1) return 1;

  return fibo(N-1) + fibo(N-2);
}