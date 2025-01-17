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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout<<fixed<<setprecision(10);
  cin>>n; a.resize(n); d.resize(n);
  for (int i = 0; i < n; i++) {
    cin>>a[i].fi>>a[i].se;
    if (i > 0) {
      d[i] = d[i-1] + dist(a[i-1], a[i]);
    }
  }
  ld c = 0;
  for (int i = 0; i < n; i++) c += dist(a[i], a[(i+1)%n]);
  ld l = 0, r = c/2, tarea = area(a);
  ld st, et, a1, a2;
  int sidx, eidx;
  int trial = 100;
  while (trial--) {
    ld offset = (l+r)/2;
    sidx = upper_bound(d.begin(), d.end(), offset)-d.begin();
    st = (offset-d[sidx-1])/dist(a[sidx], a[sidx-1]);
    pll s = {a[sidx-1].fi*(1-st)+a[sidx].fi*st, a[sidx-1].se*(1-st)+a[sidx].se*st};
    eidx = upper_bound(d.begin(), d.end(), offset+c/2)-d.begin();
    et = (offset+c/2-d[eidx-1])/dist(a[eidx%n], a[eidx-1]);
    pll e = {a[eidx-1].fi*(1-et)+a[eidx%n].fi*et, a[eidx-1].se*(1-et)+a[eidx%n].se*et};
    vector<pll> p1, p2;
    p1.push_back(s); 
    for (int i = sidx; i < eidx; i++) p1.push_back(a[i]);
    p1.push_back(e);
    p2.push_back(e); 
    for (int i = eidx; i < n; i++) p2.push_back(a[i]);
    for (int i = 0; i < sidx; i++) p2.push_back(a[i]);
    p2.push_back(s);
    /*cout<<"\n";*/
    /*cout<<offset<<" "<<offset+c/2<<" "<<c<<"\n";*/
    /*cout<<sidx<<" "<<eidx<<"\n";*/
    /*cout<<s.fi<<" "<<s.se<<" "<<e.fi<<" "<<e.se<<"\n";*/
    /*cout<<"p1\n";*/
    /*for (auto [x, y] : p1) cout<<x<<" "<<y<<"\n";*/
    /*cout<<"p2\n";*/
    /*for (auto [x, y] : p2) cout<<x<<" "<<y<<"\n";*/
    a1 = area(p1), a2 = area(p2);
    if (a1 < a2) l = offset;
    else if(a1 > a2) r = offset;
    if (abs(a1-a2)<EPS) break;
  }
  if (abs(a1-a2)>EPS || abs(a1*2-tarea)>EPS) cout<<"NO\n";
  else {
    cout<<"YES\n";
    cout<<sidx<<" "<<st<<"\n";
    cout<<eidx<<" "<<et<<"\n";
  }
}
