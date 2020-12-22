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
	//   M
	// N
	cin >> N >> M;

	vector<vector<int>> board;

	string row_input;
	for (int i = 0; i < N; i++) {
		vector<int> row_list;
		cin >> row_input;
		for (int j = 0; j < M; j++) {
			row_list.push_back(row_input[j] - '0');
		}
		//reverse(row_list.begin(), row_list.end());
		board.push_back(row_list);
	}

	deque<point> dq;
	point start(0, 0);
	dq.push_back(start);

	while (!dq.empty()) {
		point now = dq.front();
		dq.pop_front();

		if (now.y > 0 && board[now.y - 1][now.x] == 1) {
			board[now.y - 1][now.x] = board[now.y][now.x] + 1;
			point next(now.x, now.y - 1);
			dq.push_back(next);
		}
		if (now.y < N - 1 && board[now.y + 1][now.x] == 1) {
			board[now.y + 1][now.x] = board[now.y][now.x] + 1;
			point next(now.x, now.y + 1);
			dq.push_back(next);
		}
		if (now.x > 0 && board[now.y][now.x - 1] == 1) {
			board[now.y][now.x - 1] = board[now.y][now.x] + 1;
			point next(now.x - 1, now.y);
			dq.push_back(next);
		}
		if (now.x < M - 1 && board[now.y][now.x + 1] == 1) {
			board[now.y][now.x + 1] = board[now.y][now.x] + 1;
			point next(now.x + 1, now.y);
			dq.push_back(next);
		}
	}
	
	cout << board[N - 1][M - 1];

	return 0;
}