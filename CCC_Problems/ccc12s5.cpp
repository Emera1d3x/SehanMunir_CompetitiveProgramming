// https://dmoj.ca/problem/ccc12s5
#include <bits/stdc++.h>
using namespace std;

bool cat[26][26];
int memo[26][26];

int dp(int r, int c) {
  if (cat[r][c]) return memo[r][c] = 0;
  if (memo[r][c] != -1) return memo[r][c];
  if (r == 1 && c == 1) {
    return memo[r][c] = 1;
  }
  memo[r][c] = 0;
  if (r > 1) {
    memo[r][c] += dp(r - 1, c);
  }
  if (c > 1) {
    memo[r][c] += dp(r, c - 1);
  }
  return memo[r][c];
}

int main() {
  cin.sync_with_stdio(false); cin.tie(nullptr);
  int r, c, k; cin >> r >> c >> k;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      memo[i][j] = -1;
      cat[i][j] = false;
    }
  }
  for (int i = 0; i < k; i++) {
    int rc, cc; cin >> rc >> cc;
    cat[rc][cc] = true;
  }
  int ans = dp(r, c);
  cout << ans << endl;
  return 0;
}
