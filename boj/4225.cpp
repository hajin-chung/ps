#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<double, double> pdd;
pdd pivot;
int caseNum = 0;

int ccw(pdd p1, pdd p2, pdd p3) {
  double v = (p2.fi-p1.fi)*(p3.se-p1.se)-(p2.se-p1.se)*(p3.fi-p1.fi);
  if (v < 0) return -1;
  else if (v == 0) return 0;
  else return 1;
}

int dist(pdd p1, pdd p2) {
  double dx = p1.fi - p2.fi, dy = p1.se - p2.se;
  return dx*dx+dy*dy;
}

bool cmp(pdd p1, pdd p2) {
  int c = ccw(pivot, p1, p2);
  if (c == 0) return dist(pivot, p1) < dist(pivot, p2);
  return (c == 1);
}

bool solve() {
  caseNum++;
  int n;
  double x, y;
  vector<pdd> p, ch;
  scanf("%d", &n);
  if (n == 0) return false;
  int li = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &x, &y);
    p.push_back({x, y});
    if (p[i] < p[li]) li = i;
  }
  swap(p[li], p[0]);
  pivot = p[0];
  printf("pivot: %lf %lf\n", p[0].fi, p[0].se);
  sort(p.begin(), p.end(), cmp);
  for (int i = 0; i < n; i++) printf("%lf %lf\n", p[i].fi, p[i].se);

  stack<pdd> S;
  S.push(p[0]);
  S.push(p[1]);
  int next = 2;
  while (next < n) {
    while (S.size() >= 2) {
      pdd se = S.top(); S.pop();
      pdd fi = S.top();
      if (ccw(fi, se, p[next])) {
        S.push(se);
        break;
      }
    }
    S.push(p[next]);
    next++;
  }

  while (!S.empty()) {
    ch.push_back(S.top());
    S.pop();
  }

  for (int i = 0; i < ch.size(); i++) 
    printf("%lf %lf\n", ch[i].fi, ch[i].se);
  
  double ans = 10000000;
  for (int i = 0; i < ch.size(); i++) {
    pdd p1 = ch[i];
    pdd p2 = ch[(i+1)%ch.size()];
    double a = -(p2.se - p1.se);
    double b = (p2.fi - p1.fi);
    double c = -p1.se*b -p1.fi*a;
    double mx = 0;
    for (int j = 0; j < n; j++) 
      if (j != i && j != (i+1)%n) {
        double d = abs(a*ch[j].fi+b*ch[j].se+c)/sqrt(a*a+b*b);
        mx = max(mx, d);
      }
    ans = min(ans, mx);
  }
  ans += 0.005;
  printf("Case %d: %.2lf\n",caseNum, ans);
  return true;
}

int main() {
  while (solve()) {}
}
