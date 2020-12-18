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

  int Q = N - M;

  long NF = 1;
  long KF = 1;
  long QF = 1;

  for(int i = 1; i <= N; i++) NF *= i;
  for(int i = 1; i <= M; i++) KF *= i;
  for(int i = 1; i <= Q; i++) QF *= i;

  cout << NF / (KF * QF);
} 