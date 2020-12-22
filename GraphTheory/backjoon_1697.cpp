#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int check[200000];

class Point {
public: 
	int num, depth;
	int prev;

	Point() { ; };
	Point(int a, int b, int c) {
		num = a;
		depth = b;
		prev = c;
	}
};

int main() {
	int N, K;
	cin >> N >> K;

	deque<Point> dq;
	Point start(N, 0, N);
	dq.push_back(start);
	Point now;
	while (1) {
		now = dq.front();
		dq.pop_front();

		if (now.num == K) break;
		else {
			if (now.num > 0 && now.prev != now.num - 1 && check[now.num - 1] == 0) {
				Point temp0(now.num - 1, now.depth + 1, now.num);
				dq.push_back(temp0);

				check[now.num - 1] = 1;
			}

			if (now.prev != now.num + 1 && now.num + 1 < 200000  && check[now.num + 1] == 0) {
				Point temp1(now.num + 1, now.depth + 1, now.num);
				dq.push_back(temp1);

				check[now.num + 1] = 1;
			}

			if (now.prev != now.num * 2 && now.num * 2 < 200000  && check[now.num * 2] == 0) {
				Point temp2(now.num * 2, now.depth + 1, now.num);
				dq.push_back(temp2);

				check[now.num * 2] = 1;
			}
		}
	}

	cout << now.depth;
}