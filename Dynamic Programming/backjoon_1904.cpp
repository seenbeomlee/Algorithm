#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

// 1 or 00
int N, M;
int dp[1000001];

int find(int N) {
  if(N == 1) return dp[1];
  if(N == 2) return dp[2];
  if(dp[N] != 0) return dp[N];

  else {
    dp[N] = (find(N-1) + find(N-2)) % 15746;
    return dp[N];
  }
}

int main() {
    scanf("%d", &N);

    dp[1] = 1;
    dp[2] = 2;
    int res = find(N);

    printf("%d", res);
}