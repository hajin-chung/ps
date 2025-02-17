#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main() {
  int n, m, k;
  char a[1005][1005];
  int d[1005][1005];
  queue<pii> Q;
  pii s, e;
  
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", &a[i]);
  scanf("%d %d %d %d", &s.fi, &s.se, &e.fi, &e.se);
  s.fi--; s.se--; e.fi--; e.se--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      d[i][j] = INF;

  Q.push(s);
  d[s.fi][s.se] = 0;
  while (!Q.empty()) {
    auto [yy, xx] = Q.front(); Q.pop();
    for (int i = 0; i < 4; i++)
      for (int j = 1; j <= k; j++) {
        int ty = dy[i]*j + yy;
        int tx = dx[i]*j + xx;
        if (ty < 0 || ty >= n || tx < 0 || tx >= m) break;
        if (a[ty][tx] == '#') break;
        if (d[ty][tx] < d[yy][xx]+1) break;
        if (d[ty][tx] == INF) {
          d[ty][tx] = d[yy][xx] + 1;
          if (ty == e.fi && tx == e.se) {
            printf("%d\n", d[ty][tx]);
            return 0;
          }
          Q.push({ty, tx});
        }
      }
  }
  printf("-1\n");
}
