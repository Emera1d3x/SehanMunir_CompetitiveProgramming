#include <iostream>
using namespace std;


int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  bool ans = false;
  if ((N*3) != (9*A + 3*B + 4*C)){
  } else {
    N -= (3*A);
    N -= (2*C);
    if (N < 0){
    } else if ((2*C)%3 != 0){
    } else {
      ans = true;
    }
  }
  if (ans){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
