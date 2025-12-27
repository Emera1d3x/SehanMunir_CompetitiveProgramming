// https://dmoj.ca/problem/2drmq
#include <bits/stdc++.h>
using namespace std;

static int st[1000][1000][11][11];
static int lg[1001];
int n;

void init(vector<vector<int>> arr){
  n = arr.size();
  for (int i = 2; i <= n; i++){
    lg[i] = lg[i/2]+1;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      st[i][j][0][0] = arr[i][j];
    }  
  }
  int K = lg[n];
  for (int k = 0; k <= K; k++){
    for (int l = 0; l <= K; l++){
      if (k == 0 && l == 0) continue;
      for (int i = 0; i+(1<<k) <= n; i++) {
        for (int j = 0; j+(1<<l) <= n; j++) {
          if (k == 0) {
            st[i][j][k][l] = min(st[i][j][k][l-1], st[i][j+(1<<(l-1))][k][l-1]);
          } else if (l == 0) {
            st[i][j][k][l] = min(st[i][j][k-1][l], st[i+(1<<(k-1))][j][k-1][l]);
          } else {
            int a = st[i][j][k-1][l-1];
            int b = st[i+(1<<(k-1))][j][k-1][l-1];
            int c = st[i][j+(1<<(l-1))][k-1][l-1];
            int d = st[i +(1<<(k-1))][j+(1<<(l-1))][k-1][l-1];
            st[i][j][k][l] = min(min(a, b), min(c, d));
          }
        }
      }
    }
  }
}
int query(int a, int b, int c, int d){
  int k = lg[b-a+1];
  int l = lg[d-c+1];
  int a1 = st[a][c][k][l];
  int a2 = st[b-(1<<k)+1][c][k][l];
  int a3 = st[a][d-(1<<l)+1][k][l];
  int a4 = st[b-(1<<k)+1][d-(1<<l)+1][k][l];
  return min(min(a1, a2), min(a3, a4));
}
int main(){
  return 0;
}
