// 6 3 2 10 10 10 -10 -10 7 3
// 여기서 10의 개수를 알고싶다? -> upper_bound(10) - lower_bound(10)을 하면 O(NlogN)의 시간 복잡도를 갖는다.

#include <cstdio> // printf, scanf

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

long long res;

int main() {
  long long N, M;
  long long temp;

  scanf("%lld", &N);
  vector<long long> inputList;
  for(int i = 0; i < N; i++) {
    scanf("%lld", &temp);
    inputList.push_back(temp);
  }
  sort(inputList.begin(), inputList.end());

  scanf("%lld", &M);
  for(int i = 0; i < M; i++) {
    res = 0;
    scanf("%lld", &temp);

    vector<long long>::iterator lower_iter = lower_bound(inputList.begin(), inputList.end(), temp);
    vector<long long>::iterator upper_iter = upper_bound(inputList.begin(), inputList.end(), temp);

    //cout << "lower_iter: " << *lower_iter << endl;
    //cout << "upper_iter: " << *upper_iter << endl;

    if(*lower_iter != temp) res = 0;
    else res = upper_iter - lower_iter;
    
    printf("%lld ", res);
  }
}