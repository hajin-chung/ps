#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
  ll r = (b.fi-a.fi)*(c.se-a.se)-(c.fi-a.fi)*(b.se-a.se);
  return r < 0 ? -1 : r > 0;
}

ld dist(pll a, pll b) {
  ld dx = (ld)b.fi-a.fi;
  ld dy = (ld)b.se-a.se;
  return sqrt(dx*dx+dy*dy);
}

ld area(pll a, pll b, pll c) {
  ld ret = (ld)abs((a.fi*b.se+b.fi*c.se+c.fi*a.se)-(a.se*b.fi+b.se*c.fi+c.se*a.fi))/2.0;
  return ret;
}

vector<pll> get_hull(vector<pll> &a) {
  int n = a.size();
  for (int i = 1; i < n; i++) if (a[0] < a[i]) swap(a[0], a[i]);
  sort(a.begin()+1, a.end(), [&](pll u, pll v) {
    int r = ccw(a[0], u, v);
    if (r == 0) return dist(a[0], u) < dist(a[0], v);
    return r > 0;
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
  return hull;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r; cin>>n>>r;
  vector<pll> a(n);
  for (auto &[x, y] : a) cin>>x>>y;
  auto hull = get_hull(a);
  n = hull.size();
  ld ans = 1e20;
  int v = 1;
  for (int u = 0; u < n; u++) {
    while (ccw(
      {0, 0}, 
      {hull[(u+1)%n].fi-hull[u].fi, hull[(u+1)%n].se-hull[u].se}, 
      {hull[(v+1)%n].fi-hull[v].fi, hull[(v+1)%n].se-hull[v].se}) > 0
    ) v = (v+1)%n;
    ans = min(ans, area(hull[u], hull[(u+1)%n], hull[v])/dist(hull[u], hull[(u+1)%n])*2.0);
  }
  cout<<fixed<<setprecision(20)<<ans<<"\n";
}
