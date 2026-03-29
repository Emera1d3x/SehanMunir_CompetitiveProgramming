// https://dmoj.ca/problem/mmcc15p1
#include <bits/stdc++.h>
using namespace std;

struct Info {
  int u;
  int v;
  int ur;
  int vr;
  int us;
  int vs;
};
vector<Info> history;
vector<int> rep;
vector<int> sz;
int find (int x){
  while (x != rep[x]){
    x = rep[x];
  }
  return x;
}
void Init(int N){
  rep.resize(N+1);
  sz.resize(N+1);
  for (int i = 0; i <= N; i++){
    rep[i] = i;
    sz[i] = 1;
  }
}
void AddEdge(int U, int V){
  int u = find(U);
  int v = find(V);
  if (u == v){
    history.push_back({0, 0, 0, 0, 0, 0});
    return;
  }
  if (sz[u] < sz[v]){
    swap(u, v);
  }
  history.push_back({u, v, rep[u], rep[v], sz[u], sz[v]});
  rep[v] = u;
  sz[u] += sz[v];
}
void RemoveLastEdge(){
  Info last = history.back();
  history.pop_back();
  if (last.u != 0){
    rep[last.u] = last.ur;
    sz[last.u] = last.us;
    rep[last.v] = last.vr;
    sz[last.v] = last.vs;
  }
}
int GetSize(int U){
  return sz[find(U)];
}
int main(){
  return 0;
}
