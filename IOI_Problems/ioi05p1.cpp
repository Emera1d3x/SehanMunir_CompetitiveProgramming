// https://dmoj.ca/problem/ioi05p1
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main(){
  int l, w, n, k; cin >> l >> w >> n >> k;
  l++; w++;
  int up[l], down[l], left[w], right[w];
  for (int i = 0; i < l; i++){
    up[i] = INF; down[i] = INF;
  }
  for (int i = 0; i < w; i++){
    left[i] = INF; right[i] = INF;
  }
  int ar[l][w], psa[l][w];
  for (int i = 0; i < l; i++){
    for (int j = 0; j < w; j++){
      ar[i][j] = 0;
      psa[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++){
    int li, wi; cin >> li >> wi;
    ar[li][wi] += 1;
  }
  for (int i = 0; i < l; i++){
    for (int j = 0; j < w; j++){
      if (i==0&&j==0){
        psa[i][j] = ar[i][j];
      } else if (i==0){
        psa[i][j] = ar[i][j] + psa[i][j-1];
      } else if (j==0){
        psa[i][j] = ar[i][j] + psa[i-1][j];
      } else {
        psa[i][j] = ar[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1]; 
      }
    }
  }
  for (int u = 1; u < l; u++){
    for (int d = u; d < l; d++){
      int lb = 1; int rb = 1;
      while (rb < w){
        int roses = psa[d][rb] - psa[u-1][rb] - psa[d][lb-1] + psa[u-1][lb-1];
        if (roses == k){
          int perimeter = 2*(d-u+1)+2*(rb-lb+1);
          up[d] = min(up[d], perimeter);
          down[u] = min(down[u], perimeter);
          left[rb] = min(left[rb], perimeter);
          right[lb] = min(right[lb], perimeter);
          lb++;
        } else if (roses > k){
          lb++;
          if (lb > rb){
            rb++;
          }
        } else {
          rb++;
        }
      }
    }
  }
  int ans = INF;
  for (int i = l-2; i >= 1; i--){
    down[i] = min(down[i], down[i+1]);
  }
  for (int i = 2; i <= l-1; i++){
    up[i] = min(up[i], up[i-1]);
  }
  for (int i = w-2; i >= 1; i--){
    right[i] = min(right[i], right[i+1]);
  }
  for (int i = 2; i <= w-1; i++){
    left[i] = min(left[i], left[i-1]);
  }
  for (int i = 1; i <= l-2; i++){
    ans = min(ans, up[i]+down[i+1]);
  }
  for (int i = 1; i <= w-2; i++){
    ans = min(ans, left[i]+right[i+1]);
  }
  if (ans > 250*6){
    cout << "NO" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
