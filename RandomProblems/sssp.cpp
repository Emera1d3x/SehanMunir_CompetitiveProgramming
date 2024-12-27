// https://dmoj.ca/problem/sssp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<unordered_map<int,int>> adjList(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    if (adjList[u-1].count(v-1)) {
      adjList[u-1][v-1] = min(adjList[u-1][v-1], w);
      adjList[v-1][u-1] = min(adjList[v-1][u-1], w);
    } else {
      adjList[u-1][v-1] = w;
      adjList[v-1][u-1] = w;
    }
  }
  vector<bool> marked(n, false);
  vector<int> dist(n, -1);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  dist[0] = 0;
  pq.push({0,0});
  while (!pq.empty()){
    int curNode = pq.top().second;
    int curDist = pq.top().first;
    pq.pop();
    if (marked[curNode]){continue;}
    marked[curNode]=true;
    for (const pair<int, int>& neighbour : adjList[curNode]) {
      int neighbourNode = neighbour.first;
      int weight = neighbour.second;
      if (dist[neighbourNode]==-1){
        dist[neighbourNode]=curDist+weight;
        pq.push({dist[neighbourNode],neighbourNode});
      } else if (dist[neighbourNode]>=curDist+weight){
        dist[neighbourNode]=curDist+weight;
        pq.push({dist[neighbourNode],neighbourNode});
      }
    }
  }
  for (int x : dist){
    cout << x << endl;
  }
  return 0;
}
