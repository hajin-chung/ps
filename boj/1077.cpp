#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pll;
set<pll> overlap;

int ccw(pll a, pll b, pll c) {
  int r = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return r < 0 ? -1 : r > 0;
}

bool inside(vector<pll> &a, pll p) {
  int n = a.size(), l = 1, r = n-1;
  if (ccw(a[0], a[1], p) < 0) return false;
  if (ccw(a[0], a[n-1], p) > 0) return false;
  while (l + 1 < r) {
    int m = (l+r)>>1;
    if (ccw(a[0], a[m], p) > 0) l = m;
    else r = m;
  }
  return ccw(a[l], a[r], p) >= 0;
}

pair<bool, pll> intersect(pll a, pll b, pll c, pll d) {
  bool intersect = false;
  long long ccw1 = ccw(a, b, c);
  long long ccw2 = ccw(a, b, d);
  long long ccw3 = ccw(c, d, a);
  long long ccw4 = ccw(c, d, b);
  long long ccwA = ccw1 * ccw2;
  long long ccwB = ccw3 * ccw4;
  if (ccwA <= 0 && ccwB <= 0) {
    if (ccwA == 0 && ccwB == 0) {
      if (a > b) swap(a, b);
      if (c > d) swap(c, d);
      intersect = a <= d && c <= b;
    } else intersect = true;
  }
  if (!intersect) return {false, {0, 0}};
  ld x1 = a.fi, y1 = a.se;
  ld x2 = b.fi, y2 = b.se;
  ld x3 = c.fi, y3 = c.se;
  ld x4 = d.fi, y4 = d.se;
  double x = (x1 * y2 - y1 * x2) * (x3 - x4)  - (x1 - x2) * (x3 * y4 - y3 * x4);
  x /= (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  double y = (x1 * y2 - y1 * x2) * (y3 - y4)  - (y1 - y2) * (x3 * y4 - y3 * x4);
  y /= (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  return {true, {x, y}};
}

ld area(vector<pll> &a) {
  ld ret = 0;
  int n = a.size();
  a.push_back(a[0]);
  for (int i = 0; i < n; i++) ret += a[i].fi*a[i+1].se-a[i].se*a[i+1].fi;
  a.pop_back();
  return abs(ret)/2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<pll> a(n), b(m); 
  for (auto &[x, y] : a) cin>>x>>y;
  for (auto &[x, y] : b) cin>>x>>y;
  for (auto p : a) if (inside(b, p)) overlap.insert(p);
  for (auto p : b) if (inside(a, p)) overlap.insert(p);
  a.push_back(a[0]); b.push_back(b[0]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      auto [ok, p] = intersect(a[i], a[i+1], b[j], b[j+1]);
      if (ok) overlap.insert(p);
    }
  vector<pll> c;
  for (auto p : overlap) c.push_back(p);
  int cn = c.size();
  for (int i = 1; i < cn; i++) if (c[0] > c[i]) swap(c[0], c[i]);
  sort(c.begin()+1, c.end(), [&](pll a, pll b) {
    return ccw(c[0], a, b) == 1;
  });
  cout<<fixed<<setprecision(17)<<area(c)<<"\n";
}
