// https://dmoj.ca/problem/dt16l1p1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
  int ans, a, b;
  string op;
  cin>>a>>op>>b;
  if (op=="$"){ans=(a*a)-(b*b);} 
  else if(op=="@"){ans=(b*a)/(2*a-3);}
  else{ans=(a*b)*(b-14);}
  cout<<"The equation "<<a<<" "<<op<<" "<<b<<" is equal to "<<ans<<".";
  return 0; 
}
