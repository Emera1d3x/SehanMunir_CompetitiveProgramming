// https://dmoj.ca/problem/dmpg15s5
#include <vector>
#include <iostream>
using namespace std;

int main() 
{
  int n, m, x, y, w, h; cin >> n >> m; n+=1;
  bool ar[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      ar[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++){
    cin >> x >> y >> w >> h;
    ar[x][y] ^= 1;
    ar[x+w][y] ^= 1;
    ar[x][y+h] ^= 1;
    ar[x+w][y+h] ^= 1;
  }
  int white = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i==0&&j==0){
        ar[i][j] = ar[i][j];
      } else if (i==0){
        ar[i][j] ^= ar[i][j-1];
      } else if (j==0){
        ar[i][j] ^= ar[i-1][j];
      } else {
        ar[i][j] ^= ar[i-1][j];
        ar[i][j] ^= ar[i][j-1];
        ar[i][j] ^= ar[i-1][j-1];
      }
      if (ar[i][j]){
        white++;
      }
    }
  }
  cout << white << endl;
  return 0;
}
