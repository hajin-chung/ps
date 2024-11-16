#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define N 500
#define Q 100000
#define H 1000000
using namespace std;

typedef pair<int, int> pii;
struct Height { int h; vector<pii> points; };
int n, m, q, a[N][N], lo[Q], hi[Q], p[N*N];
vector<pii> h[H+5], queries;
vector<Height> heights;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

int find(int u) { 
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}
void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin>>a[i][j];
      h[a[i][j]].push_back({i, j});
    }
  for (int i = 0; i <= H; i++)
    if (h[i].size() > 0)
      heights.push_back({i, h[i]});
  for (int i = 0; i < q; i++) {
    int sy, sx, ey, ex;
    cin>>sy>>sx>>ey>>ex;
    queries.push_back({(sy-1)*m+sx-1, (ey-1)*m+ex-1});
  }
  for (int i = 0; i < q; i++) {
    lo[i] = 0; 
    hi[i] = heights.size()-1;
  }
  while (1) {
    bool flag = false;
    vector<vector<int>> g(heights.size());
    for (int i = 0; i < q; i++)
      if (lo[i] < hi[i]) {
        flag = true;
        g[(lo[i]+hi[i])>>1].push_back(i);
      }
    if (!flag) break;
    for (int i = 0; i < n*m; i++) p[i] = i;
    for (int i = 0; i < heights.size(); i++) {
      auto [h, points] = heights[i];
      for (auto [yy, xx]: points) {
        for (int k = 0; k < 4; k++) {
          int ty = yy+dy[k];
          int tx = xx+dx[k];
          if (ty >= 0 && ty < n && tx >= 0 && tx < m && a[ty][tx] <= a[yy][xx])
            merge(yy*m+xx, ty*m+tx);
        }
      }
      for (auto idx : g[i]) {
        int u = find(queries[idx].fi);
        int v = find(queries[idx].se);
        int sy = queries[idx].fi/m, sx = queries[idx].fi%m;
        int ey = queries[idx].se/m, ex = queries[idx].se%m;
        if (u == v && h >= a[sy][sx] && h >= a[ey][ex]) hi[idx] = i;
        else lo[idx] = i+1;
      }
    }
  }
  for (int i = 0; i < q; i++) cout << heights[lo[i]].h << "\n";
}
