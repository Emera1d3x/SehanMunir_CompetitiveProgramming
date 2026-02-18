// https://dmoj.ca/problem/ccc25s4
#include <bits/stdc++.h>
using namespace std;

struct Traveler {
  long long cost;
  int node;
  int edge;
};
struct CompareTraveler {
  bool operator()(const Traveler& a, const Traveler& b) const {
    return (a.cost > b.cost);
  }
};
struct Edge {
  int edgeNum;
  int v; 
  int l;
};
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<vector<Edge>> adj(n+1);
  vector<long long> weight(m+1);
  vector<long long> dist(m+1, LLONG_MAX);
  vector<bool> vis(m+1, false);
  vector<int> edge(m);
  for (int i = 0; i < m; i++){
    int u, v, l;
    cin >> u >> v >> l;
    adj[u].push_back({i, v, l});
    adj[v].push_back({i, u, l});
    weight[i] = l;
  }
  weight[m] = 0;
  priority_queue<Traveler, vector<Traveler>, CompareTraveler> pq;
  pq.push({0, 1, m});
  long long ans = -1;
  while (!pq.empty()){
    Traveler cur = pq.top();
    pq.pop();
    if (vis[cur.edge]) continue;
    vis[cur.edge] = true;
    if (cur.node == n){
      ans = cur.cost;
      break;
    }
    for (auto edges : adj[cur.node]){
      if (vis[edges.edgeNum]) continue;
      long long newCost = cur.cost + abs(weight[cur.edge] - weight[edges.edgeNum]);
      if (newCost < dist[edges.edgeNum]){
        dist[edges.edgeNum] = newCost;
        pq.push({newCost, edges.v, edges.edgeNum});
      }
    }
  }
  cout << ans << endl;
  return 0;
}
