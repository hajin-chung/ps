#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c) {
  int v = (b.fi - a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  if (v > 0) return 1;
  else if (v < 0) return -1;
  return 0;
}

int dist(pii a, pii b) {
  int dy = a.se-b.se;
  int dx = a.fi-b.fi;
  return dy*dy+dx*dx;
}

// a > b
bool lt(pii a, pii b) {
  if (a.se == b.se) return a.fi < b.fi;
  return a.se > b.se;
}

void solve_line(vector<pii> &a) {
  pii s = a[0], e = a[0];
  for (auto p : a) {
    if (lt(p, s)) s = p;
    if (lt(e, p)) e = p;
  }
  cout<<2<<"\n";
  cout<<s.fi<<" "<<s.se<<"\n";
  cout<<e.fi<<" "<<e.se<<"\n";
}

void solve() {
  int n; cin>>n;
  vector<pii> a(n);
  for (auto &[x, y] : a) cin>>x>>y;
  for (int i = 1; i < n; i++) 
    if (!lt(a[0], a[i])) 
      swap(a[0], a[i]);
  sort(a.begin()+1, a.end(), [&](pii &u, pii &v) {
    int c = ccw(a[0], u, v);
    if (c == 0) return dist(a[0], u) < dist(a[0], v);
    return c < 0;
  });
  
  bool flag = true;
  for (int i = 2; i < n; i++)
    if (ccw(a[0], a[1], a[i]) != 0)
      flag = false; 
  if (flag) {
    solve_line(a); 
    return;
  }

  vector<pii> hull;
  hull.push_back(a[0]);
  hull.push_back(a[1]);
  for (int i = 2; i < n; i++) {
    while (hull.size()>=2) {
      pii se = hull.back(); hull.pop_back();
      pii fi = hull.back();
      if (ccw(fi, se, a[i]) < 0) {
        hull.push_back(se);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  cout<<hull.size()<<"\n";
  for (auto [x, y] : hull) cout << x << ' ' << y << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int p; cin>>p;
  while (p--) solve();
}
