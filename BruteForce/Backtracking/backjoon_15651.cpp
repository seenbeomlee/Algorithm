#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

void find(int depth, vector<int> arr) {
  if(depth + 1 == M) {
    for(int i = 0; i <= depth; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  depth++;
  for(int i = 1; i <= N; i++) {
    arr[depth] = i;
    find(depth, arr);
  }
}

int main() {
  scanf("%d", &N);
  scanf("%d", &M);

  for(int i = 1; i <= N; i++) {
    vector<int> arr(M, 0); // vector에 M개의 0을 할당
    arr[0] = i;
    find(0, arr);
  }

}