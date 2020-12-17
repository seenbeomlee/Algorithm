#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

// 1 or 00
int N, M;
long dp[10001];

int main() {
  scanf("%d", &N);

  int* value = new int[N];
  for(int i = 0; i < N; i++) scanf("%d", &value[i]);

  dp[0] = value[0];
  dp[1] = value[0] + value[1];
  dp[2] = max(value[0] + value[2], value[1] + value[2]);

  long res = max(dp[1], dp[2]);
  long semiMax = dp[0];
  for(int i = 3; i < N; i++) {
    semiMax = max(semiMax, dp[i-3]);
    dp[i] = max(dp[i-2] + value[i], semiMax + value[i-1] + value[i]);
    res = max(res, dp[i]);
  }

  printf("%ld", res);
}