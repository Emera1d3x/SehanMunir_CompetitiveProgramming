// https://dmoj.ca/problem/coci08c4p4
#include <iostream>
#include <vector>
using namespace std;
int n = 0;
char grid[512][512];
vector<vector<int>> code;
void drawer(){
  for (vector<int> info: code){
    int size = info[0], startY = info[1], startX = info[2], colour = info[3];
    for (int i = startY; i < startY+size; i++){
      for (int j = startX; j < startX+size; j++){
        if (colour == 0){grid[i][j] = '0';}
        if (colour == 1){grid[i][j] = '1';}
      }
    }
  }
}
vector<int> breakDown(int sy, int sx, int ey, int ex, int sz){
  if (sz==2){
    int black = 0, white = 0;
    for (int i = sy; i < ey; i++){
      for (int j = sx; j < ex; j++){
        (grid[i][j]=='0') ? white++ : black++;
      }
    }
    if (white==4){code.push_back({sz/2,sy,sx,1});return {0,4,1};}
    else if (white==3){return {1,3,0};}
    else if (white==2){return {2,2,0};}
    else if (white==1){return {3,1,0};}
    else if (white==0){code.push_back({sz/2,sy,sx,0});return {4,0,1};}
  } else {
    int newSz = sz/2;
    vector<int> info1 = breakDown(sy,sx,sy+newSz,sx+newSz,newSz);
    vector<int> info2 = breakDown(sy+newSz,sx,sy+newSz+newSz,sx+newSz,newSz);
    vector<int> info3 = breakDown(sy,sx+newSz,sy+newSz,sx+newSz+newSz,newSz);
    vector<int> info4 = breakDown(sy+newSz,sx+newSz,sy+newSz+newSz,sx+newSz+newSz,newSz);
    info1.push_back(sy);
    info2.push_back(sy+newSz);
    info3.push_back(sy);
    info4.push_back(sy+newSz);
    info1.push_back(sx);
    info2.push_back(sx);
    info3.push_back(sx+newSz);
    info4.push_back(sx+newSz);
    vector<vector<int>> infos = {info1, info2, info3, info4};
    int minErrors = 2147483647;
    minErrors = min(
      info1[0]+info2[1]+info3[2]+info4[2],min(
      info1[0]+info2[2]+info3[1]+info4[2],min( 
      info1[0]+info2[2]+info3[2]+info4[1],min( 
      info1[1]+info2[0]+info3[2]+info4[2],min( 
      info1[1]+info2[2]+info3[0]+info4[2],min( 
      info1[1]+info2[2]+info3[2]+info4[0],min( 
      info1[2]+info2[2]+info3[1]+info4[0],min( 
      info1[2]+info2[2]+info3[0]+info4[1],min(
      info1[2]+info2[1]+info3[2]+info4[0],min(
      info1[2]+info2[1]+info3[0]+info4[2],min( 
      info1[2]+info2[0]+info3[1]+info4[2],
      info1[2]+info2[0]+info3[2]+info4[1]
    )))))))))));
    if(minErrors==(info1[0]+info2[1]+info3[2]+info4[2])){code.push_back({newSz,info1[3],info1[4],0});code.push_back({newSz,info2[3],info2[4],1});}
    else if(minErrors==(info1[0]+info2[2]+info3[1]+info4[2])){code.push_back({newSz,info1[3],info1[4],0});code.push_back({newSz,info3[3],info3[4],1});}
    else if(minErrors==(info1[0]+info2[2]+info3[2]+info4[1])){code.push_back({newSz,info1[3],info1[4],0});code.push_back({newSz,info4[3],info4[4],1});}
    else if(minErrors==(info1[1]+info2[0]+info3[2]+info4[2])){code.push_back({newSz,info2[3],info2[4],0});code.push_back({newSz,info1[3],info1[4],1});}
    else if(minErrors==(info1[1]+info2[2]+info3[0]+info4[2])){code.push_back({newSz,info3[3],info3[4],0});code.push_back({newSz,info1[3],info1[4],1});}
    else if(minErrors==(info1[1]+info2[2]+info3[2]+info4[0])){code.push_back({newSz,info4[3],info4[4],0});code.push_back({newSz,info1[3],info1[4],1});}
    else if(minErrors==(info1[2]+info2[2]+info3[1]+info4[0])){code.push_back({newSz,info4[3],info4[4],0});code.push_back({newSz,info3[3],info3[4],1});}
    else if(minErrors==(info1[2]+info2[2]+info3[0]+info4[1])){code.push_back({newSz,info3[3],info3[4],0});code.push_back({newSz,info4[3],info4[4],1});}
    else if(minErrors==(info1[2]+info2[1]+info3[2]+info4[0])){code.push_back({newSz,info4[3],info4[4],0});code.push_back({newSz,info2[3],info2[4],1});}
    else if(minErrors==(info1[2]+info2[1]+info3[0]+info4[2])){code.push_back({newSz,info3[3],info3[4],0});code.push_back({newSz,info2[3],info2[4],1});}
    else if(minErrors==(info1[2]+info2[0]+info3[1]+info4[2])){code.push_back({newSz,info2[3],info2[4],0});code.push_back({newSz,info3[3],info3[4],1});} 
    else if(minErrors==(info1[2]+info2[0]+info3[2]+info4[1])){code.push_back({newSz,info2[3],info2[4],0});code.push_back({newSz,info4[3],info4[4],1});}
    int totalWhite = info1[0] + info2[0] + info3[0] + info4[0];
    int totalBlack = info1[1] + info2[1] + info3[1] + info4[1];
    return {totalWhite, totalBlack, minErrors};
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> grid[i][j];
    }
  }
  vector<int> info = breakDown(0,0,n,n,n);
  cout << info[2] << endl;
  drawer();
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0; 
}
