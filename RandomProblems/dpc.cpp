// https://dmoj.ca/problem/dpc
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.sync_with_stdio(0);cin.tie(0);
  int n; cin >> n;
  ll ar[n][3];
  ll cost[n][3];
  for (int i = 0; i < n; i++){
    cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    cost[i][0] = 0;
    cost[i][1] = 0;
    cost[i][2] = 0;
  }
  cost[0][0] = ar[0][0];
  cost[0][1] = ar[0][1];
  cost[0][2] = ar[0][2];
  for (int i = 1; i < n; i++){
    cost[i][0] = 1LL*ar[i][0]+1LL*max(cost[i-1][1],cost[i-1][2]);
    cost[i][1] = 1LL*ar[i][1]+1LL*max(cost[i-1][0],cost[i-1][2]);
    cost[i][2] = 1LL*ar[i][2]+1LL*max(cost[i-1][1],cost[i-1][0]);
  }
  ll ans = max(max(cost[n-1][0],cost[n-1][1]),cost[n-1][2]);
  cout << ans << endl;
  return 0; 
}
