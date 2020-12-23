#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <algorithm> // sort
#include <cmath>     // floor

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF 2000000000 
#define MAXN 804 

vector<pii> edges[MAXN]; //dest, weight 
bool visit[MAXN];
int dist[MAXN];

int discovered;
int V, E;
int V1, V2;
int u, v, w;

int res[5];

void find(int start) {
    discovered = 0;

    for (int i = 0; i <= V; i++) {
        dist[i] = INF; // K to nodeV distance init
        visit[i] = false;
    }

    priority_queue<pii> pq; // -dist, index 
    pq.push({ 0, start }); // K has '0' distance to K

    while (pq.size()) { // !pq.empty()
        pii cur = pq.top();
        pq.pop();
        int distance = -cur.first;
        int current = cur.second;

        if (visit[current]) continue;
        if (dist[current] == INF) discovered++;

        visit[current] = true;
        dist[current] = distance;

        if (discovered == V) break;

        for (pii nx : edges[current]) {
            int next = nx.first;
            int weight = nx.second;
            pq.push({ -dist[current] - weight, next });
            // next가 같은 경우 중복 고려하지 않고 priorit_queue에 다 넣어도
            // MIN_HEAP에 알아서 weight가 작은 첫번 째 것만 search
        }
    }

    if (start == 1) {
        res[0] = dist[V1];
        res[1] = dist[V2];
    }
    if (start == V) {
        res[2] = dist[V1];
        res[3] = dist[V2];
    }
    if (start == V1) res[4] = dist[V2];
}

int main() {

    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({ v, w });
        edges[v].push_back({ u, w });
    }

    scanf("%d %d", &V1, &V2);

    find(1); // 1-> V1, V2 // 0 1
    find(V); // V-> V1, V2 // 2 3
    find(V1); // V1-> V2 / 4

    if (res[0] == INF || res[1] == INF || res[2] == INF || res[3] == INF || res[4] == INF) printf("-1");
    else printf("%d", min(res[0] + res[3], res[1] + res[2]) + res[4]);

    return 0;
}