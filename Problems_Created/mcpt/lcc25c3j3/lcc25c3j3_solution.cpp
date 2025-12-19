#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
  int n, m, l, as, q;
  cin >> n >> m >> l >> as >> q;
  int level[l];
  int competitors[as][4];
  // 0 is direction: 0 = N, 1 = E, 2 = S, 3 = W
  // 1 is row
  // 2 is column
  // 3 is snowball size
  int grid[n][m];
  for (int i = 0; i < n; i++){for (int j = 0; j < m; j++){grid[i][j]=0;}}
  for (int i = 0; i < l; i++){
    cin >> level[i];
  }
  for (int i = 0; i < as; i++){
    int r, c; cin >> r >> c;
    competitors[i][0] = 0;
    competitors[i][1] = r-1;
    competitors[i][2] = c-1;
    competitors[i][3] = 0;
  }
  while (q--){
    int a; string command; cin >> a >> command; a--;
    if (command == "PUSH"){
      int i = competitors[a][1];
      int j = competitors[a][2];
      int direction = competitors[a][0];
      if (direction == 0){
        if (i-1 >= 0){
          i--; competitors[a][1] -= 1;
          if (grid[i][j] < l){
            competitors[a][3] += level[grid[i][j]];
            grid[i][j] += 1;
          }
        }
      } else if (direction == 1){
        if (j+1 < m){
          j++; competitors[a][2] += 1;
          if (grid[i][j] < l){
            competitors[a][3] += level[grid[i][j]];
            grid[i][j] += 1;
          }
        }
      } else if (direction == 2){
        if (i+1 < n){
          i++; competitors[a][1] += 1;
          if (grid[i][j] < l){
            competitors[a][3] += level[grid[i][j]];
            grid[i][j] += 1;
          }
        }
      } else {
        if (j-1 >= 0){
          j--; competitors[a][2] -= 1;
          if (grid[i][j] < l){
            competitors[a][3] += level[grid[i][j]];
            grid[i][j] += 1;
          }
        }
      }
    } else if (command == "TURN_RIGHT"){
      competitors[a][0] += 1;
      competitors[a][0] %= 4;
    } else {
      competitors[a][0] += 3;
      competitors[a][0] %= 4;
    }
  }
  int mx = 0;
  for (int i = 0; i < as; i++){
    mx = max(mx, competitors[i][3]);
  }
  cout << mx << endl;
  return 0;
}
