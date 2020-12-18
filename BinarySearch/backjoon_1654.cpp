#include <cstdio> // printf, scanf

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;
// K  N
// 4 11
// 802  --> 4개
// 743  --> 3개
// 457  --> 2개
// 539  --> 2개

// 200  --> 11개
int K, N;

int main() {
  scanf("%d %d", &K, &N);
  vector<long long> list;

  long long input;
  for(int i = 0; i < K; i++) {
    scanf("%lld", &input);
    list.push_back(input);
  }

  sort(list.begin(), list.end());
  long long i = 0;
  bool is = false;
  for(i = K-1; i >= 0; i--) {
    // length == list[i] -> check
    long long length = list[i];
    int res = 0;
    for(int j = 0; j < K; j++) {
      res = res + (list[j] / length);
    }

    if(res >= N) {
      is = true;

      long long j;
      for(j = list[i]; ; j++) {
        int temp = 0;
        for(int k = 0; k < K; k++) {
          temp = temp + (list[k] / j);
        }
        if(temp < N) break;
      }
      printf("%lld", j - 1);
      break;
    }
  }

  if(!is) {
    for(i = list[0]-1; i > 0; i--) {
      int res = 0;
      for(int j = 0; j < K; j++) {
        res = res + (list[j] / i);
      }

      if(res >= N) {
        printf("%lld", i);
        break;
      }
    }
  }
}