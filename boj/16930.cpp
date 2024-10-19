#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main() {
  int n, m, k;
  char a[1005][1005];
  int d[1005][1005];
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  pii s, e;
  
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", &a[i]);
  scanf("%d %d %d %d", &s.fi, &s.se, &e.fi, &e.se);
  s.fi--; s.se--; e.fi--; e.se--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      d[i][j] = INF;

  pq.push({0, s});
  d[s.fi][s.se] = 0;
  while (!pq.empty()) {
    pip t = pq.top(); pq.pop();
    int yy = t.se.fi, xx = t.se.se;
    if (d[yy][xx] < t.fi) continue;
    if (e.fi == yy && e.se == xx) break;
    for (int i = 0; i < 4; i++)
      for (int j = 1; j <= k; j++) {
        int ty = dy[i]*j + yy;
        int tx = dx[i]*j + xx;
        if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
        if (a[ty][tx] == '#') break;
        if (d[ty][tx] < d[yy][xx] + 1) continue;
        d[ty][tx] = d[yy][xx] + 1;
        pq.push({d[ty][tx], {ty, tx}});
      }
  }
  if (d[e.fi][e.se] == INF) printf("-1\n");
  else printf("%d\n", d[e.fi][e.se]);
}
