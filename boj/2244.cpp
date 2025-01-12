#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll dist(pll a, pll b) {
  ll dx = a.fi-b.fi;
  ll dy = a.se-b.se;
  return dx*dx+dy*dy;
}

int ccw(pll a, pll b, pll c) {
  int r = (b.fi-a.fi)*(c.se-a.se)-(c.fi-a.fi)*(b.se-a.se);
  return r < 0 ? -1 : r > 0;
}

vector<pll> get_hull(vector<pll> &a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int n = a.size();
  for (int i = 1; i < n; i++) if (a[i] < a[0]) swap(a[i], a[0]);
  sort(a.begin()+1, a.end(), [&](pll u, pll v) {
    int c = ccw(a[0], u, v);
    if (c == 0) return dist(a[0], u) < dist(a[0], v);
    return c > 0;
  });
  vector<pll> hull;
  for (int i = 0; i < n; i++) {
    while (hull.size() >= 2) {
      pll y = hull.back(); hull.pop_back();
      pll x = hull.back();
      if (ccw(x, y, a[i]) > 0) {
        hull.push_back(y);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  return hull;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<pll> a(n), b(m), pt;
  for (auto &[x, y] : a) cin>>x>>y;
  for (auto &[x, y] : b) cin>>x>>y;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      pt.push_back({a[i].fi+b[j].fi, a[i].se+b[j].se});
  auto hull = get_hull(pt);
  cout<<hull.size()<<"\n";
  for (auto [x, y] : hull)
    cout<<x<<" "<<y<<"\n";
}
