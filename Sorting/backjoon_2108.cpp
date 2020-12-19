#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

int main() {
  scanf("%d", &N);
  int* arr = new int[N];
  int* count = new int[8001];
  // 0 1~4000 -1~-4000

  double total = 0;
  int minn = 4001;
  int maxx = -4001;

  int ff = 0;
  vector<int> ffList;

  for(int i = 0; i < N; i++) {
    scanf("%d", &M);

    arr[i] = M;

    minn = min(minn, M);
    maxx = max(maxx, M);
    total += M;

    if(M < 0) {
      M *= -1;
      M += 4000;
    }
    count[M]++;
  }

  for(int i = 0; i < 8001; i++) {
    if(count[i] > ff) {
      ffList.clear();
      ff = count[i];
      if(i > 4000) {
        int qq = i;
        qq -= 4000;
        qq *= -1;
        ffList.push_back(qq);
      } else ffList.push_back(i);
    } else if (count[i] == ff) {
      if(i > 4000) {
        int qq = i;
        qq -= 4000;
        qq *= -1;
        ffList.push_back(qq);
      } else ffList.push_back(i);
    } else continue;
  }

  sort(arr, arr+N);
  sort(ffList.begin(), ffList.end());

  int ffRes = 0;
  if(ffList.size() == 1) ffRes = ffList[0];
  else ffRes = ffList[1];

  cout << (int)floor((total / N + 0.5)) << endl;
  cout << arr[N/2] << endl;
  cout << ffRes << endl;
  cout << maxx - minn << endl;
}