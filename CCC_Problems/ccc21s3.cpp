//https://dmoj.ca/problem/ccc21s3
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

long long costCalc(long long pos, int n, long long p[], long long w[], long long d[]) {
  long long total = 0;
  for (int i = 0; i < n; i++) {
    long long distance = abs(pos - p[i]);
    if (distance > d[i]) {
      total += (distance - d[i]) * w[i];
    }
  }
  return total;
}

int main() {
  int n;
  cin >> n;
  long long p[n], w[n], d[n];
  long long maxp = 0;
  long long minp = numeric_limits<long long>::max();
  
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> w[i] >> d[i];
    maxp = max(p[i], maxp);
    minp = min(p[i], minp);
  }
  
  long long left = minp;
  long long right = maxp;
  long long ans = numeric_limits<long long>::max();
  
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    long long costMid = costCalc(mid, n, p, w, d);
    long long costRight = costCalc(mid + 1, n, p, w, d);
    ans = min(ans, costMid);
    if (costRight < costMid) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
