#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  scanf("%d", &N);

  int* arr = new int[N];

  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);

  vector<int> LIS;
  LIS.push_back(arr[0]);
  for(int i = 1; i < N; i++) {
    if(arr[i] > LIS[LIS.size()-1]) LIS.push_back(arr[i]);
    else {
      for(int j = 0; j < LIS.size(); j++) {
        if(j == 0 && arr[i] < LIS[0]) LIS[0] = arr[i];
        if(j > 0 && arr[i] > LIS[j-1] && arr[i] < LIS[j]) {
          LIS[j] = arr[i];
          break;
        }
      }
    }
  }

  printf("%d", (int)LIS.size());
}