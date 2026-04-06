// https://dmoj.ca/problem/ds3
// cheesing with sqrt decomp
#include <bits/stdc++.h>
using namespace std;
int main() 
{
  cin.sync_with_stdio(0); cin.tie(0);
  long long n = 0, q = 0, nearestPow = 0;
  cin >> n >> q; nearestPow = pow(2,ceil(log2(n)));
  int blockSize = 316;
  vector<unordered_map<int, int>> blocks(317);
  long long segmentTreeMin[nearestPow*2+1]; for (long long i = 0; i < nearestPow*2+1; i++){segmentTreeMin[i] = 0;}
  long long segmentTreeGCD[nearestPow*2+1]; for (long long i = 0; i < nearestPow*2+1; i++){segmentTreeGCD[i] = 0;}
  for (long long i = 0; i < n; i++){
    long long cur = 0;
    cin >> cur;
    segmentTreeMin[nearestPow+i] = cur;
    segmentTreeGCD[nearestPow+i] = cur;
    blocks[i/blockSize][cur]++;
  }
  for (long long i = nearestPow-1; i >= 1; i--){
    segmentTreeMin[i] = min(segmentTreeMin[2*i], segmentTreeMin[2*i+1]);
    segmentTreeGCD[i] = gcd(segmentTreeGCD[2*i], segmentTreeGCD[2*i+1]);
  }
  for (long long i = 0 ; i < q; i++){
    string z = " ";
    cin >> z;
    if (z == "M"){
      long long l = 0, r = 0, ans = 1e9;
      cin >> l >> r;l+=nearestPow-1;r+=nearestPow-1;
      while (l<=r){
        if (l%2==1){ans = min(ans, segmentTreeMin[l]);l = (l+1)/2;} else {l/=2;}
        if (r%2==0){ans = min(ans, segmentTreeMin[r]);r = (r-1)/2;} else {r/=2;} 
      }
      cout << ans << endl;
    } else if (z == "G"){
      long long l = 0, r = 0, ans = 0;
      cin >> l >> r;l+=nearestPow-1;r+=nearestPow-1;
      while (l<=r){
        if (l%2==1){ans = gcd(ans, segmentTreeGCD[l]);l = (l+1)/2;} else {l/=2;}
        if (r%2==0){ans = gcd(ans, segmentTreeGCD[r]);r = (r-1)/2;} else {r/=2;} 
      }
      cout << ans << endl;
    } else if (z == "C"){
      long long x = 0, v = 0;
      cin >> x >> v;
      long long upd = nearestPow+x-1;
      int oldVal = segmentTreeMin[nearestPow+x-1];
      segmentTreeMin[nearestPow+x-1] = v;
      segmentTreeGCD[nearestPow+x-1] = v;
      while (true){
        upd/=2;
        segmentTreeMin[upd] = min(segmentTreeMin[2*upd], segmentTreeMin[2*upd+1]);
        segmentTreeGCD[upd] = gcd(segmentTreeGCD[2*upd], segmentTreeGCD[2*upd+1]);
        if (upd == 1){break;}
      }
      blocks[(x-1)/blockSize][oldVal]--;
      blocks[(x-1)/blockSize][v]++;
    } else {
      long long li = 0, ri = 0, ans = 0, g = 0;
      cin >> li >> ri;
      long long l = li+nearestPow-1, r = ri+nearestPow-1;
      while (l<=r){
        if (l%2==1){g = gcd(g, segmentTreeGCD[l]);l = (l+1)/2;} else {l/=2;}
        if (r%2==0){g = gcd(g, segmentTreeGCD[r]);r = (r-1)/2;} else {r/=2;} 
      }
      li--; ri--;
      int bL = (li/blockSize), bR = (ri/blockSize);
      if (bL == bR) {
        for (int i = li; i <= ri; i++){
          if (segmentTreeMin[nearestPow+i] == g) ans++;
        } 
      } else {
        for (int i = li; i < (bL+1)*blockSize; i++){
          if (segmentTreeMin[nearestPow+i] == g) ans++;
        } 
        for (int i = bL+1; i < bR; i++){
          if (blocks[i].count(g)) ans += blocks[i][g];
        } 
        for (int i = bR*blockSize; i <= ri; i++){
          if (segmentTreeMin[nearestPow+i] == g) ans++;
        } 
      }
      cout << ans << endl;
    }
  }
  return 0;
}
