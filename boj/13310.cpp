#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppp;

vector<pll> positions(vector<ppp> &a, int t) {
  vector<pll> at(a.size());
  for (int i = 0; i < a.size(); i++) {
    at[i] = {
      a[i].fi.fi + a[i].se.fi * t,
      a[i].fi.se + a[i].se.se * t
    };
  }
  return at;
}

int ccw(pll a, pll b, pll c) {
  ll res = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return res == 0 ? 0 : res > 0 ? 1 : -1;
}

ll dist(pll a, pll b) {
  ll dx = a.fi - b.fi;
  ll dy = a.se - b.se; 
  return dx*dx+dy*dy;
}

pll sub(pll a, pll b) { return {a.fi-b.fi, a.se-b.se}; }

ll farthest(vector<ppp> &o, int t) {
  auto a = positions(o, t);
  int n = a.size();
  for (int i = 1; i < n; i++) if (a[i] > a[0]) swap(a[i], a[0]);
  sort(a.begin()+1, a.end(), [&](pll u, pll v) {
    int res = ccw(a[0], u, v);
    if (res == 0) return dist(a[0], u) < dist(a[0], v);
    return res > 0;
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
  ll ret = 0;
  n = hull.size();
  for (int u = 0, v = 1; u < n; u++) {
    while (ccw(
      {0, 0}, 
      sub(hull[(u+1)%n], hull[u]), 
      sub(hull[(v+1)%n], hull[v])) > 0) {
      v = (v+1)%n;
    }
    ret = max(ret, dist(hull[u], hull[v]));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t; cin>>n>>t;
  vector<ppp> a(n);
  for (auto &[p, v] : a) {
    auto &[x, y] = p;
    auto &[vx, vy] = v;
    cin>>x>>y>>vx>>vy;
  }
  int s = 0, e = t; 
  while (e - s >= 3) {
    int l = s+(e-s)/3, r = e-(e-s)/3; 
    ll ld = farthest(a, l);
    ll rd = farthest(a, r);
    /*cout<<s<<" "<<e<<"\n"<<l<<" "<<ld<<" "<<r<<" "<<rd<<"\n";*/
    if (rd < ld) s = l;
    else e = r;
  }
  int ans;
  ll mn = LLONG_MAX;
  for (int t = s; t <= e; t++) {
    ll d = farthest(a, t);
    if (d < mn) {
      ans = t;
      mn = d;
    }
  }
  cout<<ans<<"\n"<<mn<<"\n";
}
