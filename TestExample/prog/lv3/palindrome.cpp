#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;
int solution(string s)
{
  int answer = 0;

  for (int i = 0; i < s.length(); i++)
  {
    int Ores = 1;
    int Ares = 0;
    int left = i - 1;
    int right = i + 1;

    while (1)
    {
      if (left < 0 ||
          right >= s.length() ||
          s[left] != s[right])
        break;
      else
      {
        Ores += 2;
        left--;
        right++;
      }
    }

    left = i;
    right = i + 1;
    while (1)
    {
      if (left < 0 ||
          right >= s.length() ||
          s[left] != s[right])
        break;
      else
      {
        Ares += 2;
        left--;
        right++;
      }
    }

    answer = max(answer, max(Ores, Ares));
  }

  return answer;
}