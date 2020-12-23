// 다익스트라(dijkstra)
// https://www.crocus.co.kr/532

#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include <algorithm> // sort
#include <cmath>     // floor
using namespace std;

class Edge {
public:
	int to, weight;

	Edge() { ; };
	Edge(int a, int b) {
		to = a;
		weight = b;
	}
};

int main() {
	int V, E;
	int K;
	int u, v, w;

	//cin >> V >> E;
	//cin >> K;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	K--;

	vector<Edge>* edge_list = new vector<Edge>[V]; // 1 ~ V ==> 0 ~ V-1

	for (int i = 0; i < E; i++) {
		//cin >> u >> v >> w;
		scanf("%d %d %d", &u, &v, &w);

		u--;
		v--;

		Edge temp(v, w);
		edge_list[u].push_back(temp);
	}

	int* dist = new int[V];
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		dist[i] = 999999, visited[i] = false;

	dist[K] = 0;
	int now = K;

	for(int i = 0; i < V-1; i++) {
		visited[now] = true;

		for (Edge edge : edge_list[now]) {
			if(visited[edge.to] == false) dist[edge.to] = min(dist[edge.to], dist[now] + edge.weight);
		}

		int min = 999999;
		for (int i = 0; i < V; i++) {
			if (visited[i] == false && min > dist[i]) {
				min = dist[i];
				now = i;
			}
		}
	}

	for (int i = 0; i < V; i++) {
		//if (dist[i] == 999999) cout << "INF" << endl;
		//else cout << dist[i] << endl;
		if (dist[i] == 999999) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}

