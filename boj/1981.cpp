#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n, a[105][105];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

int dij(int mn) {
  priority_queue<pip, vector<pip>, greater<pip>> q;
  int d[105][105];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      d[i][j] = INF;
  d[1][1] = a[1][1];
  q.push({d[1][1], {1, 1}});
  while (!q.empty()) {
    auto [dist, curr] = q.top(); q.pop();
    auto [yy, xx] = curr;
    if (dist > d[yy][xx]) continue;
    for (int i = 0; i < 4; i++) {
      int ty = yy + dy[i];
      int tx = xx + dx[i];
      if (!(0 < ty && ty <= n && 0 < tx && tx <= n)) continue;
      if (a[ty][tx] < mn) continue;
      if (d[ty][tx] > max(d[yy][xx], a[ty][tx])) {
        d[ty][tx] = max(d[yy][xx], a[ty][tx]);
        q.push({d[ty][tx], {ty, tx}});
      }
    }
  }
  return d[n][n];
}

int main() {
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);
  int ans = INF;
  for (int i = 0; i <= 200; i++) {
    int d = dij(i);
    if (d == INF) continue;
    ans = min(ans, d - i);
  }
  printf("%d\n", ans);
}
