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
	int T;
	int M, N, K;
	int res = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		res = 0;
		cin >> M >> N >> K;

		vector<vector<int>> board;

		for (int j = 0; j < N; j++) {
			vector<int> row_list;
			for (int k = 0; k < M; k++) {
				row_list.push_back(0);
			}
			board.push_back(row_list);
		}

		int x, y;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			board[y][x] = 1;
		}

		deque<point> pList;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[j][k] == 1) {
					res++;
					board[j][k] = 2;

					point temp(k, j);
					pList.push_back(temp);
					while (!pList.empty()) {
						point now = pList.front();
						pList.pop_front();

						if (now.y > 0 && board[now.y - 1][now.x] == 1) {
							board[now.y - 1][now.x] = 2;
							point next(now.x, now.y - 1);
							pList.push_back(next);
						}
						if (now.y < N - 1 && board[now.y + 1][now.x] == 1) {
							board[now.y + 1][now.x] = 2;
							point next(now.x, now.y + 1);
							pList.push_back(next);
						}
						if (now.x > 0 && board[now.y][now.x - 1] == 1) {
							board[now.y][now.x - 1] = 2;
							point next(now.x - 1, now.y);
							pList.push_back(next);
						}
						if (now.x < M - 1 && board[now.y][now.x + 1] == 1) {
							board[now.y][now.x + 1] = 2;
							point next(now.x + 1, now.y);
							pList.push_back(next);
						}
					}
				}
			}
		}

		cout << res << endl;
	}
}