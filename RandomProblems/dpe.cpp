// https://dmoj.ca/problem/dpe
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101][100001];
int main() {
  cin.sync_with_stdio(0);cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < 100001; j++){
      dp[i][j] = LLONG_MAX;
    }
  } dp[0][0] = 0;
  for (int i = 1; i <= n; i++){
    ll w; int v; cin >> w >> v;
    for (int j = 0; j < 100001; j++){
      dp[i][j] = dp[i-1][j];
      if (j >= v && dp[i-1][j-v] != LLONG_MAX){
        dp[i][j] = min(dp[i][j], dp[i-1][j-v] + w);
      }
    }
  }
  ll ans = 0;
  for (int j = 0; j < 100001; j++){
    if (dp[n][j] <= k){
      ans = j;
    }
  }
  cout << ans << endl;
  return 0; 
}
