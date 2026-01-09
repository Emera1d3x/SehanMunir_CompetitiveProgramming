// https://dmoj.ca/problem/dpd
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101][100001];
int main() {
  cin.sync_with_stdio(0);cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++){
    int w; ll v; cin >> w >> v;
    for (int j = 1; j <= k; j++){
      if (j < w){
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0; 
}
