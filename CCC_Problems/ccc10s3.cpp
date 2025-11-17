// https://dmoj.ca/problem/ccc10s3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check (int sz, int h, const vector<int>& houses, int k){
  for (int i = 0; i < h; i++){
    int used = 1;
    int end = houses[i] + 2*sz;
    for (int t = 1; t < h; t++){
      int j = (i + t) % h;
      int place = houses[j];
      if (houses[i] > place){
        place += 1000000;
      }
      if (place > end){
        used++;
        end = place + 2*sz;
        if (used > k){
          break;
        }
      }
    }
    if (used <= k){
      return true;
    }
  }
  return false;
}

int main() 
{
  int h; cin >> h;
  vector<int> houses;
  for (int i = 0; i < h; i++){
    int a; cin >> a;
    houses.push_back(a);
  }
  sort(houses.begin(), houses.end());
  int k; cin >> k;
  int left = 0;
  int right = 1000000;
  while (left < right){
    int mid = left + (right - left)/2;
    bool z = check(mid, h, houses, k);
    if (z){
      right = mid;
    } else {
      left = mid + 1;
    }
  } 
  cout << left;
  return 0;
}
