#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

struct T { int x, y, h; };
const int INF = 1e9;

int get_cir(T a, T  b) {
  int xmn = min(a.x, b.x);
  int xmx = max(a.x, b.x);
  int ymn = min(a.y, b.y);
  int ymx = max(a.y, b.y); 
  return 2*(xmx-xmn)+2*(ymx-ymn);
}

bool inside(T a, T b, T c) {
  return min(a.x, b.x) <= c.x 
      && c.x <= max(a.x, b.x) 
      && min(a.y, b.y) <= c.y 
      && c.y <= max(a.y, b.y);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<T> a(n);
  for (auto &[x, y, h] : a) cin>>x>>y>>h;
  vector<bool> chk(n);
  int ans = INF;
  for (int xs = 0; xs < n; xs++) for (int xe = xs+1; xe < n; xe++) 
  for (int ys = 0; ys < n; ys++) for (int ye = ys+1; ye < n; ye++) {
      T s = {min(a[xs].x, a[xe].x), min(a[ys].y, a[ye].y), 0};
      T e = {max(a[xs].x, a[xe].x), max(a[ys].y, a[ye].y), 0};
      int cir = get_cir(s, e);
      int sum = 0, cut = 0;
      vector<int> v;
      for (auto t : a) {
        if (inside(s, e, t)) v.push_back(t.h);
        else { sum += t.h; cut++; }
      }
      sort(v.begin(), v.end());
      while (sum < cir && !v.empty()) {
        sum += v.back();
        cut++;
        v.pop_back();
      }
      if (sum >= cir && ans > cut) ans = cut;
    }
  if (ans == INF) cout<<n-1<<"\n";
  else cout<<ans<<"\n";
}
