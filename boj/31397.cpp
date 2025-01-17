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

ld area(vector<pll> &p) {
  ld ret = 0;
  int n = p.size();
  for (int i = 0; i < p.size(); i++)
    ret += p[i].fi*p[(i+1)%n].se-p[i].se*p[(i+1)%n].fi;
  return abs(ret);
}
pair<ld,int> getl(ld l){
  int i=0;
  while(1){
    if(d[i] <= l && l < d[i+1]) break; 
    i++; 
  }
  ld a = l-d[i], b = d[i+1]-l; 
  return {a/(a+b),i}; 
}

ld st, et; int si, ei;
ld f(ld m) {
  auto [stt, sii] = getl(m);
  si = sii, st = stt;
  auto [ett, eii] = getl(m+d[n]/2);
  ei = eii, et = ett;
  pll s = {a[si].fi*(1-st)+a[(si+1)%n].fi*st, a[si].se*(1-st)+a[(si+1)%n].se*st};
  pll e = {a[ei].fi*(1-et)+a[(ei+1)%n].fi*et, a[ei].se*(1-et)+a[(ei+1)%n].se*et};
  vector<pll> p;
  p.push_back(s); 
  for (int i = si+1; i <= ei; i++) p.push_back(a[i]);
  p.push_back(e);
  return area(p);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout<<fixed<<setprecision(12);
  cin>>n; a.resize(n); d.resize(n+1, 0);
  for (int i = 0; i < n; i++) {
    cin>>a[i].fi>>a[i].se;
    if (i > 0) d[i] = d[i-1] + dist(a[i-1], a[i]);
  }
  d[n] = d[n-1] + dist(a[n-1], a[0]);
  ld c = 0;
  for (int i = 0; i < n; i++) c += dist(a[i], a[(i+1)%n]);
  ld l = 0, r = c/2, tarea = area(a);
  bool flag = true;
  if (f(l) > tarea/2) flag = false;
  int trial = 450;
  while (trial--) {
    ld m = (l+r)/2;
    ld pa = f(m);
    if (pa > tarea/2) {
      if (flag) r = m;
      else l = m;
    } else {
      if (flag) l = m;
      else r = m;
    }
  }
  cout<<"YES\n";
  cout<<si+1<<" "<<st<<"\n";
  cout<<ei+1<<" "<<et<<"\n";
}
