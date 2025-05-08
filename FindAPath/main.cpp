#include <iostream>
#include <vector>
#include <array>
#include <windows.h>
using namespace std;
const int numRow = 6;
const int numCol = 9;

struct Coordinate {
  int x;
  int y;
};

bool visited(Coordinate cord, vector<Coordinate> list) {
  for(Coordinate  test : list) {
    if(test.x == cord.x && test.y == cord.y) return true;
  }
  return false;
}

vector<Coordinate> DFS(vector<Coordinate> &path, Coordinate &pos, Coordinate &dst, int maze[numRow][numCol]){
Coordinate right = {pos.x + 1, pos.y};
Coordinate down = {pos.x, pos.y +1};
Coordinate up = {pos.x, pos.y - 1};
Coordinate left = {pos.x -1, pos.y};
Coordinate next = {pos.x, pos.y};
if(down.y < numRow && maze[down.y][down.x] != 1 && !visited(down, path)) { //down
  next = down;
}
else if(right.x < numCol && maze[right.y][right.x] != 1 && !visited(right, path)) { //right
  next = right;
}
else if(up.y >= 0 && maze[up.y][up.x] != 1 && !visited(up, path)) { //up
  next = up;
}
else if(left.x >= 0 && maze[left.y][left.y] != 1 && !visited(left, path)) { //down
  next = left;
}
//cout << "(" << path.back().x << ", " << path.back().y << ")\n";
if(next.x == dst.x && next.y == dst.y) {
  path.push_back(next);
  return path;
}
else if(next.x != pos.x || next.y != pos.y){
  path.push_back(next);
  path = DFS(path, next, dst, maze);
}

return path;
}


int main() {
  srand(time(NULL));
  int maze[numRow][numCol] = {
    {0,0,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,1,0,0,0},
    {1,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,1,0,1,0},
    {0,0,0,1,1,0,0,0,0}};

  int x_src = 0;
  int y_src = 0;
  Coordinate src = {x_src, y_src};

  int x_dst = 5;
  int y_dst = 3;
  Coordinate dst = {x_dst, y_dst};

  vector<Coordinate> path;
  //depth first search
  path.push_back(src);
  path = DFS(path, src, dst, maze);
  for(int i = 0; i < numRow; i++){
    for (int j = 0; j < numCol; j++) {
      Coordinate test = {j, i};
      if(j == x_src && i == y_src) cout << "[*] ";
      else if(j == x_dst && i == y_dst) cout << "[$] ";
      else if(visited(test, path)) cout << "[-] ";
      else if(maze[i][j] == 1) cout << "[1] ";
      else if(maze[i][j] == 0) cout << "[0] ";
    }
    cout << "\n";
  };
  for(Coordinate j : path){
    cout << "(" << j.x << ", " << j.y << ") ";
  }
  return 0;
}

