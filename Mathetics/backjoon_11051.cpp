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

  if(M == 1) {
    cout << 1;
    return 0;
  }

  long NF = 1;
  long KF = 1;
  long QF = 1;

  for(int i = 1; i <= N; i++) NF = NF * i % 10007;
  for(int i = 1; i <= M; i++) KF = KF * i % 10007;
  for(int i = 1; i <= Q; i++) QF = QF * i % 10007;

  int q = (KF * QF) % 10007;

  if(NF >= q) NF /= q;

  cout << NF % 10007;
} 