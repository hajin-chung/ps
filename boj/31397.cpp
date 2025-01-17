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
    if(l>=d[i]&&l<d[i+1]) break; 
    i++; 
  }
  ld a = l-d[i], b = d[(i+1)%n]-l; 
  return {a/(a+b),i}; 
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
  ld st, et, pa;
  int si, ei;
  int trial = 10;
  while (trial--) {
    ld offset = (l+r)/2;
    auto [stt, sii] = getl(offset);
    si = sii, st = stt;
    auto [ett, sii] = getl(offset+c/2);
    ei = eii, et = ett;
    pll s = {a[si].fi*(1-st)+a[(si+1)%n].fi*st, a[si].se*(1-st)+a[(si+1)%n].se*st};
    pll e = {a[ei].fi*(1-et)+a[(ei+1)%n].fi*et, a[ei].se*(1-et)+a[(ei+1)%n].se*et};
    vector<pll> p;
    p.push_back(s); 
    for (int i = si+1; i <= ei; i++) p.push_back(a[i]);
    p.push_back(e);
    pa = area(p);
    cout<<pa<<" "<<tarea/2<<endl;
    if (pa < tarea/2) l = offset;
    else if(pa > tarea/2) r = offset;
  }
  cout<<"YES\n";
  cout<<si<<" "<<st<<"\n";
  cout<<ei<<" "<<et<<"\n";
}
