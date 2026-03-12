https://dmoj.ca/problem/dpz
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> h;
vector<ll> dp;
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n; ll c; cin >> n >> c;
  h.resize(n);
  dp.resize(n);
  for (int i = 0; i < n; i++){
    ll a; cin >> a;
    h[i] = a;
    dp[i] = -1;
  }
  dp[0] = 0;
  deque<int> dq;
  dq.push_back(0);
  for (int j = 1; j < n; j++){
    while (dq.size() > 1) {
      int i1 = dq[0], i2 = dq[1];
      ll ans1 = -2*h[j]*h[i1] + h[i1]*h[i1] + dp[i1];
      ll ans2 = -2*h[j]*h[i2] + h[i2]*h[i2] + dp[i2];
      if (ans1 >= ans2){
        dq.pop_front();
      } else {
        break;
      }
    }
    int i = dq.front();
    dp[j] = (h[j]-h[i])*(h[j]-h[i]) + dp[i] + c;
    while (dq.size() > 1) {
      int l1 = dq[dq.size()-2];
      int l2 = dq.back();
      int l3 = j;
      ll b1 = dp[l1]+h[l1]*h[l1];
      ll m1 = -2*h[l1];
      ll b2 = dp[l2]+h[l2]*h[l2];
      ll m2 = -2*h[l2];
      ll b3 = dp[l3]+h[l3]*h[l3];
      ll m3 = -2*h[l3];
      double p1 = (b1-b2)/(m2-m1);
      double p2 = (b2-b3)/(m3-m2);
      if (p1 >= p2) {
        dq.pop_back();
      } else {
        break;
      }
    }
    dq.push_back(j);
  }
  cout << dp[n-1] << endl;
  return 0; 
}
