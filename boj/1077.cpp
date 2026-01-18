#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pll;

int ccw(pll a, pll b, pll c) {
  ld r = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return r < 0 ? -1 : r > 0;
}

ld dist(pll a, pll b) {
  ld dx = a.fi-b.fi;
  ld dy = a.se-b.se; 
  return (dx*dx+dy*dy);
}

bool inside(vector<pll> &a, pll p) {
  int n = a.size();
  for (int i = 0; i < n; i++)
    if (ccw(a[i], a[(i+1)%n], p) < 0)
      return false;
  return true;
}

void intersect(vector<pll> &arr, pll a, pll b, pll c, pll d) {
  ld xi, yi;
  if(ccw(a,b,c)*ccw(a,b,d)<0 && ccw(c,d,a)*ccw(c,d,b)<0) {
    if(a.fi==b.fi) {
      xi=a.fi;
      yi=(d.se-c.se)/(d.fi-c.fi)*(xi-c.fi)+c.se;
      arr.push_back({xi,yi});
    } else if(c.fi==d.fi) {
      xi=c.fi;
      yi=(b.se-a.se)/(b.fi-a.fi)*(xi-a.fi)+a.se;
      arr.push_back({xi,yi});
    } else {
      ld m1=(b.se-a.se)/(b.fi-a.fi);
      ld m2=(d.se-c.se)/(d.fi-c.fi);
      xi=((m1*a.fi-a.se)-(m2*c.fi-c.se))/(m1-m2);
      yi=m1*xi-m1*a.fi+a.se;
      arr.push_back({xi,yi});
    }
  }
}

ld area(vector<pll> &a) {
  ld ret = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) 
    ret += a[i].fi*a[(i+1)%n].se-a[i].se*a[(i+1)%n].fi;
  return abs(ret)/2;
}

vector<pll> get_hull(vector<pll> &a) {
  int n = a.size();
  for (int i = 1; i < n; i++) if (a[i] < a[0]) swap(a[i], a[0]);
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
      auto se = hull.back(); hull.pop_back();
      auto fi = hull.back();
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
  int n, m; cin>>n>>m;
  vector<pll> ta(n), tb(m); 
  for (auto &[x, y] : ta) cin>>x>>y;
  for (auto &[x, y] : tb) cin>>x>>y;
  auto a = get_hull(ta);
  auto b = get_hull(tb);
  vector<pll> c;
  for (auto p : a) if (inside(b, p)) c.push_back(p);
  for (auto p : b) if (inside(a, p)) c.push_back(p);
  int an = a.size(), bn = b.size();
  a.push_back(a[0]); b.push_back(b[0]);
  for (int i = 0; i < an; i++)
    for (int j = 0; j < bn; j++) 
      intersect(c, a[i], a[i+1], b[j], b[j+1]);
  int cn = c.size();
  if (cn <= 2) {
    cout<<"0.0\n";
    return 0;
  }
  auto cc = get_hull(c);
  cout<<fixed<<setprecision(17)<<area(cc)<<"\n";
}
