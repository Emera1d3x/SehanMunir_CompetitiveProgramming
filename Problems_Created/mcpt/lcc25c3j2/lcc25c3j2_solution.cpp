#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
  int n, r; cin >> n >> r;
  vector<int> nums(n);
  vector<int> freqs;
  if (r >= n){cout << 0 << endl; return 0;}
  for (int i = 0; i < n; i++){cin >> nums[i];}
  sort(nums.begin(), nums.end());
  int minVal = nums[0];
  vector<int> nums_filtered;
  for (auto a : nums){
    if (a != minVal){
      nums_filtered.push_back(a);
    }
  }
  if (nums_filtered.size() == 0){cout << 0 << endl; return 0;}
  int cur = nums_filtered[0]; int freq = 0;
  for (auto a : nums_filtered){
    if (a == cur){
      freq++;
    } else {
      freqs.push_back(freq);
      cur = a; freq = 1;
    }
  }
  freqs.push_back(freq);
  sort(freqs.begin(), freqs.end(), greater<int>());
  int total = nums_filtered.size();
  for (int i = 0; i < r-1; i++){
    total -= freqs[i];
    if (total == 0){
      break;
    }
  }
  cout << total;
  return 0;
}
