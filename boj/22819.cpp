#include <bits/stdc++.h>
#define PI M_PI
using namespace std;

typedef long double ld;
struct C { ld x, y, r; };

ld dist(C &a, C &b) {
  ld dx = a.x-b.x;
  ld dy = a.y-b.y;
  return sqrt(dx*dx+dy*dy);
}

ld atan(C &a, C &b) {
  ld dx = b.x-a.x, dy = b.y-a.y;
  if (dy == 0) return dx > 0 ? 0 : PI;
  if (dx == 0) return dy > 0 ? PI/2 : 3*PI/2;
  ld ret = atan(dy/dx);
  if (dx < 0 && dy > 0) ret += PI;
  if (dx < 0 && dy < 0) ret += PI;
  return ret;
}

ld ang(C &a, C &b) {
  ld ret = asin((a.r-b.r)/dist(a, b)) + atan(a, b);
  if (ret < 0) ret += 2*PI;
  if (ret >= 2*PI) ret -= 2*PI;
  return ret;
}

bool solve() {
  int n; cin>>n;
  if (n == 0) return false;
  vector<C> t(n), a;
  for (auto &[x, y, r] : t) cin>>x>>y>>r;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < n; j++)
      if (i != j && dist(t[i], t[j])+t[i].r <= t[j].r)
        flag = true;
    if (!flag) a.push_back(t[i]);
  }
  n = a.size();
  for (int i = 1; i < n; i++) {
    if (a[0].y-a[0].r == a[i].y-a[i].r && a[0].x > a[i].x)
      swap(a[0], a[i]);
    if (a[0].y-a[0].r > a[i].y-a[i].r)
      swap(a[0], a[i]);
  }
  if (n == 1) {
    cout<<2*PI*a[0].r<<"\n";
    return true;
  }
  vector<int> hull;
  hull.push_back(0);
  ld lang = -1.0;
  while (1) {
    ld mn = 3*PI; int v, u = hull.back();
    for (int i = 0; i < n; i++) {
      if (u == i) continue;
      ld uvang = ang(a[u], a[i]);
      if (uvang >= lang && uvang < mn) {
        v = i; mn = uvang;
      }
    }
    if (v == 0) break;
    hull.push_back(v);
    lang = mn;
  }
  ld ans = 0; n = hull.size();
  for (int i = 1; i < n; i++) {
    ld d = dist(a[hull[i]], a[hull[(i+1)%n]]);
    ld dr = a[hull[i]].r-a[hull[(i+1)%n]].r;
    ans += sqrt(d*d-dr*dr);
    ld theta = ang(a[hull[i]], a[hull[(i+1)%n]]) - ang(a[hull[i-1]], a[hull[i]]);
    ans += theta * a[hull[i]].r;
  }
  ld d = dist(a[hull[0]], a[hull[1]]);
  ld dr = a[hull[0]].r-a[hull[1]].r;
  ans += sqrt(d*d-dr*dr);
  ld theta = ang(a[hull[n-1]], a[hull[0]])-ang(a[hull[0]], a[hull[1]]);
  ans += a[hull[0]].r*(2*PI-theta);
  cout<<ans<<"\n";
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout<<fixed<<setprecision(10);
  while (solve()) {}
}
