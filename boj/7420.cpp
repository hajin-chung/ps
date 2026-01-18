#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
int n, l;
vector<pii> points, hull;
pii pivot;

int pow2(int a) {return a*a;}
int dist(pii a, pii b) { return pow2(a.fi-b.fi)+pow2(a.se-b.se); }
int ccw(pii a, pii b, pii c) {
  int v = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi);
  return v != 0 ? v > 0 ? 1 : -1 : 0;
}
bool comp(pii a, pii b) {
  int v = ccw(pivot, a, b);
  if (v != 0) return v > 0;
  return dist(pivot, a) < dist(pivot, b);
}

int main() {
  scanf("%d%d",&n,&l);
  int idx = 0;
  for (int x, y, i = 0; i < n; i++) {
    scanf("%d%d",&x,&y);
    points.push_back({x, y});
    if (points[idx] > points[i]) idx = i;
  }
  pivot = points[idx];
  swap(points[0], points[idx]);
  sort(all(points), comp);
  stack<pii> s;
  s.push(points[0]);
  s.push(points[1]);
  for (int i = 2; i < n; i++) {
    while (s.size() >= 2) {
      pii second = s.top(); s.pop();
      pii first = s.top();
      if (ccw(first, second, points[i]) > 0) {
        s.push(second);
        break;
      }
    }
    s.push(points[i]);
  }
  double d = 0;
  pii first, curr;
  first = curr = s.top(); s.pop();
  while (!s.empty()) {
    pii next = s.top(); s.pop();
    d += sqrt(dist(curr, next));
    curr = next;
  }
  d += sqrt(dist(curr, first));
  d += (double)l * M_PI * 2.0;
  printf("%d\n", (int)(d+0.5));
}
