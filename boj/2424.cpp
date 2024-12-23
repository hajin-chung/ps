// 6:18
#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 1000000000
#define N 700
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<string> a(n);
  for (auto &si : a) cin>>si;
  int vd[N+1][N+1], d[N+1][N+1], yd[N+1][N+1];
  pii sy, sv, tt;
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      vd[i][j] = d[i][j] = yd[i][j] = INF;
      if (a[i][j] == 'Y') sy = {i, j};
      if (a[i][j] == 'V') sv = {i, j};
      if (a[i][j] == 'T') tt = {i, j};
    }
  vd[sv.fi][sv.se] = 0;
  pq.push({0, sv});
  while (!pq.empty()) {
    auto [dist, yx] = pq.top(); pq.pop();
    auto [yy, xx] = yx;
    for (int i = 0; i < 4; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
      if (a[ty][tx] == 'I') continue;
      if (vd[ty][tx] > dist + 1) {
        vd[ty][tx] = dist+1;
        pq.push({dist+1, {ty, tx}});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int k = 0, j = 0, mn = INF;
    while (j <= m) {
      if (j == m || a[i][j] == 'I') {
        for (; k > 0; k--) d[i][j-k] = min(d[i][j-k], mn);
        mn = INF;
      }
      mn = min(mn, vd[i][j]);
      j++; k++;
    }
  }
  for (int i = 0; i < m; i++) {
    int k = 0, j = 0, mn = INF;
    while (j <= n) {
      if (j == n || a[j][i] == 'I') {
        for (; k > 0; k--) d[j-k][i] = min(d[j-k][i], mn);
        mn = INF;
      }
      mn = min(mn, vd[j][i]);
      j++; k++;
    }
  }
  yd[sy.fi][sy.se] = 0;
  pq.push({0, sy});
  while (!pq.empty()) {
    auto [dist, yx] = pq.top(); pq.pop();
    auto [yy, xx] = yx;
    for (int i = 0; i < 4; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if (ty < 0 || ty >= n || tx < 0 || tx >= m) continue;
      if (a[ty][tx] == 'I') continue;
      if (yd[ty][tx] > dist + 1 && dist+1 < d[ty][tx]) {
        yd[ty][tx] = dist+1;
        pq.push({dist+1, {ty, tx}});
      }
    }
  }
  if (yd[tt.fi][tt.se] == INF) cout<<"NO\n";
  else cout<<"YES\n";
}
