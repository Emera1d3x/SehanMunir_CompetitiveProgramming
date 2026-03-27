// https://dmoj.ca/problem/ccc23s4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 2e12;

struct Edge {
  ll u;
  ll v;
  ll l;
  ll c;
};
struct CompareEdge {
  bool operator()(const Edge& a, const Edge& b) const {
    if (a.l != b.l){
      return (a.l > b.l);
    } else {
      return (a.c > b.c);
    }
  }
};
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  ll n, m; cin >> n >> m;
  vector<vector<Edge>> adj(n+1);
  priority_queue<Edge, vector<Edge>, CompareEdge> minEdge;
  for (ll i = 0; i < m; i++){
    ll u, v, l, c;
    cin >> u >> v >> l >> c;
    minEdge.push({u, v, l, c});
  }
  ll cost = 0;
  while (!minEdge.empty()){
    auto z = minEdge.top();
    minEdge.pop();
    vector<ll> oldDist(n+1, INF);
    vector<bool> oldMarked(n+1, false);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
    pq.push({0, z.u});
    oldDist[z.u] = 0;
    while (!pq.empty()){
      ll curNode = pq.top().second;
      ll curDist = pq.top().first;
      pq.pop();
      if (oldMarked[curNode]){continue;}
      oldMarked[curNode]=true;
      for (auto neighbour : adj[curNode]) {
        ll neighbourNode = neighbour.v;
        ll weight = neighbour.l;
        if (oldDist[neighbourNode]>=curDist+weight){
          oldDist[neighbourNode]=curDist+weight;
          pq.push({oldDist[neighbourNode],neighbourNode});
        }
      }
    }
    adj[z.u].push_back({z.u, z.v, z.l, z.c});
    adj[z.v].push_back({z.v, z.u, z.l, z.c});
    vector<ll> newDist(n+1, INF);
    vector<bool> newMarked(n+1, false);
    pq.push({0, z.u});
    newDist[z.u] = 0;
    while (!pq.empty()){
      ll curNode = pq.top().second;
      ll curDist = pq.top().first;
      pq.pop();
      if (newMarked[curNode]){continue;}
      newMarked[curNode]=true;
      for (auto neighbour : adj[curNode]) {
        ll neighbourNode = neighbour.v;
        ll weight = neighbour.l;
        if (newDist[neighbourNode]>=curDist+weight){
          newDist[neighbourNode]=curDist+weight;
          pq.push({newDist[neighbourNode],neighbourNode});
        }
      }
    }
    if (newDist[z.v] < oldDist[z.v]){
      cost += z.c;
    } else {
      adj[z.u].pop_back();
      adj[z.v].pop_back();
    }
  }
  
  cout << cost << endl;
  return 0;
}
