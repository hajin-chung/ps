#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;
pii pivot;

int ccw(pii a, pii b, pii c) {
  ll v = (b.fi-a.fi)*(c.se-a.se) - (b.se-a.se)*(c.fi-a.fi);
  if (v == 0) return 0;
  else return v > 0 ? 1 : -1;
}

ll dist(pii a, pii b) {
  ll dx = a.fi - b.fi;
  ll dy = a.se - b.se;
  return dx*dx+dy*dy; 
}

bool cmp(pii a, pii b) {
  int v = ccw(pivot, a, b);
  if (v > 0) return true;
  else if (v < 0) return false;
  return dist(pivot, a) < dist(pivot, b);
}

bool inside(vector<pii> &hull, pii p) {
  int n = hull.size();
  for (int i = 0; i < n; i++) 
    if (ccw(hull[i], hull[(i+1)%n], p) <= 0) 
      return true;
  return false;
}

vector<pii> make_hull(vector<pii> &a) {
  vector<pii> hull;
  sort(a.begin(), a.end());
  pivot = a[0];
  sort(a.begin(), a.end(), cmp);
  vector<pii> s;
  s.push_back(a[0]);
  if (a.size() == 1) {
    s.push_back(a[0]);
    return s;
  }
  s.push_back(a[1]);
  for (int i = 2; i < a.size(); i++) {
    while (s.size() >= 2) {
      pii se = s.back(); s.pop_back();
      pii fi = s.back();
      if (ccw(fi, se, a[i]) > 0) {
        s.push_back(se);
        break;
      }
    }
    s.push_back(a[i]);
  }
  return s;
}

bool intersect(pii &a1, pii &a2, pii &b1, pii &b2) {
  int c1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
  int c2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
  if (c1 == 0 && c2 == 0) return b1 <= a2 && a1 <= b2;
  return c1 <= 0 && c2 <= 0;
}

/*bool line_point_chk(pii a1, pii a2, pii b) {*/
/*  int v = ccw(a1, a2, b);*/
/*  if (v != 0) return true;*/
/*  return b.fi < min(a1.fi, a2.fi) || b.fi > max(a1.fi, a2.fi);*/
/*}*/

/*bool hull_line_chk(vector<pii> &a, vector<pii> &l) {*/
/*  vector<pii> hull = make_hull(a);*/
/*  bool flag = line_line_chk(hull.back(), hull.front(), l[0], l[1]);*/
/*  for (int i = 1; i < hull.size(); i++)*/
/*    flag &= line_line_chk(hull[i-1], hull[i], l[0], l[1]);*/
/*  return flag;*/
/*}*/

/*bool hull_hull_chk(vector<pii> &a, vector<pii> &b) {*/
/*  vector<pii> hull = make_hull(a);*/
/*  for (auto p : b) */
/*    if (inside(hull, p)) */
/*      return false;*/
/*  return true;*/
/*}*/

bool solve() {
  int n, m;
  ll x, y;
  vector<pii> a, b, hull;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &x, &y);
    a.push_back({x, y});
  }
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld", &x, &y);
    b.push_back({x, y});
  }
  if (n == 1 && m == 1) return true;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<pii> ca = make_hull(a);
  vector<pii> cb = make_hull(b);
  int can = ca.size(), cbn = cb.size();

  for (int i = 0; i < ca.size(); i++) 
    for (int j = 0; j < cb.size(); j++) 
      if (intersect(ca[i], ca[(i+1)%can], cb[j], cb[(j+1)%cbn]))
        return false;

  for (auto p : a)
    if (inside(cb, p)) 
      return false;
  for (auto p : b)
    if (inside(ca, p)) 
      return false;

  /*if (n == 0 || m == 0) return true;*/
  /*if (n == 1 && m == 1) return true;*/
  /*if (n == 1 && m == 2) return line_point_chk(b[0], b[1], a[0]);*/
  /*if (n == 1 && m >= 3) return hull_hull_chk(b, a);*/
  /*if (n == 2 && m == 1) return line_point_chk(a[0], a[1], b[0]);*/
  /*if (n == 2 && m == 2) return line_line_chk(a[0], a[1], b[0], b[1]);*/
  /*if (n == 2 && m >= 3) return hull_line_chk(b, a) && hull_hull_chk(b, a);*/
  /*if (n >= 3 && m == 1) return hull_hull_chk(a, b);*/
  /*if (n >= 3 && m == 2) return hull_line_chk(a, b) && hull_hull_chk(a, b);*/
  /*if (n >= 3 && m >= 3) return hull_hull_chk(a, b) && hull_hull_chk(b, a);*/
  return true;
}

int main() {
  int T; 
  scanf("%d", &T);
  while (T--) printf("%s\n", solve() ? "YES" : "NO");
}
