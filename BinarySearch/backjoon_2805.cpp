#include <cstdio> // printf, scanf

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath>     // floor

using namespace std;

vector<long long> list;
long long answer = 0;
long long N, M;

void find(long long start, long long end)
{
  if (start > end)
  {
    printf("%lld", answer);
    return;
  }

  long long middle = (end + start) / 2;

  long long length = middle;
  long long res = 0;
  for (int j = 0; j < N; j++)
  {
    if (list[j] > length)
      res = res + (list[j] - length);
  }

  if (res >= M)
  {
    answer = max(answer, length);
    find(middle + 1, end);
  }
  else
  {
    find(start, middle - 1);
  }
}

int main()
{
  scanf("%lld %lld", &N, &M);

  long long input;
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &input);
    list.push_back(input);
  }

  sort(list.begin(), list.end());

  find(1, list[N - 1] - 1);
}