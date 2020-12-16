#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

void find(int depth, int* arr) {
  if(depth + 1 == M) {
    for(int i = 0; i <= depth; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  depth++;
  for(int i = 1; i <= N; i++) {
    bool is = false;
    for(int j = 0; j < depth; j++) {
      if(i == arr[j]) {
        is = true;
        break;
      }
    }
    if(!is) {
      //printf("is: %d\n", i);
      arr[depth] = i;
      find(depth, arr);
    }
  }
}

int main() {
  scanf("%d", &N);
  scanf("%d", &M);

  int* arr = new int[M];
  for(int i = 1; i <= N; i++) {
    arr[0] = i;
    //printf("i: %d\n", i);
    find(0, arr);
  }

}