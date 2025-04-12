// https://dmoj.ca/problem/ccc16s3
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
using namespace std;
unordered_set<int> pho;
unordered_map<int, unordered_set<int>> adjList;
unordered_map<int, unordered_set<int>> adjListMini;
bool adjListMiniMaker(int node, int parent){
  bool reqOverall = false;
  for (auto child : adjList[node]){
    if (child == parent) {continue;}
    bool req = adjListMiniMaker(child, node);
    if (req){
      reqOverall = true;
      adjListMini[node].insert(child);
      adjListMini[child].insert(node);
    }
  }
  if (reqOverall){return true;}
  if (pho.count(node)>0){return true;}
  return false;
}
int main() 
{ 
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m; int start;
  for (int i = 0; i < m; i++){
    int cur; cin >> cur; pho.insert(cur);
    start = cur;
  }
  for (int i = 0; i < n-1; i++){
    int u, v; cin >> u >> v;
    adjList[u].insert(v); adjList[v].insert(u);
  }
  adjListMiniMaker(start, -1);
  int total = 0;
  for (auto z : adjListMini){for (auto y : adjListMini[z.first]){total++;}}
  unordered_map<int, int> dist;
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  int farNode = start;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adjListMini[u]) {
      if (dist.find(v) == dist.end()) {
        dist[v] = dist[u] + 1;
        q.push(v);
        if (dist[v] > dist[farNode]) {farNode = v;}
      }
    }
  }
  dist.clear();
  q.push(farNode);
  dist[farNode] = 0;
  int diameter = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adjListMini[u]) {
      if (dist.find(v) == dist.end()) {
        dist[v] = dist[u] + 1;
        q.push(v);
        if (dist[v] > diameter) {
          diameter = dist[v];
        }
      }
    }
  }
  cout << total-diameter << endl;
  return 0;
}
