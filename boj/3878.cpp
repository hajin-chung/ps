#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
pii pivot;

int ccw(pii a, pii b, pii c) {
  int v = (b.fi-a.fi)*(c.se-a.se) - (b.se-a.se)*(c.fi-a.fi);
  if (v == 0) return 0;
  else return v > 0 ? 1 : -1;
}

int dist(pii a, pii b) {
  int dx = a.fi - b.fi;
  int dy = a.se - b.se;
  return dx*dx+dy*dy; 
}

bool inside(vector<pii> hull, pii p) {
  int v = ccw(hull.back(), hull.front(), p);
  for (int i = 1; i < hull.size(); i++) 
    if (ccw(hull[i-1], hull[i], p) != v) 
      return false;
  return true;
}

bool cmp(pii a, pii b) {
  int v = ccw(pivot, a, b);
  if (v > 0) return true;
  else if (v < 0) return false;
  return dist(pivot, a) < dist(pivot, b);
}

vector<pii> make_hull(vector<pii> &a) {
  vector<pii> hull;
  sort(a.begin(), a.end());
  pivot = a[0];
  sort(a.begin(), a.end(), cmp);
  stack<pii> s;
  s.push(a[0]);
  s.push(a[1]);
  for (int i = 2; i < a.size(); i++) {
    while (s.size() >= 2) {
      pii se = s.top(); s.pop();
      pii fi = s.top();
      if (ccw(fi, se, a[i]) > 0) {
        s.push(se);
        break;
      }
    }
    s.push(a[i]);
  }
  while (!s.empty()) {
    hull.push_back(s.top());
    s.pop();
  }
  return hull;
}

bool line_point_chk(pii a1, pii a2, pii b) {
  int v = ccw(a1, a2, b);
  if (v != 0) return true;
  return b.fi < min(a1.fi, a2.fi) || b.fi > max(a1.fi, a2.fi);
}

bool line_line_chk(pii &a1, pii &a2, pii &b1, pii &b2) {
  int c1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
  int c2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
  if (c1 == 0 && c2 == 0) return b1 > a2 || a1 > b2;
  return c1 > 0 && c2 > 0;
}

bool hull_line_chk(vector<pii> &a, vector<pii> &l) {
  vector<pii> hull = make_hull(a);
  bool flag = line_line_chk(hull.back(), hull.front(), l[0], l[1]);
  for (int i = 1; i < a.size(); i++)
    flag &= line_line_chk(hull[i-1], hull[i], l[0], l[1]);
  return flag;
}

bool hull_hull_chk(vector<pii> &a, vector<pii> &b) {
  vector<pii> hull = make_hull(a);
  for (auto p : b) 
    if (inside(hull, p)) 
      return false;
  return true;
}

bool solve() {
  int n, m, x, y;
  vector<pii> a, b, hull;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    a.push_back({x, y});
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    b.push_back({x, y});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (n == 0 || m == 0) return true;
  if (n == 1 && m == 1) return true;
  if (n == 1 && m == 2) return line_point_chk(b[0], b[1], a[0]);
  if (n == 2 && m == 1) return line_point_chk(a[0], a[1], b[0]);
  if (n == 2 && m == 2) return line_line_chk(a[0], a[1], b[0], b[1]);
  if (n == 2 && m >= 3) return hull_line_chk(b, a) && hull_hull_chk(b, a);
  if (n >= 3 && m == 2) return hull_line_chk(a, b) && hull_hull_chk(a, b);
  if (n >= 3 && m >= 3) return hull_hull_chk(a, b) && hull_hull_chk(b, a);
  return false;
}

int main() {
  int T; 
  scanf("%d", &T);
  while (T--) printf("%s\n", solve() ? "YES" : "NO");
}
