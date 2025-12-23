// https://dmoj.ca/problem/cco11p2
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v;
  int t;
  int s;
};

struct Vamp {
  int node;
  int t;
  int s;
};

struct CompareVamp {
  bool operator()(const Vamp& a, const Vamp& b) const {
    return a.t > b.t;
  }
};

int main() 
{
  int s, n, m; cin >> s >> n >> m;
  vector<vector<Edge>> adj(n);
  for (int i = 0; i < m; i++){
    int u, v, t, b; cin >> u >> v >> t >> b;
    adj[u].push_back({v, t, t*b});
    adj[v].push_back({u, t, t*b});
  }
  int dist[n][s+1];
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= s; j++){
      dist[i][j] = -1;
    }
  }
  priority_queue<Vamp, vector<Vamp>, CompareVamp> pq;
  pq.push({0, 0, 0});
  dist[0][0] = 0;
  while (pq.size() != 0){
    Vamp u = pq.top();
    pq.pop();
    for (auto &edge : adj[u.node]){
      if (u.s + edge.s <= s && (dist[edge.v][edge.s+u.s] == -1 || u.t + edge.t < dist[edge.v][edge.s+u.s])){
        dist[edge.v][edge.s+u.s] = u.t + edge.t;
        pq.push({edge.v, u.t + edge.t, u.s + edge.s});
      }
    }
  }
  int minD = -1;
  for (int i = 0; i <= s; i++){
    if (dist[n-1][i] != -1){
      if (minD == -1){
        minD = dist[n-1][i];
      } else {
        minD = min(minD, dist[n-1][i]);
      }
    }
  }
  cout << minD << endl;
  return 0;
}
