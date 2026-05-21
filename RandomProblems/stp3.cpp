// https://dmoj.ca/problem/stp3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  ll sum;
  ll maxPrefixSum;
};

Node merge(Node l, Node r) {
  return {l.sum+r.sum, max(l.maxPrefixSum, l.sum+r.maxPrefixSum)};
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  ll n, q; cin >> n >> q; 
  ll nearestPow = pow(2, ceil(log2(n)));
  vector<Node> segmentTree(nearestPow*2, {0, 0});
  for (ll i = 0; i < n; i++) {
    ll cur; cin >> cur;
    segmentTree[nearestPow + i] = {cur, cur};
  }
  for (ll i = nearestPow - 1; i >= 1; i--) {
    segmentTree[i] = merge(segmentTree[2 * i], segmentTree[2 * i + 1]);
  }
  for (ll i = 0 ; i < q; i++) {
    char z;
    cin >> z;
    if (z == 'P') {
      ll l, r; cin >> l >> r;
      l += nearestPow-1; r += nearestPow-1;
      bool hasL = false, hasR = false;
      Node resL, resR;
      while (l <= r) {
        if (l%2 == 1) {
          if (!hasL) {resL = segmentTree[l]; hasL = true;}
          else {resL = merge(resL, segmentTree[l]);}
          l++;
        }
        if (r%2 == 0) {
          if (!hasR) {resR = segmentTree[r]; hasR = true;}
          else {resR = merge(segmentTree[r], resR);} 
          r--;
        }
        l/=2;
        r/=2;
      }
      Node finalRes;
      if (hasL && hasR) {finalRes = merge(resL, resR);}
      else if (hasL) {finalRes = resL;}
      else {finalRes = resR;}     
      cout << finalRes.maxPrefixSum << endl;
    } else if (z == 'U') {
      ll idx, x;
      cin >> idx >> x;
      ll upd = nearestPow+idx-1;
      segmentTree[upd] = {x, x};
      upd/=2;
      while (upd >= 1) {
        segmentTree[upd] = merge(segmentTree[2 * upd], segmentTree[2 * upd + 1]);
        upd/=2;
      }
    }
  }
  return 0;
}
