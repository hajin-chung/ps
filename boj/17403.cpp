#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
struct P {
  int x, y, idx;
  bool operator<(P &rhs) {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
};

ll dist(P a, P b) {
  ll dx = a.x-b.x;
  ll dy = a.y-b.y;
  return dx*dx+dy*dy;
}

int ccw(P a, P b, P c) {
  int r = (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
  return r < 0 ? -1 : r > 0;
}

vector<P> get_hull(vector<P> &a) {
  int n = a.size();
  vector<P> hull;
  hull.push_back(a[0]); 
  hull.push_back(a[1]);
  for (int i = 2; i < n; i++) {
    while (hull.size() >= 2) {
      P y = hull.back(); hull.pop_back();
      P x = hull.back();
      if (ccw(x, y, a[i]) > 0) {
        hull.push_back(y);
        break;
      }
    }
    hull.push_back(a[i]);
  }
  return hull;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<P> a(n), aa(n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin>>x>>y;
    a[i] = {x, y, i};
  }
  aa = a;
  int cnt = 0;
  while (a.size() >= 3) {
    cnt++;
    n = a.size();
    for (int i = 1; i < n; i++) if (a[i]<a[0]) swap(a[0], a[i]);
    sort(a.begin()+1, a.end(), [&](P &u, P &v) {
      int c = ccw(a[0], u, v); 
      if (c == 0) return dist(a[0], u) < dist(a[0], v);
      return c == 1;
    });
    auto hull = get_hull(a);
    if (hull.size() == 2) break;
    for (auto [x, y, idx] : hull) ans[idx] = cnt;
    a.clear();
    for (int i = 0; i < aa.size(); i++) if (!ans[i]) a.push_back(aa[i]);
  }
  for (auto i : ans) cout<<i<<" ";
  cout<<"\n";
}
