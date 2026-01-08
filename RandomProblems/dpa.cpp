// https://dmoj.ca/problem/dpa
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> ar;
vector<ll> cost;
int dp(int n){
  if (cost[n]!=-1){
    return cost[n];
  } else {
    cost[n] = min(dp(n-1)+abs(ar[n-1]-ar[n]),dp(n-2)+abs(ar[n-2]-ar[n]));
  }
  return cost[n];
}
int main() {
  cin.sync_with_stdio(0);cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    ar.push_back(a);
    cost.push_back(-1);
  }
  cost[0] = 0;
  cost[1] = abs(ar[1]-ar[0]);
  int ans = dp(n-1);
  cout << ans << endl;
  return 0; 
}
