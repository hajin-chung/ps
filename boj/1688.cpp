#include <bits/stdc++.h>
#define INF 2000000000
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
  ll res = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return res == 0 ? 0 : res > 0 ? 1 : -1;
}

ll dist(pll a, pll b) {
  ll dy = a.se-b.se;
  ll dx = a.fi-b.fi;
  return dy*dy+dx*dx;
}

vector<pll> get_hull(vector<pll> &a) {
  int n = a.size();
  for (int i = 1; i < n; i++) 
    if (a[0].se > a[i].se || (a[0].se == a[i].se && a[0].fi > a[i].fi)) 
      swap(a[0], a[i]);
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
  return hull;
}

bool line_intersect(pll s1, pll e1, pll s2, pll e2) {
  return ccw(s1, e1, s2)*ccw(s1, e1, e2) < 0 && ccw(s2, e2, s1)*ccw(s2, e2, e1) < 0;
}

bool hull_contains(vector<pll> &hull, pll p) {
  int cnt = 0, n = hull.size();
  for (int i = 0; i < n; i++)
    if (line_intersect(p, {INF,p.se+1}, hull[i], hull[(i+1)%n]))
      cnt++;
  return cnt%2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pll> a(n), s(3);
  for (auto &[x, y] : a) cin>>x>>y;
  for (auto &[x, y] : s) cin>>x>>y;
  vector<pll> hull = get_hull(a);
  for (auto p : s) cout<<hull_contains(hull, p)<<"\n";
}
