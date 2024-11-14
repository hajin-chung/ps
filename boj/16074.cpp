#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define N 500
#define Q 100000
#define H 1000000
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;
struct Query { pii s, e; };
struct Height {
  ll h;
  vector<pii> polls;
};
ll n, m, q, a[N][N], lo[Q], hi[Q], p[N*N];
bool chk[N][N];
vector<pii> h[H+1];
vector<Height> heights;
vector<Query> queries;
ll dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

ll find(ll u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}
ll find(pii pp) { return find(pp.fi*m+pp.se); }

void merge(ll u, ll v) {
  u = find(u); v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}
void merge(pii u, pii v) { merge(u.fi*m+u.se, v.fi*m+v.se); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>q;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < m; j++) {
      cin>>a[i][j];
      h[a[i][j]].push_back({i, j});
    }
  for (ll i = 1; i <= H; i++)
    if (h[i].size() > 0)
      heights.push_back({i, h[i]});
  for (ll i = 0; i < q; i++) {
    ll sy, sx, ey, ex;
    cin>>sy>>sx>>ey>>ex;
    queries.push_back({{sy-1, sx-1}, {ey-1, ex-1}});
  }
  for (ll i = 0; i < q; i++) {
    lo[i] = 0; 
    hi[i] = heights.size()-1;
  }
  while (1) {
    bool flag = false;
    vector<vector<ll>> g;
    g.resize(heights.size());
    for (ll i = 0; i < q; i++)
      if (lo[i] < hi[i]) {
        flag = true;
        g[(lo[i]+hi[i])>>1].push_back(i);
      }
    if (!flag) break;
    for (ll i = 0; i < n*m; i++) p[i] = i;
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < m; j++)
        chk[i][j] = false;
    for (ll i = 0; i < heights.size(); i++) {
      auto [h, polls] = heights[i];
      for (auto [yy, xx]: polls) {
        chk[yy][xx] = true;
        for (ll k = 0; k < 4; k++) {
          ll ty = yy+dy[k];
          ll tx = xx+dx[k];
          if (ty >= 0 && ty < n && tx >= 0 && tx < m && chk[ty][tx])
            merge({yy, xx}, {ty, tx});
        }
      }
      for (auto idx : g[i]) {
        ll u = find(queries[idx].s);
        ll v = find(queries[idx].e);
        if (u == v) hi[idx] = i;
        else lo[idx] = i+1;
      }
    }
  }
  for (ll i = 0; i < q; i++) cout << heights[lo[i]].h << "\n";
}
