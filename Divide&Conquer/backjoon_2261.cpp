// 가장 가까운 두 점 사이의 거리^2 찾기

#include <cstdio>

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N;

class point {
  public:
    int x, y;
  point() {;}
  point(int a, int b) {
    x = a;
    y = b;
  }
};

struct compare{
    bool operator() (point A, point B) const {
        if (A.y == B.y)  {
            return A.x < B.x;
        }
        else {
            return A.y < B.y;
        }
    }
};

bool compareList(point& A, point& B) {
  if(A.x > B.x) return false;
  else if (A.x < B.x) return true;
  else return A.y < B.y;
}

long long dist(point A, point B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int main() {
  scanf("%d", &N);

  vector<point> input_list;

  int a, b;
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &a, &b);
    point temp(a, b);
    input_list.push_back(temp);
  }

  sort(input_list.begin(), input_list.end(), compareList);
  //for(int i = 0; i < N; i++) cout << pList[i].x << " " << pList[i].y << endl;

  // double smallDist = dist(pList[0], pList[1]);
  // vector<point> sList;
  // sList.push_back(pList[0]);
  // sList.push_back(pList[1]);
  // for(int i = 2 ; i < N; i++) {
  //   point now = sList[i];
  //   for(point temp: sList) {
  //     if(abs(temp.x - now.x) >= smallDist || abs(temp.y - now.y) >= smallDist){
  //       // pop temp
  //     } else {
  //       double tempDist = dist(pList[i], temp);
  //       smallDist = min(smallDist, tempDist);
  //     }
  //   }
  //   sList.push_back(pList[i]);
  // }

  // printf("%lld", (long long)(smallDist * smallDist));
  set<point, compare> candidate = { input_list[0], input_list[1] };
  long long shortest = dist(input_list[0], input_list[1]);
  int start = 0;
  int list_size = input_list.size();
  for (int i = 2; i < list_size; i++) {
      point& now = input_list[i];
      while (start < i) {
          point& p = input_list[start];
          int distX = now.x - p.x;
          if (distX * distX > shortest) {
              candidate.erase(p);
              start += 1;
          }
          else { // if it has any point inside the square
              break;
          }
      }

      int temp_d = (int)sqrt((double)shortest) + 1;
      point lower_point = point(-100000, now.y - temp_d);
      point upper_point = point(100000, now.y + temp_d);
      set<point>::iterator lower = candidate.lower_bound(lower_point);
      set<point>::iterator upper = candidate.upper_bound(upper_point);
      for (set<point>::iterator it = lower; it != upper; it++) {
          long long nowDist = dist(now, *it);
          if (nowDist < shortest) {
              shortest = nowDist;
          }
      }
      point temp = now;
      candidate.insert(temp);
  }

  printf("%lld", shortest);
}