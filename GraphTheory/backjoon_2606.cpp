#include <iostream>
#include <string>
#include <vector>
#include <deque>


#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N, M;

//7
//6
//1 2
//2 3
//1 5
//5 2
//5 6
//4 7

int main()
{
	cin >> N >> M;

	vector<int>* edge_list = new vector<int>[N+1];

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		edge_list[from].push_back(to);
		edge_list[to].push_back(from);
	}

	vector<int> check_list;
	check_list.assign(N+1, 0);

	deque<int> q;
	q.push_back(1);

	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop_front();

		if (check_list[now] == 0) {
			for (int child : edge_list[now]) {
				q.push_back(child);
			}
		}

		check_list[now] = 1;
	}

	int count = 0;
	for (int i = 0; i < N + 1; i++)
		if (check_list[i] == 1) count++;

	cout << count - 1;
}