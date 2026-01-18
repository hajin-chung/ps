#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 2000000000
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int ccw(pll a, pll b, pll c) {
  ll r = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return r >= 0 ? r == 0 ? 0 : 1 : -1;
}

struct Polygon {
  int n;
  ll xmn = INF, xmx = -INF;
  vector<pll> b, t;
  Polygon(vector<pll> o) {
    n = o.size();
    int p, mn = 0;
    for (int i = 1; i < n; i++) {
      if (o[mn] > o[i]) 
        mn = i;
      xmn = min(xmn, o[i].fi);
      xmx = max(xmx, o[i].fi);
    }
    b.push_back(o[mn]);
    for (int ti = mn; ti < n+mn; ti++) {
      ll i = ti%n;
      if (o[(i-1+n)%n].fi < o[i].fi) b.push_back(o[i]);
      if (o[i].fi > o[(i+1)%n].fi) {
        p = i;
        t.push_back(o[i]);
      }
    }
    t.push_back(o[(p+1)%n]);
    reverse(t.begin(), t.end());
  }
  // 1 : up, -1 : down
  int find(vector<pll> &v, pll p) {
    int l = 0, r = v.size()-1;
    while (l < r) {
      ll m = (l+r)>>1;
      if (p.fi < v[m].fi) r = m;
      else l = m+1;
    }
    int ret = ccw(v[l-1], v[l], p);
    return ret;
  }
  bool chk(pll p) {
    if (p.fi < xmn || p.fi > xmx) return false;
    int br = find(b, p); 
    int tr = find(t, p); 
    return br*tr == -1;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k; cin>>n>>m>>k;
  vector<pll> a(n), b(m), s(k);
  for (auto &[x, y] : a) cin>>x>>y;
  for (auto &[x, y] : b) cin>>x>>y;
  for (auto &[x, y] : s) cin>>x>>y;
  Polygon A(a);
  Polygon B(b);
  int ans = 0;
  for (auto p : s)
    if (!A.chk(p) || B.chk(p))
      ans++;
  if (ans == 0) cout<<"YES\n";
  else cout<<ans<<"\n";
}
