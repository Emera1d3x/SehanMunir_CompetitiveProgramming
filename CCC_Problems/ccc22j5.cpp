// https://dmoj.ca/problem/ccc22j5
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(false); cin.tie(nullptr);
  int n, t;cin >> n >> t;
  vector<pair<int,int>> coordsR, coordsC;
  for (int i = 0; i < t; i++) {
    int r, c;
    cin >> r >> c;
    coordsR.push_back({r, c});
    coordsC.push_back({c, r});
  }
  coordsR.push_back({0, 0}); coordsR.push_back({n + 1, n + 1});
  coordsC.push_back({0, 0}); coordsC.push_back({n + 1, n + 1});
  sort(coordsR.begin(), coordsR.end());
  sort(coordsC.begin(), coordsC.end());
  int ans = 0;
  for (int i = 0; i < coordsR.size(); i++) {
    for (int j = i+1; j < coordsR.size(); j++) {
      int height = coordsR[j].first-coordsR[i].first-1;
      if (height <= ans) continue;
      int prev = 0;
      int bestWidth = 0;
      for (int k = 0; k < coordsC.size(); k++) {
        int col = coordsC[k].first;
        int row = coordsC[k].second;
        if (row > coordsR[i].first && row < coordsR[j].first) {
          bestWidth = max(bestWidth, col-prev-1);
          prev = col;
        }
      }
      bestWidth = max(bestWidth, n+1-prev-1);
      ans = max(ans, min(height, bestWidth));
    }
  }
  cout << ans << endl;
  return 0;
}
