#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c) {
  int r = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return r >= 0 ? r == 0 ? 0 : 1 : -1;
}

int dist(pii a, pii b) {
  int dx = a.fi-b.fi, dy = a.se-b.se;
  return dx*dx+dy*dy;
}

bool intersect(pii s1, pii e1, pii s2, pii e2) {
  if (s1 > e1) swap(s1, e1);
  if (s2 > e2) swap(s2, e2);
  int c1 = ccw(s1, e1, s2)*ccw(s1, e1, e2);
  int c2 = ccw(s2, e2, s1)*ccw(s2, e2, e1);
  if (c1 == 0 && c2 == 0) return s2 <= e1 && s1 <= e2;
  return c1 <= 0 && c2 <= 0;
}

vector<pii> get_hull(vector<pii> &a) {
  int n = a.size();
  for (int i = 1; i < n; i++) if (a[0] > a[i]) swap(a[0], a[i]);
  sort(a.begin()+1, a.end(), [&](pii u, pii v) {
    int r = ccw(a[0], u, v);
    if (r == 0) return dist(a[0], u) < dist(a[0], v);
    return r > 0;
  });
  vector<pii> hull;
  hull.push_back(a[0]);
  hull.push_back(a[1]);
  for (int i = 2; i < n; i++) {
    while (!hull.empty()) {
      pii se = hull.back(); hull.pop_back();
      pii fi = hull.back();
      if (ccw(fi, se, a[i]) > 0) {
        hull.push_back(se);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  return hull;
}

bool inside(vector<pii> &hull, pii p) {
  int n = hull.size(), l = 1, r = n-1;
  if (ccw(hull[0], hull[1], p) < 0) return false;
  if (ccw(hull[0], hull[n-1], p) > 0) return false;
  while (l + 1 < r) {
    int m = (l+r)>>1;
    if (ccw(hull[0], hull[m], p) > 0) l = m;
    else r = m;
  }
  return ccw(hull[l], hull[r], p) >= 0;
}

bool solve() {
  int n, m; cin>>n>>m;
  vector<pii> a(n), b(m);
  for (auto &[x, y] : a) cin>>x>>y;
  for (auto &[x, y] : b) cin>>x>>y;
  if (n < m) swap(a, b);

  if (n == 1 && m == 1) return true;
  if (n == 2 && m == 1) {
    if (ccw(a[0], a[1], b[0]) != 0) return true;
    else {
      if (min(a[0], a[1]) < b[0] && b[0] < max(a[0], a[1])) return false;
      return true;
    }
  }
  if (n == 2 && m == 2) return !intersect(a[0], a[1], b[0], b[1]);
  vector<pii> ahull = get_hull(a); 
  vector<pii> bhull = get_hull(b); 
  int flag = false;
  for (auto p : bhull) flag |= inside(ahull, p);
  for (auto p : ahull) flag |= inside(bhull, p);
  return !flag;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) {
    if (solve()) cout<<"YES\n";
    else cout<<"NO\n";
  }
}
