#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

// 2 <= N <= 200,000
// i2 <= C <= N

int N;
int C;

bool check_possible(int *arr, int dist)
{
  int num = 1;
  int idx = 1;
  int prev_c = arr[0];
  while (idx < N)
  {
    if (arr[idx] - prev_c >= dist)
    {
      prev_c = arr[idx];
      num++;
      idx++;
    }
    else
    {
      idx++;
    }

    if (num >= C)
      return true;
  }
  return false;
}

int main()
{
  scanf("%d %d", &N, &C);

  int *arr = new int[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &arr[i]);
  }

  sort(arr, arr + N);

  int dist_end = arr[N - 1] - arr[0];
  int dist_start = 1;
  int dist_mid = 0;
  int dist_max = 0;

  while (dist_start <= dist_end)
  {
    dist_mid = (dist_end + dist_start) / 2;

    if (check_possible(arr, dist_mid))
    { // if num >= C
      dist_max = max(dist_max, dist_mid);
      dist_start = dist_mid + 1;
    }
    else
    {
      dist_end = dist_mid - 1;
    }
  }

  printf("%d", dist_max);
}