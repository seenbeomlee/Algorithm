#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int solution(vector<vector<int>> triangle)
{
  int height = triangle.size(); // 5
  int answer = 0;

  for (int i = 1; i < height; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 && i > 0)
      {
        triangle[i][j] += triangle[i - 1][j];
        answer = max(answer, triangle[i][j]);
      }
      else if (j == i && i > 0)
      {
        triangle[i][j] += triangle[i - 1][j - 1];
        answer = max(answer, triangle[i][j]);
      }
      else
      {
        triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        answer = max(answer, triangle[i][j]);
      }
    }
  }

  return answer;
}