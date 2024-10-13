#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<double, double> pdd;
int caseNum = 0;

bool solve() {
  caseNum++;
  int n;
  double x, y;
  vector<pdd> p;
  cin >> n; 
  if (n == 0) return false;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p.push_back({x, y});
  }
  
  double ans = 10000000;
  for (int i = 0; i < n; i++) {
    pdd p1 = p[i];
    pdd p2 = p[(i+1)%n];
    double a = -(p2.se - p1.se);
    double b = (p2.fi - p1.fi);
    double c = -p1.se*b -p1.fi*a;
    double mx = 0;
    for (int j = 0; j < n; j++) 
      if (j != i && j != (i+1)%n) {
        double d = abs(a*p[j].fi+b*p[j].se+c)/sqrt(a*a+b*b);
        mx = max(mx, d);
      }
    ans = min(ans, mx);
  }
  ans += 0.005;
  printf("Case %d: %.2lf\n",caseNum, ans);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (solve()) {}
}
