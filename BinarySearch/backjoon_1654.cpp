#include <cstdio> // printf, scanf

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath>     // floor

using namespace std;
// K  N
// 4 11
// 802  --> 4개
// 743  --> 3개
// 457  --> 2개
// 539  --> 2개

// 200  --> 11개
int K, N;
long long answer = 0;
vector<long long> list;

void find(long long start, long long end)
{
  if (start > end)
  {
    printf("%lld", answer);
    return;
  }

  long long middle = (end + start) / 2;

  long long length = middle;
  int res = 0;
  for (int j = 0; j < K; j++)
  {
    res = res + (list[j] / length);
  }

  if (res >= N)
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
  scanf("%d %d", &K, &N);

  long long input;
  for (int i = 0; i < K; i++)
  {
    scanf("%lld", &input);
    list.push_back(input);
  }

  sort(list.begin(), list.end());
  bool is = false;
  for (long long i = K - 1; i >= 0; i--) // check if answer is between given list[i]
  {
    // length == list[i] -> check
    long long length = list[i];
    int res = 0;
    for (int j = 0; j < K; j++)
    {
      res = res + (list[j] / length);
    }

    if (res >= N)
    {
      is = true;

      answer = max(answer, length);
      find(list[i], list[i + 1] - 1);
      break;
    }
  }

  if (!is) // if not, search length '1' to length 'list[0] -1'
  {
    find(1, list[0] - 1);
  }
}