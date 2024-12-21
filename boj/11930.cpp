#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = 1e-12;
struct P { ld x, y, z; };

ld dist(P a, P b) {
  ld dx = a.x - b.x;
  ld dy = a.y - b.y;
  ld dz = a.z - b.z;
  return dx*dx+dy*dy+dz*dz;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<P> a(n);
  for (auto &[x, y, z] : a) cin>>x>>y>>z;
  P u = {0, 0 ,0};
  for (auto [x, y, z] : a) {
    u.x += x;
    u.y += y;
    u.z += z;
  }
  u.x /= n; u.y /= n; u.z /= n;
  ld delta = 1.0;
  int tries = 1000000;
  while (tries--) {
    P v = a[0];
    ld d = 0;
    for (auto p : a) {
      ld r = dist(u, p);
      if (d < r) {
        v = p;
        d = r;
      }
    }
    u.x += (v.x - u.x + EPS) * delta; 
    u.y += (v.y - u.y + EPS) * delta; 
    u.z += (v.z - u.z + EPS) * delta; 
    delta *= 0.999;
  }
  ld rad = 0;
  for (auto p : a) rad = max(rad, dist(u, p));
  cout<<fixed<<setprecision(2)<<sqrt(rad)<<"\n";
}
