// https://dmoj.ca/problem/sac21ccp4
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, l, r;
  cin >> n >> q;
  int ar[n];
  int psa[n];
  psa[0] = 0;
  for (int i = 0; i < n; i++){
    cin >> ar[i];
    psa[i+1] = ar[i] + psa[i];
  }
  for (int i = 0; i < q; i++){
    cin >> l >> r;
    cout << (psa[r]-psa[l-1])/(r-l+1) << endl;
  }
  return 0; 
}
