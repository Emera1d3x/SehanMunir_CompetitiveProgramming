#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int t, k; cin >> t; cin >> k;
  while (t--){
    int n; string s;
    cin >> n >> s;
    int str[n]={0};
    int instructions[n]={0};
    // cout << n << " " << s << endl;
    for (int i = 0; i < n; i++){
      if (s[i] == 'O'){
        str[i] = 0;
      } else {
        str[i] = 1;
      }
    }
    bool flip = false;
    for (int i = n-1; i >= 0; i--){
      if (!flip){
        if (str[i] == 0){
          instructions[i] = 0;
          flip = !flip;
        } else {
          instructions[i] = 1;
        }
      } else {
        if (str[i] == 0){
          instructions[i] = 1;
        } else {
          instructions[i] = 0;
          flip = !flip;
        }
      }
    }
    bool possible;
    possible = true;
    if (possible){
      cout << "YES" << endl;
      if (k == 1){
        for (int i = 0; i < n; i++){
          if (instructions[i] == 0){
            cout << "O";
          } else {
            cout << "M";
          }
        } cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
