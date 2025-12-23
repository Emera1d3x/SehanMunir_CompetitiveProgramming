// https://dmoj.ca/problem/ccc15s4
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v;
  int t;
  int h;
};

struct Ship {
  int node;
  int t;
  int h;
};

struct CompareShip {
  bool operator()(const Ship& a, const Ship& b) const {
    return a.t > b.t;
  }
};

int main() 
{
  int k, n, m; cin >> k >> n >> m;
  vector<vector<Edge>> adj(n+1);
  for (int i = 0; i < m; i++){
    int u, v, t, h; cin >> u >> v >> t >> h;
    adj[u].push_back({v, t, h});
    adj[v].push_back({u, t, h});
  }
  int s, e; cin >> s >> e;
  int dist[n+1][k];
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < k; j++){
      dist[i][j] = -1;
    }
  }
  priority_queue<Ship, vector<Ship>, CompareShip> pq;
  pq.push({s, 0, 0});
  dist[s][0] = 0;
  while (pq.size() != 0){
    Ship u = pq.top();
    pq.pop();
    for (auto &edge : adj[u.node]){
      if (u.h + edge.h < k && (dist[edge.v][edge.h+u.h] == -1 || u.t + edge.t < dist[edge.v][edge.h+u.h])){
        dist[edge.v][edge.h+u.h] = u.t + edge.t;
        pq.push({edge.v, u.t + edge.t, u.h + edge.h});
      }
    }
  }
  int minD = -1;
  for (int i = 0; i < k; i++){
    if (dist[e][i] != -1){
      if (minD == -1){
        minD = dist[e][i];
      } else {
        minD = min(minD, dist[e][i]);
      }
    }
  }
  cout << minD << endl;
  return 0;
}
