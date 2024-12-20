#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n;
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1}, dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
vector<string> s;
int a[1005][1005], chk[1005][1005], adj[1010][1010], sz[1010];
int k = 4;

void floodfill(int u, int yy, int xx) {
  queue<pii> Q;
  Q.push({yy, xx});
  while (!Q.empty()) {
    auto [yy, xx] = Q.front(); Q.pop();
    sz[u]++;
    a[yy][xx] = u;
    for (int i = 0; i < 4; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
      if (s[yy][xx] != s[ty][tx]) continue;
      if (a[ty][tx] == 0) Q.push({ty, tx});
    }
  }
}

void dfs(int yy, int xx) {
  if (chk[yy][xx]) return;
  if (a[yy][xx] == 0) floodfill(k++, yy, xx);
  int u = a[yy][xx];
  chk[yy][xx] = true;
  for (int i = 0; i < 8; i++) {
    int ty = yy+dy[i];
    int tx = xx+dx[i];
    if (ty == -1) { adj[0][u] = adj[u][0] = 1; }
    if (ty == n) { adj[1][u] = adj[u][1] = 1; }
    if (tx == -1) { adj[2][u] = adj[u][2] = 1; }
    if (tx == n) { adj[3][u] = adj[u][3] = 1; }
    if (ty == -1 || ty == n || tx == -1 || tx == n) continue;
    if (s[ty][tx] == '.') continue;
    if (s[yy][xx] == s[ty][tx]) {
      dfs(ty, tx);
    } else {
      dfs(ty, tx);
      int v = a[ty][tx];
      adj[u][v] = adj[v][u] = 1;
    }
  }
}

vector<int> dij(int u) {
  vector<int> d(k, INF);
  d[u] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, u});
  while (!pq.empty()) {
    auto [dist, u] = pq.top(); pq.pop();
    if (d[u] < dist) continue;
    for (int v = 0; v < k; v++)
      if (d[v] > d[u] + adj[u][v]) {
        d[v] = d[u] + adj[u][v];
        pq.push({d[v], v});
      }
  }
  return d;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; s.resize(n);
  for (auto &si: s) cin>>si;
  dfs(0, 1);
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++) {
      if (adj[i][j]) adj[i][j] = sz[j];
      else adj[i][j] = INF;
    }
  int ans = INF;
  vector<int> d0 = dij(0);
  vector<int> d2 = dij(2);
  ans = min(ans, d0[1]);
  ans = min(ans, d0[2]);
  ans = min(ans, d2[3]);
  cout<<ans<<"\n";
}
