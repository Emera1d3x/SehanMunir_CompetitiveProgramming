// https://dmoj.ca/problem/stp1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  long long n = 0, q = 0, nearestPow = 0;
  cin >> n >> q; nearestPow = pow(2,ceil(log2(n)));
  long long segmentTree[nearestPow*2+1]; for (long long i = 0; i < nearestPow*2+1; i++){segmentTree[i] = 0;}
  for (long long i = 0; i < n; i++){
    long long cur = 0;
    cin >> cur;
    segmentTree[nearestPow+i] = cur;
  }
  for (long long i = nearestPow-1; i >= 1; i--){
    segmentTree[i] = segmentTree[2*i]+segmentTree[2*i+1];
  }
  for (long long i = 0 ; i < q; i++){
    char z = 0;
    cin >> z;
    if (z=='S'){
      long long l = 0, r = 0, ans = 0;
      cin >> l >> r;l+=nearestPow-1;r+=nearestPow-1;
      while (l<=r){
        if (l%2==1){ans += segmentTree[l];l = (l+1)/2;} else {l/=2;}
        if (r%2==0){ans += segmentTree[r];r = (r-1)/2;} else {r/=2;} 
      }
      cout << ans << endl;
    } else if (z=='U'){
      long long i = 0, x = 0;
      cin >> i >> x;
      long long upd = nearestPow+i-1;
      segmentTree[nearestPow+i-1] = x;
      while (true){
        upd/=2;
        segmentTree[upd] = segmentTree[2*upd]+segmentTree[2*upd+1];
        if (upd == 1){break;}
      }
    }
  }
  return 0;
}
