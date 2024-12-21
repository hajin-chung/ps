#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;
struct P { double x, y, z; };

double dist(P a, P b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dz = a.z - b.z;
  return dx*dx+dy*dy+dz*dz;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<P> a(n);
  for (auto &[x, y, z] : a) cin>>x>>y>>z;
  double delta = 1.0;
  P u = a[0];
  int tries = 10000;
  while (tries--) {
    P v = a[0];
    double d = 0;
    for (auto p : a) {
      double r = dist(u, p);
      if (d < r) {
        v = p;
        d = r;
      }
    }
    u.x += (v.x - u.x + EPS) * delta; 
    u.y += (v.y - u.y + EPS) * delta; 
    u.z += (v.z - u.z + EPS) * delta; 
    delta *= 0.95;
  }
  double rad = 0;
  for (auto p : a) rad = max(rad, dist(u, p));
  cout<<fixed<<setprecision(2)<<sqrt(rad)<<"\n";
}
