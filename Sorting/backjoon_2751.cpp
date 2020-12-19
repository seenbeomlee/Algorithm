#include <cstdio>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;

int main() {
  scanf("%d", &M);

  vector<int> list;
  char trash;

  for(int i = 0; i < M; i++) {
    scanf("%d", &N);

    list.push_back(N);
  }

  sort(list.begin(), list.end()); // N * logN

  for(vector<int>::iterator iter = list.begin(); iter != list.end(); iter++) {
    printf("%d\n", *iter);
  }
}