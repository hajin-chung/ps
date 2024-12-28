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
    int yy = (sx+sy+s)/2;
    int xx = sx-yy+s/2;
    /*if (yy < 0 || yy > m || xx < 0 || xx > n) return 0;*/
    for (int k = 0; k < t; k++) 
      if (sx <= a[k].fi 
          && a[k].fi <= sx+s
          && sy <= a[k].se 
          && a[k].se <= sy+s)
        cnt++;
    return cnt;
  };
  for (int i = 0; i < t; i++) 
    for (int j = 0; j < t; j++) {
      int c = f(a[i].fi, a[j].se);
      if (c > ans) {
        ans = c;
        p = {a[i].fi+s/2, a[j].se+s/2};
      }
    }
  int xx = p.fi, yy = p.se;
  yy = (xx+yy)/2;
  xx = xx-yy;
  cout<<xx<<" "<<yy<<"\n";
  cout<<ans<<"\n";
}
