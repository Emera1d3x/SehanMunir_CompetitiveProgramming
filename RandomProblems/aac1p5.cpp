// https://dmoj.ca/problem/aac1p5
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <utility>
using namespace std;

vector<bool> marked;
vector<int> dist;
vector<unordered_map<int, int>> adjList;
vector<pair<int, int>> power;
void dfs(int curNode){
  int even = 0, odd = 0;
  marked[curNode] = true;
  (dist[curNode]==0) ? even++ : odd++;
  for (auto neighbour : adjList[curNode]){
    int nextNode = neighbour.first;
    int weight = neighbour.second;
    if (!marked[nextNode]){
      dist[nextNode] = (dist[curNode] + weight) % 2;
      dfs(nextNode);
      even += power[nextNode].first;
      odd += power[nextNode].second;
    }
  }
  power[curNode] = {even, odd};
}
int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  long n;
  cin >> n;
  marked.resize(n, false);
  dist.resize(n, 0);
  adjList.resize(n);
  power.resize(n, {0, 0});

  for (int i = 0; i < n; i++){
    dist[i] = 0;
    marked[i] = 0;
  }
  for (int i = 0; i < n-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adjList[a-1][b-1] = (c%2);
    adjList[b-1][a-1] = (c%2);
  }
  dfs(0);
  long long even = 0, odd = 0;
  even = 1LL * power[0].first;
  odd = 1LL * power[0].second;
  long long evenPath = (1LL *(even*(even-1))+(odd*(odd-1)))/2;
  long long oddPath = (1LL * ((n*n)-n) - (1LL *(even*(even-1))+(odd*(odd-1))))/2;
  long long dif = abs(evenPath-oddPath);
  long long tempEven = 0, tempOdd = 0;
  for (auto x : power){
    tempEven = 1LL * even;
    tempOdd = 1LL * odd;
    evenPath = (1LL *((even-x.first+x.second)*((even-x.first+x.second)-1))+((odd-x.second+x.first)*((odd-x.second+x.first)-1)))/2;
    oddPath = (1LL * ((n*n)-n) - (1LL *((even-x.first+x.second)*((even-x.first+x.second)-1))+((odd-x.second+x.first)*((odd-x.second+x.first)-1))))/2;
    dif = min(dif,abs(evenPath-oddPath));
  }
  cout << dif << endl;
  return 0;
}
