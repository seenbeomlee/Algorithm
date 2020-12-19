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
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());

  cout << *arr.begin() * *(arr.end()-1);
} 