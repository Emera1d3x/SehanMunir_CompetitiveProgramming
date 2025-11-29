#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() 
{
  int n, m, k, a, b;
  cin >> n >> m >> k >> a >> b;
  vector<int> ks;
  vector<vector<int>> adjList(n+1);
  vector<bool> markedA(n+1);
  vector<bool> markedB(n+1);
  vector<int> distA(n+1);
  vector<int> distB(n+1);
  for (int i = 0; i < k; i++){
    int a; cin >> a;
    ks.push_back(a);
  }
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  for (int i = 0; i <= n; i++){
    markedA[i] = false;
    markedB[i] = false;
    distA[i] = -1;
    distB[i] = -1;
  }
  queue<int> pq;
  distA[a] = 0;
  pq.push(a);
  while (!pq.empty()){
    int curNode = pq.front();
    pq.pop();
    if (markedA[curNode]){continue;}
    markedA[curNode] = true;
    for (int neighbour : adjList[curNode]){
      if (distA[neighbour]==-1){
        distA[neighbour] = distA[curNode] + 1;
        pq.push(neighbour);
      } else if (distA[neighbour]>distA[curNode] + 1){
        distA[neighbour] = distA[curNode] + 1;
        pq.push(neighbour);
      }
    }
  }
  distB[b] = 0;
  pq.push(b);
  while (!pq.empty()){
    int curNode = pq.front();
    pq.pop();
    if (markedB[curNode]){continue;}
    markedB[curNode] = true;
    for (int neighbour : adjList[curNode]){
      if (distB[neighbour]==-1){
        distB[neighbour] = distB[curNode] + 1;
        pq.push(neighbour);
      } else if (distB[neighbour]>distB[curNode] + 1){
        distB[neighbour] = distB[curNode] + 1;
        pq.push(neighbour);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < k; i++){
    ans = min(ans, distA[ks[i]]+distB[ks[i]]);
  }
  cout << ans << endl;
  return 0;
}
