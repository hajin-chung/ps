#include <bits/stdc++.h>
using namespace std;

int a[9][9];

bool check(int y, int x, int n) {
  for (int i = 0; i < 9; i++) {
    if (a[y][i] == n) return false;
    if (a[i][x] == n) return false;
    int by = (y/3)*3 + i/3, bx = (x/3)*3 + i%3;
    if (a[by][bx] == n) return false;
  }
  return true;
}

void print() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      printf("%d", a[i][j]);
    printf("\n");
  }
}

void rec(int y, int x) {
  if (y == 9 && x == 0) {
    print();
    exit(0);
  }

  if (a[y][x] == 0)  {
    for (int i = 1; i <= 9; i++)
      if (check(y, x, i)) {
        a[y][x] = i;
        rec(y+(x+1)/9, (x+1)%9);
        a[y][x] = 0;
      }
  } else {
    rec(y+(x+1)/9, (x+1)%9);
  }
}

int main() {
  char tmp[10];
  for (int i = 0; i < 9; i++) {
    scanf("%s", tmp);
    for (int j = 0; j < 9; j++)
      a[i][j] = tmp[j] - '0';
  }
  rec(0, 0);
}
