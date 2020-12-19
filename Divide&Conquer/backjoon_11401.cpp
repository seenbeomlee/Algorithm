#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor
 
// 1,000,000,007로 나눈 나머지를 출력한다.
// N <= 4,000,000

using namespace std;

// 10 11 12
// 4

int main() {
  long long N, K;
  long long Q;

  scanf("%lld %lld", &N, &K);
  Q = N - K;

  long long NF = 1;
  long long KF = 1;
  long long QF = 1;

  for(int i = 1; i <= N; i++) NF = NF * i % 1000000007;
  for(int i = 1; i <= K; i++) KF = KF * i % 1000000007;
  for(int i = 1; i <= Q; i++) QF = QF * i % 1000000007;

  // cout << NF << endl;
  // cout << KF << endl;
  // cout << QF << endl;

  printf("%lld", NF / ((KF * QF) % 1000000007) % 1000000007);
}
