#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

int main() {
	int V, E;
	int K;
	int u, v, w;

	cin >> V >> E;
	cin >> K;

	vector<int>* edge_list = new vector<int>[V+1];

	int** board = new int* [V+1];
	for (int i = 0; i < V+1; i++) board[i] = new int[V+1];
	for (int i = 0; i < V+1; i++)
		for (int j = 0; j < V+1; j++)
			board[i][j] = 11;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		if (board[u][v] == 11) edge_list[u].push_back(v);
		board[u][v] = min(board[u][v], w);
	}

	int* dist = new int[V+1];
	bool* visited = new bool[V+1];
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[K] = 0;
	visited[K] = true;
	int now = K;
	while (1) {




		for (int i = 0; i < V; i++) {
			if(visited)
		}
	}
}