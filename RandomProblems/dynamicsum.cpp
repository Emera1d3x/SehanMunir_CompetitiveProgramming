// https://dmoj.ca/problem/dynamicsum
#include <bits/stdc++.h>
using namespace std;
int main() 
{
  cin.sync_with_stdio(0); cin.tie(0);
  long long n = 0, q = 0, nearestPow = 1;
  long long operations = 0, lastAns = 0;
  cin >> n >> q; 
  while (nearestPow < n) nearestPow <<= 1;
  vector<vector<pair<long long, long long>>> segmentTree(nearestPow*2);
  for (long long i = 0; i < nearestPow*2; i++){
    segmentTree[i].push_back({0, 0});
  }
  for (long long i = 0 ; i < q; i++){
    char z = 0;
    cin >> z;
    if (z=='2'){
      long long l = 0, r = 0, x = 0;
      cin >> l >> r >> x;
      l ^= lastAns;
      r ^= lastAns;
      x ^= lastAns;
      x = operations-x;
      long long ans = 0;
      l += nearestPow-1;
      r += nearestPow-1;
      while (l <= r) {
        if (l % 2 == 1) {
          auto &vec = segmentTree[l];
          int pos = upper_bound(vec.begin(), vec.end(), make_pair(x, LLONG_MAX)) - vec.begin();
          if (pos > 0) ans += vec[pos - 1].second;
          l++;
        }
        if (r % 2 == 0) {
          auto &vec = segmentTree[r];
          int pos = upper_bound(vec.begin(), vec.end(), make_pair(x, LLONG_MAX)) - vec.begin();
          if (pos > 0) ans += vec[pos - 1].second;
          r--;
        } l/=2; r/=2;
      }
      cout << ans << endl;
      lastAns = ans;
    } else if (z=='1'){
      operations++;
      long long i = 0, v = 0;
      cin >> i >> v;
      i ^= lastAns; v ^= lastAns;
      long long upd = nearestPow+i-1;
      while (upd >= 1) {
        auto &vec = segmentTree[upd];
        long long currentTotal = vec.back().second;
        vec.push_back({operations, currentTotal + v});
        if (upd == 1) break;
        upd /= 2;
      }
    }
  }
  return 0;
}
