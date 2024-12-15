#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long double ld;
struct pt { ld x, y; };
int n;
vector<pt> a;

ld dist(pt a, pt b) {
  ld dx = a.x-b.x;
  ld dy = a.y-b.y;
  return sqrt(dx*dx+dy*dy);
}

pt get_circle(pt a, pt b) {
  pt c = pt {(a.x+b.x)/2, (a.y+b.y)/2};
  return c;
}

pt get_circle(pt a, pt b, pt c) {
  ld aa = a.x*a.x+a.y*a.y;
  ld bb = b.x*b.x+b.y*b.y;
  ld cc = c.x*c.x+c.y*c.y;
  ld dd = 2*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
  /*if (fabs(dd) < 1e-14) {*/
  /*  ld ab = dist(a, b);*/
  /*  ld bc = dist(b, c);*/
  /*  ld ca = dist(c, a);*/
  /*  if (ab > bc && ab > ca) return get_circle(a, b);*/
  /*  if (bc > ab && bc > ca) return get_circle(b, c);*/
  /*  if (ca > bc && ca > ab) return get_circle(c, a);*/
  /*}*/
  ld ux = (aa*(b.y-c.y)+bb*(c.y-a.y)+cc*(a.y-b.y))/dd;
  ld uy = (aa*(c.x-b.x)+bb*(a.x-c.x)+cc*(b.x-a.x))/dd;
  return {ux, uy};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n);
  for (auto &[x, y] : a) cin>>x>>y;
  pt c = a[0];
  ld r = -1;
  for (int i = 0; i < n; i++) if (dist(c, a[i]) > r) {
    c = a[i]; r = 0;
    for (int j = 0; j < i; j++) if (dist(c, a[j]) > r) {
      c = get_circle(a[i], a[j]); r = dist(c, a[i]);
      for (int k = 0; k < j; k++) if (dist(c, a[k]) > r) {
        c = get_circle(a[i], a[j], a[k]); r = dist(c, a[k]);
      }
    }
  }
  cout<<fixed<<setprecision(3);
  cout<<c.x<<" "<<c.y<<"\n"<<r<<"\n";
}
