// https://dmoj.ca/problem/cco12p2
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int node;
  int weight;
};

struct CompareEdge {
  bool operator()(const Edge& a, const Edge& b) const {
    return a.weight > b.weight;
  }
};

int main() {
  const int INF = 1e9;
  int n, m; cin >> n >> m;
  vector<vector<Edge>> adj(n+1);
  for (int i = 0; i < m; i++){
    int u, v, w; cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  int dist[n+1][2];
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < 2; j++){
      dist[i][j] = INF;
    }
  }
  priority_queue<Edge, vector<Edge>, CompareEdge> pq;
  pq.push({1, 0});
  dist[1][0] = 0;
  while (pq.size() != 0){
    Edge u = pq.top();
    pq.pop();
    if (u.weight > dist[u.node][1]) continue;
    for (auto &neighbour : adj[u.node]){
      int nDist = u.weight + neighbour.weight;
      if (nDist < dist[neighbour.node][0]) {
        dist[neighbour.node][1] = dist[neighbour.node][0];
        dist[neighbour.node][0] = nDist;
        pq.push({neighbour.node, nDist});
      } else if (nDist > dist[neighbour.node][0] && nDist < dist[neighbour.node][1]) {
        dist[neighbour.node][1] = nDist;
        pq.push({neighbour.node, nDist});
      }
    }
  }
  if (dist[n][1] == INF){
    cout << -1 << endl;
    return 0;
  }
  cout << dist[n][1] << endl;
  return 0;
}
