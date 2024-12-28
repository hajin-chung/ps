#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, t, s; cin>>n>>m>>t>>s;
  vector<pii> a(t);
  for (int i = 0; i < t; i++) {
    int x, y; cin>>x>>y;
    a[i] = {x+y, y-x};
  }
  int ans = 0;
  pii p;
  auto f = [&](int sx, int sy) {
    int cnt = 0;
    for (int k = 0; k < t; k++) 
      if (sx <= a[k].fi 
          && a[k].fi <= sx+s
          && sy <= a[k].se 
          && a[k].se <= sy+s)
        cnt++;
    return cnt;
  };
  for (int i = 1; i < t; i++) 
    for (int j = 0; j < i; j++) {
      int c1 = f(a[i].fi, a[j].se);
      int c2 = f(a[j].fi, a[i].se);
      if (c1 > ans) {
        ans = c1;
        p = {a[i].fi, a[j].se};
      }
      if (c2 > ans) {
        ans = c2;
        p = {a[j].fi, a[i].se};
      }
    }
  for (int i = 0; i < t; i++) {
    int c = f(a[i].fi, a[i].se);
    if (c > ans) {
      ans = c;
      p = a[i];
    }
  }
  int xx = p.fi, yy = p.se;
  yy = (xx+yy)/2;
  xx = xx-yy;
  yy += s/2;
  cout<<xx<<" "<<yy<<"\n";
  cout<<ans<<"\n";
}
