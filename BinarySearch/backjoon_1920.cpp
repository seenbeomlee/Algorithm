#include <cstdio>

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

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

  for(int i = 0; i < checkList.size(); i++){
    if(binary_search(inputList.begin(), inputList.end(), checkList[i]))
      printf("1\n");
    else printf("0\n");
  }  
}