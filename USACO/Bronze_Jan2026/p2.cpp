// USACO 2026 Second Contest, Bronze
// Problem 2. Moo Hunt
// https://usaco.org/index.php?page=viewproblem2&cpid=1564
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  int combs = 1 << n;
  vector<int> countA(combs, 0);
  vector<int> countB(combs, 0);
  vector<int> countC(combs, 0);
  for (int i = 0; i < k; i++) {
    int x, y, z; cin >> x >> y >> z; x--; y--; z--;
    int maskx = 1 << x;
    int masky = 1 << y;
    int maskz = 1 << z;
    int maskFull = maskx|masky|maskz;
    countA[maskx]++;
    countC[maskFull]++;
    countB[maskx|masky]++;
    countB[maskx|maskz]++;
  }
  combs = countA.size();
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < combs; mask++) {
      if (mask & (1 << i)) {
        countA[mask] += countA[mask^(1<<i)];
      }
    }
  }
  combs = countB.size();
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < combs; mask++) {
      if (mask & (1 << i)) {
        countB[mask] += countB[mask^(1<<i)];
      }
    }
  }
  combs = countC.size();
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < combs; mask++) {
      if (mask & (1 << i)) {
        countC[mask] += countC[mask^(1<<i)];
      }
    }
  }
  int best = -1;
  long long possibilities = 0;
  for (int mask = 0; mask < combs; mask++) {
    int score = countA[mask]-countB[mask]+countC[mask];
    if (score > best) {
      best = score;
      possibilities = 1;
    } else if (score == best) {
      possibilities++;
    }
  }
  cout << best << " " << possibilities << endl;
  return 0;
}
