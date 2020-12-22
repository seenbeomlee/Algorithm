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

int N;
int idx = 0;
vector<int> count_list;

void search(vector<vector<int>> board, vector<vector<int>>& visited, int i, int j) {
	visited[i][j] = idx;

	deque<point> pList;
	int num = 0;

	point start(j, i);
	pList.push_back(start);

	point now;
	while (!pList.empty()) {
		now = pList.front();
		pList.pop_front();
		num++;

		// i == now.y, j == now.x
		if (now.y > 0 && board[now.y - 1][now.x] == 1 && visited[now.y - 1][now.x] == 0) {
			visited[now.y - 1][now.x] = idx;
			point next(now.x, now.y - 1);
			pList.push_back(next);
		}
		if (now.y < N - 1 && board[now.y + 1][now.x] == 1 && visited[now.y + 1][now.x] == 0) {
			visited[now.y + 1][now.x] = idx;
			point next(now.x, now.y + 1);
			pList.push_back(next);
		}
		if (now.x > 0 && board[now.y][now.x - 1] == 1 && visited[now.y][now.x - 1] == 0) {
			visited[now.y][now.x - 1] = idx;
			point next(now.x - 1, now.y);
			pList.push_back(next);
		}
		if (now.x < N - 1 && board[now.y][now.x + 1] == 1 && visited[now.y][now.x + 1] == 0) {
			visited[now.y][now.x + 1] = idx;
			point next(now.x + 1, now.y);
			pList.push_back(next);
		}
	}

	count_list.push_back(num);
}

int main()
{
	cin >> N;

	vector<vector<int>> visited;
	vector<vector<int>> board;
	vector<int> inputList;
	
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputList.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		vector<int> board_row;
		vector<int> visited_row;
		for (int j = 0; j < N; j++) {
			input = inputList[i] % 10;
			inputList[i] /= 10;

			board_row.push_back(input);
			visited_row.push_back(0);
		}

		//reverse(board_row.begin(), board_row.end());

		board.push_back(board_row);
		visited.push_back(visited_row);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && visited[i][j] == 0) {
				idx++;
				search(board, visited, i, j);
			}
		}
	}

	cout << idx << endl;

	sort(count_list.begin(), count_list.end());
	for (int i = 0; i < count_list.size(); i++) cout << count_list[i] << endl;
}