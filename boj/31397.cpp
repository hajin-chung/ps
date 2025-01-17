#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pll;
const ld EPS = 1e-6;
vector<pll> a;
vector<ld> d;
int n;

ld dist(pll a, pll b) {
  ld dx = a.fi - b.fi;
  ld dy = a.se - b.se;
  return sqrt(dx*dx+dy*dy);
}

ld area(pll a, pll b, pll c) {
  return abs(a.fi*b.se+b.fi*c.se+c.fi*a.se-a.se*b.fi-b.se*c.fi-c.se*a.fi)/2; }

ld area(vector<pll> &p) {
  ld ret = 0;
  for (int i = 1; i < p.size()-1; i++)
    ret += area(p[0], p[i], p[i+1]);
  return ret;
}

ld relerr(ld t, ld a) { return (t-a)/a; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout<<fixed<<setprecision(12);
  cin>>n; a.resize(n); d.resize(n, 0);
  for (int i = 0; i < n; i++) {
    cin>>a[i].fi>>a[i].se;
    if (i > 0) d[i] = d[i-1] + dist(a[i-1], a[i]);
  }
  ld c = 0;
  for (int i = 0; i < n; i++) c += dist(a[i], a[(i+1)%n]);
  ld l = 0, r = c/2, tarea = area(a);
  ld st, et, pa;
  int sidx, eidx;
  int trial = 3333;
  while (trial--) {
    ld offset = (l+r)/2;
    sidx = upper_bound(d.begin(), d.end(), offset)-d.begin();
    st = (offset-d[sidx-1])/dist(a[sidx%n], a[sidx-1]);
    pll s = {a[sidx-1].fi*(1-st)+a[sidx%n].fi*st, a[sidx-1].se*(1-st)+a[sidx%n].se*st};
    eidx = upper_bound(d.begin(), d.end(), offset+c/2)-d.begin();
    et = (offset+c/2-d[eidx-1])/dist(a[eidx%n], a[eidx-1]);
    pll e = {a[eidx-1].fi*(1-et)+a[eidx%n].fi*et, a[eidx-1].se*(1-et)+a[eidx%n].se*et};
    vector<pll> p;
    p.push_back(s); 
    for (int i = sidx; i < eidx; i++) p.push_back(a[i]);
    p.push_back(e);
    pa = area(p);
    if (pa < tarea/2) l = offset;
    else if(pa > tarea/2) r = offset;
  }
  if (fabs(pa * 2 - tarea) > 1e-6 && fabs(relerr(pa * 2, tarea)) > 1e-6) {
    cout << "NO\n";
    return 0;
  }
  cout<<"YES\n";
  cout<<sidx<<" "<<st<<"\n";
  cout<<eidx<<" "<<et<<"\n";
}
