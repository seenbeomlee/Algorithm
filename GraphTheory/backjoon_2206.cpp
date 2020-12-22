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
int res;

void bfs(vector<vector<int>> board, Point& now, int can) {

	if (board[now.y][now.x] >= res) return;
	if (now.x == M - 1 && now.y == N - 1) {
		res = min(res, board[now.y][now.x]);
		return;
	}

	if (now.y > 0) {
		if (board[now.y - 1][now.x] == 0) {
			board[now.y - 1][now.x] = board[now.y][now.x] + 1;
			Point next(now.x, now.y - 1);
			bfs(board, next, can);
			board[now.y - 1][now.x] = 0;
		}
		else if (can == 0 && board[now.y - 1][now.x] == -1) {
			board[now.y - 1][now.x] = board[now.y][now.x] + 1;
			Point next(now.x, now.y - 1);
			bfs(board, next, 1);
			board[now.y - 1][now.x] = -1;
		}
	}
	if (now.y < N - 1) {
		if (board[now.y + 1][now.x] == 0) {
			board[now.y + 1][now.x] = board[now.y][now.x] + 1;
			Point next(now.x, now.y + 1);
			bfs(board, next, can);
			board[now.y + 1][now.x] = 0;
		}
		else if (can == 0 && board[now.y + 1][now.x] == -1) {
			board[now.y + 1][now.x] = board[now.y][now.x] + 1;
			Point next(now.x, now.y + 1);
			bfs(board, next, 1);
			board[now.y + 1][now.x] = -1;
		}
	}
	if (now.x > 0) {
		if (board[now.y][now.x - 1] == 0) {
			board[now.y][now.x - 1] = board[now.y][now.x] + 1;
			Point next(now.x - 1, now.y);
			bfs(board, next, can);
			board[now.y][now.x - 1] = 0;
		}
		else if (can == 0 && board[now.y][now.x - 1] == -1) {
			board[now.y][now.x - 1] = board[now.y][now.x] + 1;
			Point next(now.x - 1, now.y);
			bfs(board, next, 1);
			board[now.y][now.x - 1] = -1;
		}
	}
	if (now.x < M - 1) {
		if (board[now.y][now.x + 1] == 0) {
			board[now.y][now.x + 1] = board[now.y][now.x] + 1;
			Point next(now.x + 1, now.y);
			bfs(board, next, can);
			board[now.y][now.x + 1] = 0;
		}
		else if (can == 0 && board[now.y][now.x + 1] == -1) {
			board[now.y][now.x + 1] = board[now.y][now.x] + 1;
			Point next(now.x + 1, now.y);
			bfs(board, next, 1);
			board[now.y][now.x + 1] = -1;
		}
	}
		
}

int main() {
	res = 10001;
	cin >> N >> M;

	//   M
	// N

	string row_input;
	vector<vector<int>> board;
	for (int i = 0; i < N; i++) {
		cin >> row_input;
		vector<int> board_row;
		for (int j = 0; j < M; j++) {
			int input = row_input[j] - '0';
			if (input == 1) input = -1;

			board_row.push_back(input);
		}
		board.push_back(board_row);
	}

	// (0, 0) to (N-1, M-1)
	// you can break one wall(-1) if it makes shortest path
	Point start(0, 0);
	board[0][0] = 1;
	bfs(board, start, 0); // if 0 -> can break, or not

	if (res == 10001) res = -1;
	cout << res;
}