#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n;
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1}, dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
vector<string> s;
int a[1005][1005], chk[1005][1005];
int k = 1;
vector<int> sz(1);

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
      if (ty <= 0 || ty > n || tx <= 0 || tx > n) continue;
      if (s[yy-1][xx-1] != s[ty-1][tx-1]) continue;
      if (a[ty][tx] == 0) Q.push({ty, tx});
    }
  }
}

void color() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (s[i-1][j-1] != '.' && a[i][j] == 0) {
        sz.push_back(0);
        floodfill(k++, i, j);
      }
}

int dij() {
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  int d[1005][1005];
  for (int i = 0; i <= n+1; i++)
    for (int j = 0; j <= n+1; j++)
      d[i][j] = INF;
  d[0][2] = 0;
  pq.push({0, {0, 2}});
  while (!pq.empty()) {
    auto [dist, yx] = pq.top(); pq.pop();
    auto [yy, xx] = yx;
    if (dist > d[yy][xx]) continue;
    for (int i = 0; i < 8; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if (ty < 0 || ty > n+1 || tx < 0 || tx > n+1) continue;
      int w = 0;
      if (a[ty][tx] != a[yy][xx]) w = sz[a[ty][tx]];
      if (d[ty][tx] > d[yy][xx] + w) {
        d[ty][tx] = d[yy][xx] + w;
        pq.push({d[ty][tx], {ty, tx}});
      }
    }
  }
  int ret = INF;
  for (int i = 0; i <= n-1; i++) ret = min(ret, d[n+1][i]);
  for (int i = 2; i <= n; i++) ret = min(ret, d[i][0]);
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; s.resize(n);
  for (auto &si: s) cin>>si;
  color();
  sz.push_back(0);
  for (int i = 2; i <= n+1; i++) a[0][i] = k;
  for (int i = 1; i <= n-1; i++) a[i][n+1] = k;
  k++;
  sz.push_back(0);
  for (int i = 0; i <= n-1; i++) a[n+1][i] = k;
  for (int i = 2; i <= n; i++) a[i][0] = k;
  k++;
  sz[0] = INF;
  cout<<dij()<<"\n";
}
