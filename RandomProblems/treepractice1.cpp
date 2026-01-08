// https://dmoj.ca/problem/treepractice1
#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{ 
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<bool> marked(n, false);
  vector<vector<pair<int,int>>> adjListW(n);
  vector<vector<int>> adjList(n);
  for (int i = 0; i < n-1; i++){
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    adjListW[u].push_back({v, w});
    adjListW[v].push_back({u, w});
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  int chain = 0;
  int maxDiameter = 0;
  for (int i = 0; i < n; i++){
    if (marked[i]){continue;}
    vector<int> dist1(n, -1), dist2(n, -1), p(n, -1);
    stack<int> s;
    s.push(i);
    dist1[i] = 0;
    marked[i] = true;
    int farNode1 = i;
    while (!s.empty()) {
      int u = s.top(); s.pop();
      for (int v : adjList[u]) {
        if (dist1[v] == -1) {
          int w = 0;
          for (auto &pr : adjListW[u]) if (pr.first == v) w = pr.second;
          dist1[v] = dist1[u] + w;
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
        if (dist2[v] == -1) {
          int w = 0;
          for (auto &pr : adjListW[u]){
            if (pr.first == v) w = pr.second;
          }
          dist2[v] = dist2[u] + w;
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
    while (p[u] != -1) {
      int v = p[u];
      int w = 0;
      for (auto &pr : adjListW[u])
          if (pr.first == v) w = pr.second;
      d += w;
      int curDif = max(d, diameter - d);
      if (curDif < curChain) curChain = curDif;
      u = v;
    }

    chain = max(chain, curChain);
  }

  cout << maxDiameter << endl << chain << endl;
  return 0;
}
