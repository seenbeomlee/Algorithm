#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

// 1 2 3 4 , 1 4 2 3 .. 은 같이 존재하면 안됨 -> arr[i] > arr[i-1] 이게끔 로직을 돌면 된다.

// void find(int depth, vector<int> arr) 이러면, 자바에서 배열 넘길때같이 깊은 복사
// 아래와 같이 해야 얕은복사 (포인터로, 함수가 호출된 시점의 arr도 같이 값 변경)
void find(int depth, vector<int>& arr) {
  if(depth + 1 == M) {
    for(int i = 0; i <= depth; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  depth++;
  //for(int i = 1; i <= N; i++) cout << "check" << i << ": " << check[i] << endl;
  for(int i = arr[0]; i <= N; i++) {
    bool is = false;

    if(i <= arr[depth-1]) is = true;

    if(!is) {
      arr[depth] = i;
      find(depth, arr);
    }
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