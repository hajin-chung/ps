#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105][105];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

bool check() {
  int i, j;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j] == 1)
        return true;
  return false;
}

void melt() {
  int cnt[105][105], visit[105][105], i, j;
  queue<pair<int, int>> Q;

  for (i = 0; i <= n+1; i++)
    for (j = 0; j <= m+1; j++)
      cnt[i][j] = visit[i][j] = 0;

  Q.push({0, 0});
  visit[0][0] = 1;
  while (!Q.empty()) {
    pair<int, int> ff = Q.front();
    Q.pop();
    int yy = ff.first, xx = ff.second;
    for (i = 0; i < 4; i++) {
      int ty = yy + dy[i];
      int tx = xx + dx[i];
      if (ty < 0 || ty > n+1 || tx < 0 || tx > m+1) continue;
      if (a[ty][tx] == 1) cnt[ty][tx]++;
      else if (a[ty][tx] == 0 && visit[ty][tx] == 0) {
        visit[ty][tx] = 1;
        Q.push({ty, tx});
      }
    }
  }

  for (i = 1; i <= n; i++)
    for (j = 1; j <=m ; j++)
      if (cnt[i][j] >= 2)
        a[i][j] = 0;
}

int main() {
  int i, j, ans = 0;

  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <=m; j++)
      scanf("%d", &a[i][j]);

  while (check()) {
    melt();
    ans++;
  }
  printf("%d\n", ans);
}
