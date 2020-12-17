#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

// 1 or 00
int N, M;
int dp[100000];

int main() {
    long A = 1; // 0, 9
    long B = 2; // 1, 8
    long C = 2; // 2, 7
    long D = 2; // 3, 6
    long E = 2; // 4, 5

    long nextA;
    long nextB;
    long nextC;
    long nextD;
    long nextE;

    scanf("%d", &N);
    for(int i = 1; i < N; i++) {
      nextA = B;
      nextB = A + C;
      nextC = B + D;
      nextD = C + E;
      nextE = D + E;

      A = nextA % 1000000000;
      B = nextB % 1000000000;
      C = nextC % 1000000000;
      D = nextD % 1000000000;
      E = nextE % 1000000000;
    }
    printf("%ld", (A + B + C + D + E) % 1000000000);
}