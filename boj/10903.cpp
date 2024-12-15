#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
  ll res = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  if (res > 0) return 1;
  else if (res == 0) return 0;
  return -1;
}

ll dist(pll a, pll b) {
  ll dy = a.se-b.se;
  ll dx = a.fi-b.fi;
  return dy*dy+dx*dx;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r; cin>>n>>r;
  vector<pll> a(n);
  for (auto &[x, y] : a) cin>>x>>y;
  for (int i = 1; i < n; i++) if (a[i] < a[0]) swap(a[i], a[0]);
  sort(a.begin()+1,a.end(), [&](pll u, pll v) {
    int c = ccw(a[0], u, v);
    if (c == 0) return dist(a[0], u) < dist(a[0], v);
    return c > 0;
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
  double ans = 0;
  for (int i = 0; i < n; i++)
    ans += sqrt((double)dist(a[i], a[(i+1)%n]));
  ans += 2*r*M_PI;
  cout<<fixed<<setprecision(12)<<ans<<"\n";
}
