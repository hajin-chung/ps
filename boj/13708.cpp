#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct pt { double x, y; };
int n;
vector<pt> a;

double dist(pt a, pt b) {
  double dx = a.x-b.x;
  double dy = a.y-b.y;
  return dx*dx+dy*dy;
}

pt get_circle(pt a, pt b) {
  pt c = pt {(a.x+b.x)/2, (a.y+b.y)/2};
  return c;
}

pt get_circle(pt a, pt b, pt c) {
  double aa = a.x*a.x+a.y*a.y;
  double bb = b.x*b.x+b.y*b.y;
  double cc = c.x*c.x+c.y*c.y;
  double dd = 2*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
  if (fabs(dd) < 1e-14) {
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ca = dist(c, a);
    if (ab > bc && ab > ca) return get_circle(a, b);
    if (bc > ab && bc > ca) return get_circle(a, b);
    if (ca > bc && ca > ab) return get_circle(a, b);
  }
  double ux = (aa*(b.y-c.y)+bb*(c.y-a.y)+cc*(a.y-b.y))/dd;
  double uy = (aa*(c.x-b.x)+bb*(a.x-c.x)+cc*(b.x-a.x))/dd;
  return {ux, uy};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n);
  for (auto &[x, y] : a) cin>>x>>y;
  pt c = a[0];
  double r = -1;
  for (int i = 0; i < n; i++) if (dist(c, a[i]) > r) {
    c = a[i]; r = 0;
    for (int j = 0; j < i; j++) if (dist(c, a[j]) > r) {
      c = get_circle(a[i], a[j]); r = dist(c, a[i]);
      for (int k = 0; k < j; k++) if (dist(c, a[k]) > r) {
        c = get_circle(a[i], a[j], a[k]); r = dist(c, a[k]);
      }
    }
  }
  /*cout<<c.x<<" "<<c.y<<"\n"<<r<<"\n";*/
  cout<<fixed<<setprecision(2)<<2*sqrt(r)<<"\n";
}
