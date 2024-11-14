#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define N 500
#define Q 100000
#define H 1000000
using namespace std;

typedef pair<int, int> pii;
struct Query { pii s, e; };
struct Height {
  int h;
  vector<pii> points;
};
int n, m, q, a[N][N], lo[Q], hi[Q];
pii p[N][N];
bool chk[N][N];
vector<pii> h[H+1];
vector<Height> heights;
vector<Query> queries;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

pii find(pii u) { 
  if (p[u.fi][u.se] == u) return u;
  return p[u.fi][u.se] = find(p[u.fi][u.se]);
}

void merge(pii u, pii v) {
  u = find(u); v = find(v);
  if (u < v) p[v.fi][v.se] = u;
  else p[u.fi][u.se] = v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin>>a[i][j];
      h[a[i][j]].push_back({i, j});
    }
  for (int i = 1; i <= H; i++)
    if (h[i].size() > 0)
      heights.push_back({i, h[i]});
  for (int i = 0; i < q; i++) {
    int sy, sx, ey, ex;
    cin>>sy>>sx>>ey>>ex;
    queries.push_back({{sy-1, sx-1}, {ey-1, ex-1}});
  }
  for (int i = 0; i < q; i++) {
    lo[i] = 0; 
    hi[i] = heights.size()-1;
  }
  while (1) {
    bool flag = false;
    vector<vector<int>> g;
    g.resize(heights.size());
    for (int i = 0; i < q; i++)
      if (lo[i] < hi[i]) {
        flag = true;
        g[(lo[i]+hi[i])>>1].push_back(i);
      }
    if (!flag) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        chk[i][j] = false;
        p[i][j] = {i, j};
      }
    for (int i = 0; i < heights.size(); i++) {
      auto [h, points] = heights[i];
      for (auto [yy, xx]: points) {
        chk[yy][xx] = true;
        for (int k = 0; k < 4; k++) {
          int ty = yy+dy[k];
          int tx = xx+dx[k];
          if (ty >= 0 && ty < n && tx >= 0 && tx < m && chk[ty][tx])
            merge({yy, xx}, {ty, tx});
        }
      }
      for (auto idx : g[i]) {
        pii u = find(queries[idx].s);
        pii v = find(queries[idx].e);
        if (u == v) hi[idx] = i;
        else lo[idx] = i+1;
      }
    }
  }
  for (int i = 0; i < q; i++) cout << heights[lo[i]].h << "\n";
}
