// 벨만 포드 알고리즘(Bellman - Ford Algorithm)
// https://www.crocus.co.kr/534?category=209527

// test-case for it
// https://www.acmicpc.net/board/view/39180

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
long long* dist;

bool bellman(int N, int M) {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;

	for (int idx = 0; idx < N; idx++) {
		for (int i = 1; i <= N; i++) {
			int start = i;

			for (pii next : edge_list[start]) {
				dist[next.first] = min(dist[next.first], dist[start] + next.second);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge_list[i].size(); j++) {
			if (dist[i] < INF / 2 && dist[edge_list[i][j].first] > dist[i] + edge_list[i][j].second) return false;
		}
	}

	return true;
}

int main() {
	int N, M;
	int a, b, c;

	scanf("%d %d", &N, &M);

	edge_list = new vector<pii>[N + 1]; // 0 is empty
	dist = new long long [N + 1] ;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge_list[a].push_back({ b, c });
	}

	// start with 1
	// if there exists negative loop, printf "-1"
	// if there exists un-reachable city, printf "-1"

	// bool result = bellman(N, M); // if false, there exists at least 1 negative cycle
	if (!bellman(N, M)) printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] > INF/ 2) printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}
}