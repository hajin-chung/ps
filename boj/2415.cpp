#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
struct T {
  ll l, x, y; 
  int i, j;
};
vector<T> v;
vector<pll> a;

ll dist(pll a, pll b) {
  ll dx = a.fi - b.fi;
  ll dy = a.se - b.se;
  return dx*dx+dy*dy;
}

ll sz(int p, int q) {
  vector<pll> sq;  
  ll w = dist(a[v[p].i], a[v[q].i]);
  ll h = dist(a[v[p].i], a[v[q].j]);
  return sqrt(w*h); 
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n; a.resize(n);
  for (auto &[x, y] : a) cin>>x>>y;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      v.push_back({dist(a[i], a[j]), a[i].fi+a[j].fi, a[i].se+a[j].se, i, j});
  sort(v.begin(), v.end(), [](T& a, T &b) {
    if (a.l == b.l) {
      if (a.x == b.x) return a.y < b.y;
      return a.x < b.x;
    }
    return a.l < b.l;
  });
  ll ans = 0;
  for (int i = 0, j; i < v.size(); ) {
    j = i+1;
    while (j < v.size() && v[i].l == v[j].l && v[i].x == v[j].x && v[i].y == v[j].y) {
      ans = max(ans, sz(i, j));
      j++;
    }
    i = j;
  }
  cout<<ans<<"\n";
}
