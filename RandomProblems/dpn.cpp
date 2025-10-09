// https://dmoj.ca/problem/dpn
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long c[400][400];
long long ar[401];
long long psa[401];

long long dp(int l, int r) {
  if (l == r) return 0;
  if (c[l][r] != 0) return c[l][r];
  long long best = LLONG_MAX;
  for (int k = l; k < r; k++) {
    long long cost = dp(l, k) + dp(k + 1, r) + (psa[r + 1] - psa[l]);
    best = min(best, cost);
  }
  c[l][r] = best;
  return best;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> ar[i];
    psa[i + 1] = psa[i] + ar[i];
  }
  cout << dp(0, N - 1) << "\n";
  return 0;
}
