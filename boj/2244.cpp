#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
struct P {
  int x, y;
  bool operator<(P &rhs) {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
  P operator+(const P &rhs) {
    return {x+rhs.x, y+rhs.y};
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
  for (int i = 1; i < n; i++) if (a[i] < a[0]) swap(a[i], a[0]);
  sort(a.begin(), a.end(), [&](P u, P v) {
    int c = ccw(a[0], u, v);
    if (c == 0) return dist(a[0], u) < dist(a[0], v);
    return c > 0;
  });
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
  int n, m; cin>>n>>m;
  vector<P> a(n), b(m), pt;
  for (auto &[x, y] : a) cin>>x>>y;
  for (auto &[x, y] : b) cin>>x>>y;
  for (auto [ax, ay] : a)
    for (auto [bx, by] : b)
      pt.push_back({ax+bx, ay+by});
  auto hull = get_hull(pt);
  cout<<hull.size()<<"\n";
  for (auto [x, y] : hull)
    cout<<x<<" "<<y<<"\n";
}
