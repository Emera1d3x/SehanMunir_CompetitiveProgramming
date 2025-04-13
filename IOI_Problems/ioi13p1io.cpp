// https://dmoj.ca/problem/ioi13p1io
#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{ 
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, l; cin >> n >> m >> l; 
  bool marked[n] = {false};
  unordered_map<int,unordered_map<int,int>> adjListW;
  unordered_map<int, vector<int>> adjList;
  for (int i = 0; i < m; i++){
    int u, v, w; cin >> u >> v >> w;
    adjListW[u][v] = w;
    adjListW[v][u] = w;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  vector<int> chain;
  int maxDiameter = 0;
  for (int i = 0; i < n; i++){
    if (marked[i]){continue;}
    unordered_map<int, int> dist1, dist2, p;
    stack<int> s;
    s.push(i);
    dist1[i] = 0;
    marked[i] = true;
    int farNode1 = i;
    while (!s.empty()) {
      int u = s.top(); s.pop();
      for (int v : adjList[u]) {
        if (dist1.find(v) == dist1.end()) {
          dist1[v] = dist1[u] + adjListW[u][v];
          s.push(v);
          marked[v] = true;
          if (dist1[v] > dist1[farNode1]) farNode1 = v;
        }
      }
    }
    s.push(farNode1);
    dist2[farNode1] = 0;
    int farNode2 = farNode1;
    while (!s.empty()) {
      int u = s.top(); s.pop();
      for (int v : adjList[u]) {
        if (dist2.find(v) == dist2.end()) {
          dist2[v] = dist2[u] + adjListW[u][v];
          p[v] = u;
          s.push(v);
          if (dist2[v] > dist2[farNode2]) farNode2 = v;
        }
      }
    }
    int diameter = dist2[farNode2];
    maxDiameter = max(maxDiameter, diameter);
    int curChain = diameter;
    int u = farNode2;
    int d = 0;
    while (p.count(u)) {
      int v = p[u];
      d += adjListW[u][v];
      int curDif = max(d, diameter - d);
      if (curDif < curChain) {
        curChain = curDif;
      }
      u = v;
    }
    chain.push_back(curChain);
  }
  sort(chain.begin(), chain.end(), greater<int>());
  if (chain.size() == 1){
    cout << maxDiameter << endl;
  } else if (chain.size() == 2){
    cout << max(maxDiameter, chain[0] + chain[1] + l) << endl;
  } else {
    cout << max(maxDiameter, max(chain[0] + chain[1] + l, chain[1] + chain[2] + 2*l)) << endl;
  }
  return 0;
}
