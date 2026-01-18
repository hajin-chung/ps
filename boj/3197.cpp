#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n, m, wd[1505][1505], d[1505][1505];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
char a[1505][1505];
priority_queue<pip, vector<pip>, greater<pip>> q;
pii s, e;

int main() {
  scanf("%d%d",&n,&m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      wd[i][j] = d[i][j] = INF;
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    scanf("%s", &a[i][1]);
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'L') {
        a[i][j] = '.';
        if (!flag) {
          s = {i, j};
          flag = true;
        } else {
          e = {i, j};
        }
      }
      if (a[i][j] == '.') {
        wd[i][j] = 0;
        q.push({0, {i, j}});
      }
    }
  }
  d[s.fi][s.se] = 0;
  while (!q.empty()) {
    auto [dist, curr] = q.top(); q.pop();
    auto [yy, xx] = curr;
    if (dist > wd[yy][xx]) continue;
    for (int i = 0; i < 4; i++) {
      int ty = yy + dy[i];
      int tx = xx + dx[i];
      if (!(0 < ty && ty <= n && 0 < tx && tx <= m)) continue;
      if (wd[ty][tx] > wd[yy][xx] + (a[ty][tx] == 'X')) {
        wd[ty][tx] = wd[yy][xx] + (a[ty][tx] == 'X');
        q.push({wd[ty][tx], {ty, tx}});
      }
    }
  }
  q.push({0, s});
  while (!q.empty()) {
    auto [dist, curr] = q.top(); q.pop();
    auto [yy, xx] = curr;
    if (dist > d[yy][xx]) continue;
    for (int i = 0; i < 4; i++) {
      int ty = yy + dy[i];
      int tx = xx + dx[i];
      if (!(0 < ty && ty <= n && 0 < tx && tx <= m)) continue;
      if (d[ty][tx] > max(d[yy][xx], wd[ty][tx])) {
        d[ty][tx] = max(d[yy][xx], wd[ty][tx]);
        q.push({d[ty][tx], {ty, tx}});
      }
    }
  }
  printf("%d\n", d[e.fi][e.se]);
}
