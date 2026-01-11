// https://dmoj.ca/problem/ccc16s4
#include <bits/stdc++.h>
using namespace std;

int N;
int ar[401];
int psa[401];
int memo[401][401];

int sum(int l, int r) {
  return psa[r] - psa[l - 1];
}
int dp(int l, int r) {
  if (l == r) return 1;
  if (memo[l][r] != -1) return memo[l][r];
  for (int k = l; k < r; k++) {
    if (dp(l, k) && dp(k + 1, r) && sum(l, k) == sum(k + 1, r)) {
      return memo[l][r] = 1;
    }
  }
  for (int i = l; i < r; i++) {
    if (!dp(l, i)) {
      continue;
    }
    for (int j = i + 2; j <= r; j++) {
      if (dp(i + 1, j - 1) && dp(j, r) && sum(l, i) == sum(j, r)) {
        return memo[l][r] = 1;
      }
    }
  }
  return memo[l][r] = 0;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> ar[i];
    psa[i] = psa[i - 1] + ar[i];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      memo[i][j] = -1;
    }
  }
  int ans = 0;
  for (int l = 1; l <= N; l++) {
    for (int r = l; r <= N; r++) {
      if (dp(l, r)) {
        ans = max(ans, sum(l, r));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
