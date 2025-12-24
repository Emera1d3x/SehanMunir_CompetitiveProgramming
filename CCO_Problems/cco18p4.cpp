// https://dmoj.ca/problem/cco18p4
#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, k;
  cin >> r >> c >> k;
  int lowR = 1, highR = r;
  int lowC = 1, highC = c;
  while (lowR != highR || lowC != highC) {
    int midR = (lowR + highR) / 2;
    int midC = (lowC + highC) / 2;

    cout << "? " << midR << " " << midC << endl;
    cout.flush();
    long long a;
    cin >> a;

    long long b = LLONG_MAX;
    if (midR + 1 <= highR) {
      cout << "? " << (midR + 1) << " " << midC << endl;
      cout.flush();
      cin >> b;
    }
    long long z = LLONG_MAX;
    if (midC + 1 <= highC) {
      cout << "? " << midR << " " << (midC + 1) << endl;
      cout.flush();
      cin >> z;
    }

    if (a < b) {
      highR = midR;
    } else if (a == b) {
      lowR = midR;
      highR = midR;
    } else {
      lowR = midR + (lowR + 1 == highR);
    }
    if (a < z) {
      highC = midC;
    } else if (a == z) {
      lowC = midC;
      highC = midC;
    } else {
      lowC = midC + (lowC + 1 == highC);
    }
  }

  cout << "? " << lowR << " " << lowC << endl;
  cout.flush();
  long long ans;
  cin >> ans;
  cout << "! " << ans << endl;
  cout.flush();
  return 0;
}
