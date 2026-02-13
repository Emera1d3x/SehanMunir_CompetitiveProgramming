// Official Solution
#include <bits/stdc++.h>
using namespace std;

struct Bird {
  char dir;
  int x;
  int y;
};
struct CompareX {
  bool operator()(const Bird& a, const Bird& b) const {
    return a.x > b.x;
  }
};
struct CompareY {
  bool operator()(const Bird& a, const Bird& b) const {
    return a.y > b.y;
  }
};
int main() {
  int n; cin >> n;
  map<int, priority_queue<Bird, vector<Bird>, CompareY>> NS; // key = x-axis, val = sorted bottom to top
  map<int, priority_queue<Bird, vector<Bird>, CompareX>> EW; // key = y-axis, val = sorted left to right
  map<int, priority_queue<Bird, vector<Bird>, CompareX>> diag1; // top left to bottom right, key = diagonal (the number), val = sorted left to right
  map<int, priority_queue<Bird, vector<Bird>, CompareX>> diag2; // bottom left to top right, key = diagonal (the number), val = sorted left to right
  for (int i = 0; i < n; i++){
    char d; int x, y; cin >> d >> x >> y;
    Bird b = {d, x, y};
    if (d=='N'||d=='S') NS[x].push(b);
    if (d=='E'||d=='W') EW[y].push(b);
    diag1[x+y].push(b);
    diag2[x-y].push(b);
  }
  long long ans = 0;
  for (auto& [x, pq] : NS) {
    vector<Bird> birds;
    while (!pq.empty()) { birds.push_back(pq.top()); pq.pop(); }
    int north = 0;
    for (auto& b : birds) {
      if (b.dir == 'N') north++;
      else if (b.dir == 'S') ans += north;
    }
  }
  for (auto& [y, pq] : EW) {
    vector<Bird> birds;
    while (!pq.empty()) { birds.push_back(pq.top()); pq.pop(); }
    int east = 0;
    for (auto& b : birds) {
      if (b.dir == 'E') east++;
      else if (b.dir == 'W') ans += east;
    }
  }
  for (auto& [key, pq] : diag1) {
    vector<Bird> birds;
    while (!pq.empty()) { birds.push_back(pq.top()); pq.pop(); }
    int north = 0, south = 0, east = 0, west = 0;
    for (auto& b : birds) {
      if (b.dir == 'N'){
        north++;
        ans += east;
      } else if (b.dir == 'W'){
        west++;
        ans += south;
      } else if (b.dir == 'S'){
        south++;
      } else {
        east++;
      }
    }
  }
  for (auto& [key, pq] : diag2) {
    vector<Bird> birds;
    while (!pq.empty()) { birds.push_back(pq.top()); pq.pop(); }
    int north = 0, south = 0, east = 0, west = 0;
    for (auto& b : birds) {
      if (b.dir == 'N'){
        north++;
      } else if (b.dir == 'W'){
        west++;
        ans += north;
      } else if (b.dir == 'S'){
        south++;
        ans += east;
      } else {
        east++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
