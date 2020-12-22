#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

//7
//0110100
//0110101
//1110101
//0000111
//0100000
//0111110
//0111000

//3
//7
//8
//9

class point {
public:
	int x, y;

	point() { ; };
	point(int a, int b) {
		x = a;
		y = b;
	}
};

int main()
{
	int N, M;
	cin >> M >> N;

	int** board = new int* [N];
	for (int i = 0; i < N; i++) board[i] = new int[M];

	deque<point> dq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				point temp(j, i);
				dq.push_back(temp);
			}
		}
	}

	int res = 0; // res = max(res, board[i][j])

	while (!dq.empty()) {
		point now = dq.front();
		dq.pop_front();

		/*
		cout << "now(" << now.x << ", " << now.y << ")" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		*/

		res = max(res, board[now.y][now.x]);

		if (now.y > 0 && board[now.y - 1][now.x] == 0) {
			board[now.y - 1][now.x] = board[now.y][now.x] + 1;
			point next(now.x, now.y - 1);
			dq.push_back(next);
		}
		if (now.y < N - 1 && board[now.y + 1][now.x] == 0) {
			board[now.y + 1][now.x] = board[now.y][now.x] + 1;
			point next(now.x, now.y + 1);
			dq.push_back(next);
		}
		if (now.x > 0 && board[now.y][now.x - 1] == 0) {
			board[now.y][now.x - 1] = board[now.y][now.x] + 1;
			point next(now.x - 1, now.y);
			dq.push_back(next);
		}
		if (now.x < M - 1 && board[now.y][now.x + 1] == 0) {
			board[now.y][now.x + 1] = board[now.y][now.x] + 1;
			point next(now.x + 1, now.y);
			dq.push_back(next);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (board[i][j] == 0) {
				res = 0;
				break;
			}
		if (res == 0) break;
	}

	cout << res - 1;
}