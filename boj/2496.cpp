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
    int x = (sx-sy)/2, y = (sx+sy)/2 + s/2;
    if (x < 0 || x > n || y < 0 || y > m) return;
    for (int k = 0; k < t; k++) 
      if (sx <= a[k].fi 
          && a[k].fi <= sx+s
          && sy <= a[k].se 
          && a[k].se <= sy+s)
        cnt++;
    if (ans < cnt) {
      ans = cnt; 
      p = {x, y};
    }
  };
  for (int i = 0; i < t; i++) 
    for (int j = 0; j < t; j++) {
      int x = a[i].fi, y = a[j].se;
      if ((x+y)%2) f(x+1, y), f(x-1, y), f(x, y+1), f(x, y-1);
      else f(x, y);
      f(x+y-s/2, y-x-s/2);
    }
  cout<<p.fi<<" "<<p.se<<"\n";
  cout<<ans<<"\n";
}
