#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int n, m, ar, ac, br, bc;
  cin >> n >> m >> ar >> ac >> br >> bc;
  
  int test1 = abs(br - ar);
  int test2 = abs(bc - ac);
  
  if (br > ar) {
    if (ar - test1 < 1) {
      test1 = floor(br / 2.0);
    }
  } else if (br < ar) {
    if (ar + test1 > n) {
      test1 = ceil((n - br) / 2.0);
    }
  }
  if (bc > ac) {
    if (ac - test2 < 1) {
      test2 = floor(bc / 2.0);
    }
  } else if (bc < ac) {
    if (ac + test2 > m) {
      test2 = ceil((m - bc) / 2.0);
    }
  }
  cout << max(test1, test2) << endl;
  return 0;
}
