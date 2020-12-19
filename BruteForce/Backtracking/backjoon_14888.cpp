#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;
int minn = 1000000000;
int maxx = -1000000000;

void find(int depth, int value, vector<int> arr, vector<int> ss) {
  depth++;

  if(depth == arr.size()) {
    maxx = max(maxx, value);
    minn = min(minn, value); 
  }

  for(int i = 0; i < 4; i++) {
    switch(i) {
      case 0:
        if(ss[0] != 0) {
          ss[0]--;
          find(depth, value + arr[depth], arr, ss);
          ss[0]++;
          break;
        }
      case 1:
        if(ss[1] != 0) {
          ss[1]--;
          find(depth, value - arr[depth], arr, ss);
          ss[1]++;
          break;
        }
      case 2:
        if(ss[2] != 0) {
          ss[2]--;
          find(depth, value * arr[depth], arr, ss);
          ss[2]++;
          break;
        }
      case 3:
        if(ss[3] != 0) {
          ss[3]--;
          find(depth, value / arr[depth], arr, ss);
          ss[3]++;
          break;
        }
    }
  }
}

int main() {
  scanf("%d", &N);
  
  vector<int> arr;
  vector<int> ss;

  int input;
  for(int i = 0; i < N; i++) {
    scanf("%d", &input);
    arr.push_back(input);
  }

  for(int i = 0; i < 4; i++) {
    scanf("%d", &input);
    ss.push_back(input);
  }

  find(0, arr[0], arr, ss);

  printf("%d\n", maxx);
  printf("%d\n", minn);
}