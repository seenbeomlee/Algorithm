#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  cin >> N;

  vector<int> arr;
  int tmp;
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }

  sort(arr.begin(), arr.end());

  for(int i = 2; i < arr[N-1]; i++) {
    bool is = false;
    int n = arr[0] % i;
    for(int j = 1; j < N; j++) {
      if(arr[j] % i != n) {
        is = true;
        break;
      }
    }
    if(!is) cout << i << " ";
  }
} 