#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

class Point {
public: 
	int x, y;

	Point() { ; };
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

int N, M;
int res = 10001;

void bfs(vector<vector<int>> board, Point& bp) {
	board[bp.y][bp.x] = 0;

	deque<Point> dq;
	Point start(0, 0);
	dq.push_back(start);

	board[0][0] = 1;
	while (!dq.empty()) {
		Point now = dq.front();
		dq.pop_front();

		if (board[now.y][now.x] >= res) return;

		if (now.y > 0 && board[now.y - 1][now.x] == 0) {
			board[now.y - 1][now.x] = board[now.y][now.x] + 1;
			Point next(now.x, now.y - 1);
			dq.push_back(next);
		}
		if (now.y < N - 1 && board[now.y + 1][now.x] == 0) {
			board[now.y + 1][now.x] = board[now.y][now.x] + 1;
			Point next(now.x, now.y + 1);
			dq.push_back(next);
		}
		if (now.x > 0 && board[now.y][now.x - 1] == 0) {
			board[now.y][now.x - 1] = board[now.y][now.x] + 1;
			Point next(now.x - 1, now.y);
			dq.push_back(next);
		}
		if (now.x < M - 1 && board[now.y][now.x + 1] == 0) {
			board[now.y][now.x + 1] = board[now.y][now.x] + 1;
			Point next(now.x + 1, now.y);
			dq.push_back(next);
		}
	}

	if (board[N - 1][M - 1] != 0) res = min(res, board[N - 1][M - 1]);
}

int main() {
	int res = 10001;
	cin >> N >> M;

	//   M
	// N

	string row_input;
	vector<vector<int>> board;
	vector<Point> pList;
	for (int i = 0; i < N; i++) {
		cin >> row_input;
		vector<int> board_row;
		for (int j = 0; j < M; j++) {
			int input = row_input[j] - '0';
			if (input == 1) input = -1;

			board_row.push_back(input);
			if (input == -1) {
				Point temp(j, i);
				pList.push_back(temp);
			}
		}
		board.push_back(board_row);
	}

	// (0, 0) to (N-1, M-1)
	// you can break one wall(-1) if it makes shortest path
	for (int i = 0; i < pList.size(); i++) { // loop for pList 0 ~ pList.size() -1
		Point& bp = pList[i];
		bfs(board, bp);
	}

	if (res == 10001) res = -1;
	cout << res;
}