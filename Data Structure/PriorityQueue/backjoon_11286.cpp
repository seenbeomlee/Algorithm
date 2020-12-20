#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N;
// reference : https://wordbe.tistory.com/entry/STL-priorityqueue (절댓값 힙)

class Compare
{
public:
  bool operator()(const int &A, const int &B)
  {
    if (abs(A) == abs(B))
      return A > B;
    else
      return abs(A) > abs(B);
  }
};

int main()
{
  scanf("%d", &N);

  priority_queue<int, vector<int>, Compare> pq;
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