#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll dist(pll a, pll b) {
  ll dx = a.fi-b.fi;
  ll dy = a.se-b.se;
  return dx*dx+dy*dy;
}

int ccw(pll a, pll b, pll c) {
  int r = (b.fi-a.fi)*(c.se-a.se)-(c.fi-a.fi)*(b.se-a.se);
  return r < 0 ? -1 : r > 0;
}

ld area(pll a, pll b, pll c) {
  ll p1 = a.fi*b.se+b.fi*c.se+c.fi*a.se;
  ll p2 = a.se*b.fi+b.se*c.fi+c.se*a.fi;
  return (ld)abs(p1-p2)/2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pll> a(n);
  for (auto &[x, y] : a) cin>>x>>y;
  for (int i = 1; i < n; i++) if (a[i]<a[0]) swap(a[0], a[i]);
  sort(a.begin()+1, a.end(), [&](pll &u, pll &v) {
    int c = ccw(a[0], u, v); 
    if (c == 0) return dist(a[0], u) < dist(a[0], v);
    return c == 1;
  });
  vector<pll> hull;
  hull.push_back(a[0]); 
  hull.push_back(a[1]);
  for (int i = 2; i < n; i++) {
    while (hull.size() >= 2) {
      pll se = hull.back(); hull.pop_back();
      pll fi = hull.back();
      if (ccw(fi, se, a[i]) > 0) {
        hull.push_back(se);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  n = hull.size();
  ld sum = 0;
  for (int i = 1; i < n-1; i++)
    sum += area(a[0], a[i], a[i+1]);
  cout<<(int)(sum/50.0f)<<"\n";
}
