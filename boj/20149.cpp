#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Point {
  ll x, y;
};

Point p1, p2, p3, p4;

int ccw(Point p1, Point p2, Point p3) {
  ll c = (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
  if (c == 0) return 0;
  return c > 0;
}

int main() {
  scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
  scanf("%d %d %d %d", &p3.x, &p3.y, &p4.x, &p4.y);
  int c1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int c2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
  if (c1 == 0 && c2 == 0) printf("0\n");
  else if (c1 <= 0 && c2 <= 0) {
    printf("1\n")
  } else {
    printf("0\n");
  }
}
