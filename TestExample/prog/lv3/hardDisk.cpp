// fail with test-case 19

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

class job
{
public:
  int start, time, wait, done;
  job() { ; }
  job(int x, int y)
  {
    start = x;
    time = y;
    wait = 0;
    done = 0;
  }
};

bool compare(job &A, job &B)
{
  if (A.start > B.start)
    return false;
  else if (A.start < B.start)
    return true;
  else
    return A.time < B.time;
}

int solution(vector<vector<int>> jobs)
{
  int answer = 0;

  vector<job> list;
  int x, y;
  for (int i = 0; i < jobs.size(); i++)
  {
    x = jobs[i][0];
    y = jobs[i][1];
    job temp(x, y);
    list.push_back(temp);
  }

  sort(list.begin(), list.end(), compare); // start asc -> end asc

  vector<job *> waitList;
  vector<job *> endList;

  job *now = &list[0];
  now->done = 1;
  now->wait = now->time;
  int current = now->start + now->time;
  int waitIdx = 1;
  while (endList.size() != list.size())
  {
    // put and update waitList
    for (waitIdx; waitIdx < list.size(); waitIdx++)
    {
      if (list[waitIdx].start <= current && list[waitIdx].done == 0)
      {
        waitList.push_back(&list[waitIdx]);
      }
      else
        break;
    }

    // update wait in waitList
    //for (job& temp : waitList) {
    //if(temp.done == 0) temp.wait += current - temp.start;
    //}

    // put now to endList
    endList.push_back(now);
    if (endList.size() == list.size())
      break;

    // select next job in waitList
    int tt = 1001;
    for (job *temp : waitList)
    {
      if (temp->done == 0)
      {
        if (tt > temp->time)
        {
          now = temp;
          tt = temp->time;
        }
      }
    } // update current
    if (tt == 1001)
    {
      for (int i = 0; i < list.size(); i++)
      {
        if (list[i].start >= current)
        {
          now = &list[i];
          break;
        }
      }
      current = now->start + now->time;
    }
    else
    {
      current += now->time;
    }
    now->done = 1;
    now->wait += current - now->start;
  }

  for (job temp : list)
  {
    answer += temp.wait;
  }

  return answer / list.size();
}

int main()
{
  vector<vector<int>> input;
  vector<int> A;
  vector<int> B;
  vector<int> C;
  vector<int> D;

  A.push_back(0);
  A.push_back(3);

  B.push_back(4);
  B.push_back(4);

  C.push_back(5);
  C.push_back(3);

  D.push_back(4);
  D.push_back(1);

  input.push_back(A);
  input.push_back(B);
  input.push_back(C);
  input.push_back(D);

  int ans = solution(input);

  cout << ans;

  return 0;
}