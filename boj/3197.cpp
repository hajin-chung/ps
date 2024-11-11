#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n, m, d[1505][1505];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
char a[1505][1505];
priority_queue<pip, vector<pip>, greater<pip>> q;
pii s, e;

int main() {
  scanf("%d%d",&n,&m);
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    scanf("%s", &a[i][1]);
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 'L') {
        a[i][j] = '.';
        if (!flag) {
          s = {i, j};
          flag = true;
        } else {
          e = {i, j};
        }
      }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      d[i][j] = INF;
  d[s.fi][s.se] = 0;
  q.push({0, s});
  while (!q.empty()) {
    auto [dist, curr] = q.top(); q.pop();
    auto [yy, xx] = curr;
    if (dist > d[yy][xx]) continue;
    for (int i = 0; i < 4; i++) {
      int ty = yy + dy[i];
      int tx = xx + dx[i];
      if (!(0 < ty && ty <= n && 0 < tx && tx <= m)) continue;
      if (d[ty][tx] > d[yy][xx] + (a[ty][tx] == 'X')) {
        d[ty][tx] = d[yy][xx] + (a[ty][tx] == 'X');
        q.push({d[ty][tx], {ty, tx}});
      }
    }
  }
  printf("%d\n", (int)ceil((double)d[e.fi][e.se]/2));
}
