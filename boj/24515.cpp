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
      if (ty < 0 || ty >= n || tx < 0 || tx >= n) continue;
      if (s[yy][xx] != s[ty][tx]) continue;
      if (a[ty][tx] == 0) Q.push({ty, tx});
    }
  }
}

void color() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] != '.' && a[i][j] == 0) {
        sz.push_back(0);
        floodfill(k++, i, j);
      }
}

int dij_top() {
  int ret = INF;
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  int d[1010][1010];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == 0 && j > 0) {
        d[i][j] = sz[a[i][j]];
        pq.push({d[i][j], {i, j}});
      } else d[i][j] = INF;
    }
  while (!pq.empty()) {
    auto [dist, yx] = pq.top(); pq.pop();
    auto [yy, xx] = yx;
    if (dist > d[yy][xx]) continue; 
    for (int i = 0; i < 8; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if ((ty == 0 && tx == 0) || (ty == n || tx == n)) continue;
      if (ty < 0 || ty > n || tx < 0 || tx > n) continue;
      int w = 0;
      if (a[ty][tx] != a[yy][xx]) w = sz[a[ty][tx]];
      if (d[ty][tx] > d[yy][xx] + w) {
        d[ty][tx] = d[yy][xx] + w;
        pq.push({d[ty][tx], {ty, tx}});
      }
    }
  }
  for (int i = 0; i < n-1; i++)
    ret = min(ret, d[n-1][i]);
  for (int i = 0; i < n-1; i++)
    ret = min(ret, d[i][0]);
  return ret;
}

int dij_left() {
  int ret = INF;
  priority_queue<pip, vector<pip>, greater<pip>> pq;
  int d[1010][1010];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (j == 0 && i > 0) {
        d[i][j] = sz[a[i][j]];
        pq.push({d[i][j], {i, j}});
      } else d[i][j] = INF;
    }
  while (!pq.empty()) {
    auto [dist, yx] = pq.top(); pq.pop();
    auto [yy, xx] = yx;
    if (dist > d[yy][xx]) continue; 
    for (int i = 0; i < 8; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i]; if ((ty == 0 && tx == 0) || (ty == n || tx == n)) continue;
      if (ty < 0 || ty > n || tx < 0 || tx > n) continue;
      int w = 0;
      if (a[ty][tx] != a[yy][xx]) w = sz[a[ty][tx]];
      if (d[ty][tx] > d[yy][xx] + w) {
        d[ty][tx] = d[yy][xx] + w;
        pq.push({d[ty][tx], {ty, tx}});
      }
    }
  }
  for (int i = 0; i < n-1; i++)
    ret = min(ret, d[i][n-1]);
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; s.resize(n);
  for (auto &si: s) cin>>si;
  color();
  cout<<min(dij_top(), dij_left())<<"\n";
}
