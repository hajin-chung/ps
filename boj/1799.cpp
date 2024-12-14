#include <bits/stdc++.h>
using namespace std;

int n, a[10][10], ans, tmp[10][10];
int dy[4] = {1, 1, -1, -1}, dx[4] = {1, -1, 1, -1};

void rec(int yy, int xx, int cnt) {
  if (yy == n) {
    if (cnt > ans) {
      cout<<cnt<<"\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          cout<<a[i][j]<<" ";
        cout<<"\n";
      }
    }
    ans = max(ans, cnt);
    return;
  }
  int flag = a[yy][xx] == 0;
  if (flag) {
    tmp[yy][xx] = 1;
    a[yy][xx]++;
    for (int k = 0; k < 4; k++) {
      int ty = yy + dy[k], tx = xx + dx[k];
      while (ty >= 0 && ty < n && tx >= 0 && tx < n) {
        a[ty][tx]++;
        ty += dy[k];
        tx += dy[k];
      }
    }
  }
  int nx = xx+1, ny = yy;
  if (nx == n) { nx = 0; ny++; }
  rec(ny, nx, cnt+flag);
  if (flag) {
    tmp[yy][xx] = 0;
    a[yy][xx]--;
    for (int k = 0; k < 4; k++) {
      int ty = yy + dy[k], tx = xx + dx[k];
      while (ty >= 0 && ty < n && tx >= 0 && tx < n) {
        a[ty][tx]--;
        ty += dy[k];
        tx += dy[k];
      }
    }
    rec(ny, nx, cnt);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin>>a[i][j];
      a[i][j] = 1-a[i][j];
    }
  rec(0, 0, 0);
  cout<<ans<<"\n";
}
