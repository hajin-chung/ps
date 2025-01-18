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

void intersect(set<pll> &arr, pll a, pll b, pll c, pll d) {
  double xi, yi;
  if(ccw(a,b,c)*ccw(a,b,d)<0 && ccw(c,d,a)*ccw(c,d,b)<0) {
    if(a.fi==b.fi) {
      xi=a.fi;
      yi=(d.se-c.se)/(d.fi-c.fi)*(xi-c.fi)+c.se;
      arr.insert({xi,yi});
    } else if(c.fi==d.fi) {
      xi=c.fi;
      yi=(b.se-a.se)/(b.fi-a.fi)*(xi-a.fi)+a.se;
      arr.insert({xi,yi});
    } else {
      double m1=(b.se-a.se)/(b.fi-a.fi);
      double m2=(d.se-c.se)/(d.fi-c.fi);
      xi=((m1*a.fi-a.se)-(m2*c.fi-c.se))/(m1-m2);
      yi=m1*xi-m1*a.fi+a.se;
      arr.insert({xi,yi});
    }
  }
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
    for (int j = 0; j < m; j++) 
      intersect(overlap, a[i], a[i+1], b[j], b[j+1]);
  vector<pll> c;
  for (auto p : overlap) c.push_back(p);
  int cn = c.size();
  if (cn <= 2) {
    cout<<"0.0\n";
    return 0;
  }
  for (int i = 1; i < cn; i++) if (c[0] > c[i]) swap(c[0], c[i]);
  sort(c.begin()+1, c.end(), [&](pll a, pll b) {
    int r = ccw(c[0], a, b);
    if (r == 0) return dist(c[0], a) < dist(c[0], b);
    return r > 0;
  });
  cout<<fixed<<setprecision(17)<<area(c)<<"\n";
}
