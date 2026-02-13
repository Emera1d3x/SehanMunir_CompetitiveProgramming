// Official Solution
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n, k; cin >> n >> k;
  int ar[100001];
  for (int i = 0; i <= 100000; i++){
    ar[i] = 0;
  }
  for (int i = 0; i < n; i++){
    int a, b; char comma;
    cin >> a >> comma >> b;
    int frame = max(abs(a),abs(b));
    ar[frame] += 1;
  }
  int ans = 0;
  for (int i = 0; i <= 100000; i++){
    if (ar[i] >= k){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
