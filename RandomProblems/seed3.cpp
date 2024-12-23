// https://dmoj.ca/problem/seed3
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n, w, total;
  cin >> s >> n >> w;
  int difAr[s+1];
  total = 0;
  for (int i = 0; i <= s; i++){
    difAr[i] = 0;
  }
  for (int i = 0; i < w; i++){
    int l, r, z;
    cin >> l >> r >> z;
    difAr[l-1] += z;
    difAr[r] -= z;
  }
  for (int i = 1; i <= s; i++){
    difAr[i] += difAr[i-1];
  }
  for (int i = 0; i < s; i++){
    if (difAr[i]<n){total++;}
  }
  cout << total;
  return 0; 
}
