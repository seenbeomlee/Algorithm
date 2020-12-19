#include <cstdio>

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // sort
#include <cmath> // floor

using namespace std;

int N, M;

class point {
  public:
    int x, y;
  
  point() {;}
  point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

bool compare(point& A, point& o) {
  if(A.x > o.x) return false;
  else if (o.x > A.x) return true;
  else return A.y < o.y;
}

int main() {
  scanf("%d", &N);

  int x, y;

  vector<point> pList;

  for(int i = 0; i < N; i++) {
    scanf("%d %d", &x, &y);
    point temp(x, y);
    pList.push_back(temp);
  }

  sort(pList.begin(), pList.end(), compare);

  for(int i = 0; i < N; i++) {
    printf("%d %d\n", pList[i].x, pList[i].y);
  }
}