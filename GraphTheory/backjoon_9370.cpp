// 최단 경로가 g-h를 거치는지 확인하는 방법

// sol1
// 1. g-h를 제외하고 dist1로 Dijkstra를 돌린다.
// 2. g-h를 포함하고 dist2로 Dijkstra를 돌린다.
// 3. dist1[i] != dist2[i] 면 최단 경로가 g-h를 거친다 (하지만, 최단 경로가 여러가지 일 경우 틀렸습니다)

// sol2
// g-h의 w에는 *2-1의 가중치(홀수)
// 나머지 edge의 w에는 *2의 가중치(짝수)
// dist[i] == 홀수면 g-h를 거친 것이다

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor

using namespace std;

typedef pair<int, int> pii;

#define INF 2000000000 

vector<pii>* edge_list;
bool* visit_check;

void Dijkstra(int* dist, int n, int s) {
	int discovered = 0;

	for (int i = 0; i < n + 1; i++) {
		dist[i] = INF;
		visit_check[i] = false;
	}
	dist[s] = 0;

	priority_queue<pii> pq;
	pq.push({ 0, s });

	while (pq.size()) {
		pii cur = pq.top();
		pq.pop();

		int distance = -cur.first;
		int current = cur.second;

		if (visit_check[current]) continue;
		if (dist[current] == INF) discovered++;

		visit_check[current] = true;
		dist[current] = distance;

		if (discovered == n) break;

		for (pii nx : edge_list[current]) {
			int next = nx.first;
			int weight = nx.second;
			pq.push({ -dist[current] - weight, next });
		}
	}
}

int main() {
	int T;
	int n, m, t;
	int s, g, h;
	int a, b, d;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &n, &m, &t);
		// n == #node 2~2,000
		// m == #edge 1~50,000
		// t == #candidate 1~100

		edge_list = new vector<pii>[n+1]; // 0 is empty
		visit_check = new bool[n + 1];
		int* dist = new int[n + 1];

		scanf("%d %d %d", &s, &g, &h);
		// s == start

		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &a, &b, &d);
			if ( (a == g && b == h) || (a == h && b == g) ) {
				d = d * 2 - 1;
			}
			else {
				d = d * 2;
			}
			edge_list[a].push_back({ b, d });
			edge_list[b].push_back({ a, d });
		}

		vector<int> candidate_list;
		int candidate;
		for (int j = 0; j < t; j++) {
			scanf("%d", &candidate);
			candidate_list.push_back(candidate);
		}

		Dijkstra(dist, n, s);

		vector<int> res_list;
		for (int j = 0; j < candidate_list.size(); j++) {
			if (dist[candidate_list[j]] % 2 == 1) res_list.push_back(candidate_list[j]);
		}
		sort(res_list.begin(), res_list.end());
		for (int j = 0; j < res_list.size(); j++) printf("%d ", res_list[j]);
	}
}