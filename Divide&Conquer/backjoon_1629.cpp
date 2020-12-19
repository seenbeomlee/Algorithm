#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

// 10 11 12
// 4

long long find(long long N, long long M, long long K) {
  if(M == 1) return N % K;
  else {
    if(M % 2 == 0) {
      long long half = find(N, M/2, K);
      return half * half % K;
    } else {
      return (N * (find(N, M-1, K) % K)) % K;
    }
  }
}

int main() {
  long long N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);

  printf("%lld", find(N, M, K));
}
