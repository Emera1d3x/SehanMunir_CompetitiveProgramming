#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  } 
  for (int i = 1; i < n; i++) {
    a[i] = min(a[i], 2*a[i-1]);
  }
  vector<long long> cost;
  vector<long long> size;
  long long curSize = 1;
  int i = 0;
  while (i < n && curSize <= 1000000000LL) {
    cost.push_back(a[i]);
    size.push_back(curSize);
    curSize <<= 1;
    i++;
  }
  long long bestBig = LLONG_MAX;
  while (i < n) {
    bestBig = min(bestBig, a[i]); i++;
    
  }
  if (bestBig != LLONG_MAX) {
    cost.push_back(bestBig);
    size.push_back(curSize);
  }
  int m = cost.size();
  while (q--) {
    long long x; cin >> x;
    long long ans = LLONG_MAX;
    long long currCost = 0;
    for (int j = m - 1; j >= 0; j--) {
      long long take = x/size[j];
      if (take > 0) {
        currCost += take*cost[j];
        x -= take*size[j];
      }
      if (x > 0) {
        ans = min(ans, currCost + cost[j]);
      }
    }
    ans = min(ans, currCost);
    cout << ans << endl;
  }
  return 0;
}
