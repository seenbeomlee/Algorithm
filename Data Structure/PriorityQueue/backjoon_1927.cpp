#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N;

// max-heap & min-heap : https://breakcoding.tistory.com/123

int main()
{
  scanf("%d", &N);

  priority_queue<int, vector<int>, greater<int>> pq;
  int input;
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &input);

    if (input == 0)
    {
      if (pq.empty())
        printf("0\n");
      else
      {
        printf("%d\n", pq.top());
        pq.pop();
      }
    }
    else
    {
      pq.push(input);
    }
  }
}