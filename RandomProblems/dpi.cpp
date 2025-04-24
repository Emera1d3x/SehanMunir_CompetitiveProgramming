// https://dmoj.ca/problem/dpi
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  int n;
  cin >> n;
  double perchance[n] = {};
  for (int i = 0; i < n; i++){cin >> perchance[i];}
  double dp[n+1][n+1] = {};
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    double p = perchance[i - 1];
    for (int j = 0; j <= i; j++) {
      dp[i][j] += dp[i-1][j] * (1-p);
      if (j > 0){dp[i][j] += dp[i-1][j-1] * p;}
    }
  }
  double ans = 0;
  for (int j = (n/2)+1; j <= n; j++) {
    ans += dp[n][j];
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
