// https://dmoj.ca/problem/ccc03s3
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tiles, r, c;
char grid[25][25];
vector<int> rooms;
int space;
void bfs(int y, int x, int dy, int dx) {
  y+=dy;
  x+=dx;
  if (y==-1||x==-1||y==r||x==c||grid[y][x]!='.'){
    return;
  } else {
    grid[y][x] = 'X';
    space++;
  }
  bfs(y,x,1,0);
  bfs(y,x,-1,0);
  bfs(y,x,0,1);
  bfs(y,x,0,-1);
}
int main() {
  cin >> tiles >> r >> c;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      char cur;
      cin >> cur;
      grid[i][j] = cur;
    }
  }
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (grid[i][j]=='.'){
        space = 1;
        grid[i][j] = 'X';
        bfs(i,j,1,0);
        bfs(i,j,-1,0);
        bfs(i,j,0,1);
        bfs(i,j,0,-1);
        rooms.push_back(space);
      }
    }
  }
  int a, b;
  sort(rooms.begin(), rooms.end());
  bool full = true;
  for (int i = rooms.size(); i >= 0; i--){
    if (tiles-rooms[i]>=0){
      tiles-=rooms[i];
    } else {
      full = false;
      a = rooms.size() - i - 1;
      b = tiles;
      if (a==1){
        cout << a << " room, " << b << " square metre(s) left over";
      } else {
        cout << a << " rooms, " << b << " square metre(s) left over"; 
      }
      break;
    }
  }
  if (full) {
    if (rooms.size()==1){
      cout << rooms.size() << " room, " << tiles << " square metre(s) left over";
    } else {
      cout << rooms.size() << " rooms, " << tiles << " square metre(s) left over"; 
    }
  }
  return 0; 
}
