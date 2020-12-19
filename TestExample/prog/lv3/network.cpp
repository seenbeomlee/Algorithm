#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

// 1 <= n <= 200
// idx of computers is 0 ~ n-1
int solution(int n, vector<vector<int>> computers)
{
  int answer = 1;

  int *checkList = new int[n]; // if all != 0 -> answer
  for (int i = 0; i < n; i++)
    checkList[i] = 0;

  queue<int> q;
  q.push(0);
  while (1)
  {
    if (q.empty())
    {
      bool finish = true;
      int i;
      for (i = 0; i < n; i++)
      {
        if (checkList[i] == 0)
        {
          finish = false;
          break;
        }
      }
      if (finish)
        break;
      q.push(i);
      answer++;
      checkList[i] = answer;
      continue;
    }

    int now = q.front();
    q.pop();
    // dfs
    for (int i = 0; i < n; i++)
    {
      if (computers[now][i] == 1 && checkList[i] == 0)
      { // i is not visited yet
        checkList[i] = answer;
        q.push(i);
      }
    }
  }

  return answer;
}

int main()
{
  int ans = solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});

  cout << ans;

  return 0;
}