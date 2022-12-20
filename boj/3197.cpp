#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int> > Q;
int n, m;
int a[1505][1505];
int d[1505][1505], path[1505][1505];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int sx, sy, ex, ey;

int main() {
  int i, j, k;
  char t[1505];
  int cnt = 0, flag = 0;
  int yy, xx, ty, tx;

  scanf("%d %d", &n, &m);
  for(i=1; i<=n; i++) {
    scanf("%s", t);
    for(j=1; j<=m; j++) {
      d[i][j] = -1;
      path[i][j] = 1000000000;
      if (t[j-1] == 'X') a[i][j] = 1;
      else if(t[j-1] == 'L') {
        if (sx == 0) {
          sy = i;
          sx = j;
        } else {
          ey = i;
          ex = j;
        }
      }
    }
  }

  for(i=1; i<=n; i++) {
    for(j=1; j<=m; j++) {
      if (d[i][j] == -1 && a[i][j] == 0) {
        Q.push({i, j});
        d[i][j] = 0;
        while(!Q.empty()) {
          yy = Q.front().first;
          xx = Q.front().second;
          Q.pop();
          for(k=0; k<4; k++) {
            ty = yy + dy[k];
            tx = xx + dx[k];
            if(ty > 0 && ty <= n && tx > 0 && tx <= m) {
              if (a[ty][tx] == 1 && (d[ty][tx] == -1 || d[ty][tx] > d[yy][xx]+1)) {
                d[ty][tx] = d[yy][xx] + 1; 
                Q.push({ty, tx});
              } else if(a[ty][tx] == 0 && d[ty][tx] == -1) {
                d[ty][tx] = 0;
                Q.push({ty, tx});
              }
            }
          }
        }
      }
    }
  }

  Q.push({sy, sx});
  path[sy][sx] = 0;
  while(!Q.empty()) {
    yy = Q.front().first;
    xx = Q.front().second;
    Q.pop();
    for(k=0; k<4; k++) {
      ty = yy + dy[k];
      tx = xx + dx[k];
      if (ty > 0 && ty <= n && tx > 0 && tx <= m) {
        if (a[ty][tx] == 1 && a[yy][xx] == 1) {
        }
      }
    }
  }

  for(i=1; i<=n; i++) {
    for(j=1 ; j<=m; j++) printf("%d ", path[i][j]);
    printf("\n");
  }

  printf("%d\n", path[ey][ex]);
}