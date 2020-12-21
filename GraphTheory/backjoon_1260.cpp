//BFS
//DFS

#include <iostream>
#include <string>
#include <vector>
#include <deque>


#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int N, M;

// 4 5 1
// 1 2
// 1 3
// 1 4
// 2 4
// 3 4

// 1 2 4 3 DFS
// 1 2 3 4 BFS

bool compare(int A, int B) {
	return A > B;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	vector<int>* edge_list = new vector<int>[N + 1];
	deque<int> list;
	int* visit_list = new int[N + 1];

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		edge_list[from].push_back(to);
		edge_list[to].push_back(from);
	}

	for (int i = 0; i <= N; i++) {
		visit_list[i] = 0;
		sort(edge_list[i].begin(), edge_list[i].end(),compare);
	}
	list.push_back(K);
	while (!list.empty()) {
		int now = list.back();
		list.pop_back();
		if (visit_list[now] == 0) {
			cout << now << " ";
			for (int child : edge_list[now]) {
				if (visit_list[child] == 0) {
					list.push_back(child);
				}
			}
		}
		visit_list[now] = 1;
	}
	cout << endl;

	for (int i = 0; i <= N; i++) {
		visit_list[i] = 0;
		sort(edge_list[i].begin(), edge_list[i].end());
	}
	list.push_back(K);
	visit_list[K] = 1;
	while (!list.empty()) {
		int now = list.front();
		list.pop_front();

		cout << now << " ";
		for (int child : edge_list[now]) {
			if (visit_list[child] == 0) {
				visit_list[child] = 1;
				list.push_back(child);
			}
		}
	}
}