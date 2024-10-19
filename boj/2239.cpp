#include <bits/stdc++.h>
using namespace std;

int a[9][9];

bool checkRow() {
  for (int i = 0; i < 9; i++) {
    bool chk[10];
    for (int j = 0; j < 10; j++) chk[j] = false;
    for (int j = 0; j < 9; j++) {
      if (a[i][j] > 0 && chk[a[i][j]]) return false;
      else chk[a[i][j]] = true;
    }
  }
  return true;
}

bool checkCol() {
  for (int i = 0; i < 9; i++) {
    bool chk[10];
    for (int j = 0; j < 10; j++) chk[j] = false;
    for (int j = 0; j < 9; j++) {
      if (a[j][i] > 0 && chk[a[j][i]]) return false;
      else chk[a[j][i]] = true;
    }
  }
  return true;
}

bool checkBlock() {
  for (int i = 0; i < 3; i++) 
    for (int j = 0; j < 3; j++) {
      bool chk[10];
      for (int k = 0; k < 10; k++) chk[k] = false;
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++) {
          int y = i*3 + k, x = j*3 + l;
          if (a[y][x] > 0 && chk[a[y][x]]) return false;
          else chk[a[y][x]] = true;
        }
    }
  return true;
}

bool check() {
  return checkRow() && checkCol() && checkBlock();
}

void print() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      printf("%d", a[i][j]);
    printf("\n");
  }
}

void dfs(int y, int x) {
  if (y == 9 && x == 0) {
    print();
    exit(0);
  }

  if (a[y][x] == 0) 
    for (int i = 1; i <= 9; i++) {
      a[y][x] = i;
      if (check()) dfs(y+(x+1)/9, (x+1)%9);
      a[y][x] = 0;
    }
  else dfs(y+(x+1)/9, (x+1)%9);
}

int main() {
  char tmp[10];
  for (int i = 0; i < 9; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < 9; j++)
      a[i][j] = tmp[j] - '0';
  }
  dfs(0, 0);
}
