// https://dmoj.ca/problem/dmopc17c3p2
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 0;
  cin >> n;
  vector<int> ar(n, 0);
  vector<int> arTest(n, 0);
  vector<int> steps;
  for (int i = 0; i < n; i++){
    int z = 0;
    cin >> z;
    ar[i] = z;
    arTest[i] = z;
  }
  for (int i = 1; i < n-1; i++){
    if (arTest[i-1]==1){
      arTest[i-1] = 0;
      (arTest[i]==0) ? arTest[i]=1 : arTest[i]=0;
      (arTest[i+1]==0) ? arTest[i+1]=1 : arTest[i+1]=0;
      steps.push_back(i+1);
    }
  }
  if (arTest[n-1]==arTest[n-2]){
    if (arTest[n-1]==1){steps.push_back(n);}
    cout << steps.size() << endl;
    for (int x : steps){
      cout << x << endl;
    }
  } else {
    steps.clear();
    steps.push_back(1);
    (ar[0]==0) ? ar[0]=1 : ar[0]=0;
    (ar[1]==0) ? ar[1]=1 : ar[1]=0;
    for (int i = 1; i < n-1; i++){
      if (ar[i-1]==1){
        ar[i-1] = 0;
        (ar[i]==0) ? ar[i]=1 : ar[i]=0;
        (ar[i+1]==0) ? ar[i+1]=1 : ar[i+1]=0;
        steps.push_back(i+1);
      }
    }
    if (ar[n-1]==1){steps.push_back(n);}
    cout << steps.size() << endl;
    for (int x : steps){
      cout << x << endl;
    }
  }
  return 0;
}
