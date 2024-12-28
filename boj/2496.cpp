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
  for (int i = 1; i < t; i++)
    for (int j = 0; j < i; j++) {
      int xx = min(a[i].fi, a[j].fi);
      int yy = min(a[i].se, a[j].se);
      int cnt = 0;
      for (int k = 0; k < n; k++) 
        if (xx <= a[k].fi 
            && a[k].fi <= xx+s
            && yy <= a[k].se 
            && a[k].se <= yy+s)
          cnt++;
      if (cnt > ans) {
        ans = cnt;
        p = {xx, yy};
      }
    }
  int xx = p.fi, yy = p.se;
  yy = (xx+yy)/2;
  xx = xx-yy;
  yy += s/2;
  cout<<xx<<" "<<yy<<"\n";
  cout<<ans<<"\n";
}
