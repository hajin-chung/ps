#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

pll sub(pll a, pll b) {
  return {a.fi-b.fi, a.se-b.se};
}

int ccw(pll a, pll b, pll c) {
  ll res = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return res == 0 ? 0 : res > 0 ? 1 : -1;
}

ll dist(pll a, pll b) {
  ll dy = a.se-b.se;
  ll dx = a.fi-b.fi;
  return dy*dy+dx*dx;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pll> a(n);
  for (auto &[x, y] : a) cin>>x>>y;
  for (int i = 1; i < n; i++) if (a[0] > a[i]) swap(a[0], a[i]);
  sort(a.begin()+1, a.end(), [&](pll u, pll v) {
    int c = ccw(a[0], u, v);
    if (c == 0) return dist(a[0], u) < dist(a[0], v);
    return c > 0;
  });
  vector<pll> hull;
  hull.push_back(a[0]);
  hull.push_back(a[1]);
  for (int i = 2; i < n; i++) {
    while (hull.size() >= 2) {
      pll se = hull.back(); hull.pop_back();
      pll fi = hull.back();
      if (ccw(fi, se, a[i]) > 0) {
        hull.push_back(se);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  n = hull.size();
  ll ans = 0;
  for (int u = 0, v = 1; u < n && v < n; u++) {
    while (ccw(
      {0, 0}, 
      sub(hull[(u+1)%n], hull[u]), 
      sub(hull[(v+1)%n], hull[v])) > 0) {
      v++;
    }
    if (v >= n) break;
    ans = max(ans, dist(hull[u], hull[v]));
  }
  cout<<ans<<"\n";
}
