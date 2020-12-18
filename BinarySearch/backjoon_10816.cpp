#include <cstdio>

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

long long res;

void binaryLogic(vector<long long> inputList, long long check, long long s, long long e) {
  long long middle = (e + s) / 2;

  if(s > e) { // end-point
    //cout << "check1: " << check << endl;
    if(inputList[s] == check) res++;
    return;
  }

  if(inputList[middle] == check) {
    //cout << "check2: " << check << endl;
    res++;
    //left
    long long idx = middle - 1;
    while(1) {
      if(idx < 0 || inputList[idx] != check) break;
      res++;
      idx--;
    }
    //right
    idx = middle + 1;
    while(1) {
      if(idx >= inputList.size() || inputList[idx] != check) break;
      res++;
      idx++;
    }
  } else if (inputList[middle] > check) {
    binaryLogic(inputList, check, s, middle - 1);
  } else {
    binaryLogic(inputList, check, middle + 1, e);
  }
}

int main() {
  long long N, M;
  long long temp;

  scanf("%lld", &N);
  vector<long long> inputList;
  for(int i = 0; i < N; i++) {
    scanf("%lld", &temp);
    inputList.push_back(temp);
  }

  scanf("%lld", &M);
  vector<long long> checkList;
  for(int i = 0; i < M; i++) {
    scanf("%lld", &temp);
    checkList.push_back(temp);
  }

  sort(inputList.begin(), inputList.end());

  //binarySearch Logic
  for(int i = 0; i < M; i++) {
    res = 0;
    binaryLogic(inputList, checkList[i], 0, M - 1);
    printf("%lld ", res);
  }
}