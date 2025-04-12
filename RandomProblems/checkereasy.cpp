// https://dmoj.ca/problem/checkereasy
#include <iostream>
using namespace std;
int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m; n++; m++;
  int ar[n][m];
  int psa[n][m];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      ar[i][j] = 0;
      psa[i][j] = 0;
    }
  }
  while (true){
    int x, y, z;
    cin >> x >> y >> z;
    if (x==0){break;}
    ((x+y)%2==1) ? ar[x][y] = z : ar[x][y] = -z;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (i==0&&j==0){
        psa[i][j] = ar[i][j];
      } else if (i==0){
        psa[i][j] = ar[i][j] + psa[i][j-1];
      } else if (j==0){
        psa[i][j] = ar[i][j] + psa[i-1][j];
      } else {
        psa[i][j] = ar[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1]; 
      }
    }
  }
  while (true){
    int xi, yi, xj, yj;
    cin >> xi >> yi >> xj >> yj;
    if (xi==0){break;}
    int ans = psa[xj][yj] - psa[xi-1][yj] - psa[xj][yi-1] + psa[xi-1][yi-1];
    if ((xi+yi)%2==0){ans*=-1;}
    cout << ans << endl;
  }
  return 0;
}
