// https://dmoj.ca/problem/ds2
#include <bits/stdc++.h>
using namespace std;
vector<int> rep;
vector<int> sz;
int find (int x){
  while (x != rep[x]){
    x = rep[x];
  }
  return x;
}
bool same(int u, int v){
  if (find(u) == find(v)){
    return true;
  } 
  return false;
}
void unite(int u, int v){
  u = find(u);
  v = find(v);
  if (sz[u] < sz[v]){
    swap(u,v);
  } 
  sz[u] += sz[v];
  rep[v] = u;
}
int main() 
{
  cin.sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  rep.resize(n+1);
  sz.resize(n+1);
  for (int i = 0; i <= n; i++){
    rep[i] = i;
    sz[i] = 1;
  }
  vector<int> adj[n+1];
  vector<pair<int, int>> edge;
  queue<int> edges;
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    edge.push_back({u, v});
  }
  for (int i = 0; i < m; i++){
    int u = edge[i].first; 
    int v = edge[i].second;
    if (!same(u, v)){
      unite(u, v);
      edges.push(i+1);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  stack<int> s;
  bool marked[n+1]={};
  s.push(1);
  while (!s.empty()){
    int curNode = s.top();
    s.pop();
    if (marked[curNode]){continue;}
    marked[curNode] = true;
    for (int neighbour : adj[curNode]){
      if (!marked[neighbour]){
        s.push(neighbour);
      }
    }
  }
  bool works = true;
  for (int i = 1; i <= n; i++){
    works = works & marked[i];
  }
  if (!works){
    cout << "Disconnected Graph" << endl;
  } else {
    while (!edges.empty()){
      int x = edges.front();
      edges.pop();
      cout << x << endl;
    }
  }
  return 0;
}
