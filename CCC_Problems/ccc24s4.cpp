// https://dmoj.ca/problem/ccc24s4
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> marked;
vector<char> ans;

void dfs(int node, int depth = 0) {
  if (marked[node]) return;
  marked[node] = true;
  for (auto& [nxt, i] : adj[node]) {
    if (!marked[nxt]) {
      ans[i] = depth % 2 == 0 ? 'R' : 'B';
      dfs(nxt, depth+1);
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  adj.resize(n+1);
  marked.resize(n+1);
  ans.resize(m);
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
  for (int i = 0; i < m; i++){
    ans[i] = 'G';
  }
  for (int i = 1; i <= n; i++){
    dfs(i, 0);
  }
  
  for (int i = 0; i < m; i++){
    cout << ans[i];
  }
  return 0;  
}
