// https://dmoj.ca/problem/ccc17s4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> rep;
vector<ll> sz;

ll find(ll x){
  while (x != rep[x]){
    x = rep[x];
  }
  return x;
}
bool same(ll u, ll v){
  return find(u) == find(v);
}
void unite(ll u, ll v){
  u = find(u);
  v = find(v);
  if (sz[u] < sz[v]){
    swap(u, v);
  }
  sz[u] += sz[v];
  rep[v] = u;
}
struct Edge {
  ll u, v, c, idx;
};
struct CompareEdge {
  bool operator()(const Edge& a, const Edge& b) const {
    if (a.c != b.c) return a.c > b.c;
    return a.idx > b.idx;
  }
};
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  ll n, m, d;
  cin >> n >> m >> d;
  rep.resize(n+1);
  sz.resize(n+1);
  for (ll i = 0; i <= n; i++){
    rep[i] = i;
    sz[i] = 1;
  }
  priority_queue<Edge, vector<Edge>, CompareEdge> pq;
  priority_queue<Edge, vector<Edge>, CompareEdge> pq2;
  for (ll i = 0; i < m; i++){
    ll u, v, c;
    cin >> u >> v >> c;
    pq.push({u, v, c, i+1});
    pq2.push({u, v, c, i+1});
  }
  ll maxEdge = 0, a = 0, b = 0;
  while (!pq.empty()){
    auto e = pq.top(); pq.pop();
    if (!same(e.u, e.v)){
      unite(e.u, e.v);
      maxEdge = max(maxEdge, e.c);
      (e.idx > n-1)? b++ : a++;
    }
  }
  ll days = max(b,(n-1)-a);
  if (d == 0){
    cout << days << endl;
    return 0;
  }
  for (ll i = 0; i <= n; i++){
    rep[i] = i;
    sz[i] = 1;
  }
  while (!pq2.empty()){
    auto e = pq2.top(); pq2.pop();
    if (!same(e.u, e.v)){
      if (e.c < maxEdge || (e.idx <= n-1 && e.c == maxEdge)) {
        unite(e.u, e.v);
      } else if (e.c <= d && e.idx <= n-1) {
        days--;
        break;
      }
    }
  }
  cout << days << endl;
  return 0;
}
