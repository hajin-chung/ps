#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct Point { double x, y; };
int n;
vector<Point> a;

double dist(Point a, Point b) {
  double dx = a.x-b.x;
  double dy = a.y-b.y;
  return dx*dx+dy*dy;
}

Point get_circle(Point a, Point b) {
  Point c = Point {(a.x+b.x)/2, (a.y+b.y)/2};
  return c;
}

Point get_circle(Point a, Point b, Point c) {
  Point center = Point {
    -((b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y)*(c.y-b.y)-(b.x*b.x-c.x*c.x+b.y*b.y-c.y*c.y)*(a.y-b.y))/(2*(a.x-b.x)*(c.y-b.y)-2*(c.x-b.x)*(a.y-b.y)),
    -((b.y*b.y-a.y*a.y+b.x*b.x-a.x*a.x)*(c.x-b.x)-(b.y*b.y-c.y*c.y+b.x*b.x-c.x*c.x)*(a.x-b.x))/(2*(a.y-b.y)*(c.x-b.x)-2*(c.y-b.y)*(a.x-b.x)),
  };
  return center;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n);
  for (auto &[x, y] : a) cin>>x>>y;
  Point c = a[0];
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
  cout<<setprecision(3)<<2*sqrt(r)<<"\n";
}
