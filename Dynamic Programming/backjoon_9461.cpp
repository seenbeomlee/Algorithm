#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

// 1 or 00
int N, M;
long dp[1000001];

long find(int N) {
  if(N < 6) return dp[N];
  if(dp[N] != 0) return dp[N];

  else {
    dp[N] = (find(N-1) + find(N-5));
    return dp[N];
  }
}

int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &M);
      long res = find(M);
      printf("%ld\n", res);
    }
}