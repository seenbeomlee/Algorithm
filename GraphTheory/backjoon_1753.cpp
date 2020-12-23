// 다익스트라 Dijkstra
// https://eine.tistory.com/entry/%EB%B0%B1%EC%A4%80-1753%EB%B2%88-%EB%AC%B8%EC%A0%9C-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C-%ED%92%80%EC%9D%B4

// Pair - first를 먼저 비교하고, first가 같은 경우 second의 대소 비교
// Priority_queue는 기본적으로 MAX_HEAP 이므로, '-'를 넘어서 음수 값을 넣는 형식으로 MIN_HEAP 구현

#include <bits/stdc++.h> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii; 

#define INF 2000000000 
#define MAXN 20004 

vector<pii> edges[MAXN]; //dest, weight 
bool visit_check[MAXN]; 
int dist[MAXN]; 

int main() { 
  
  int discovered = 0; 
  int V, E, K; 
  
  scanf("%d%d%d", &V, &E, &K); 
  
  for (int i = 0; i <= V; i++) { 
    dist[i] = INF; // K to nodeV distance init
  } 
  
  for (int i = 0; i < E; i++) { 
    int u, v, w; scanf("%d%d%d", &u, &v, &w); 
    edges[u].push_back({ v, w }); 
  } 
    
  priority_queue<pii> pq; // -dist, index 
  pq.push({ 0, K }); // K has '0' distance to K

  while (pq.size()) { // !pq.empty()
    pii cur = pq.top(); 
    pq.pop(); 
    int distance = -cur.first; 
    int current = cur.second; 
    
    if (visit_check[current]) continue; 
    if (dist[current] == INF) discovered++; 
    
    visit_check[current] = true; 
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
    
    for (int i = 1; i <= V; i++) { 
      if (dist[i] == INF) { puts("INF"); } 
      else { printf("%d\n", dist[i]); } 
    } 
      
  return 0; 
}