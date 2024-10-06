#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

vector<pair<double, double>> a;

int main() {
  int n, x, y, i; 
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    a.push_back({(double)x, (double)y});
  }

  double s1 = 0, s2 = 0;
  for (i = 0; i < n; i++) {
    s1 += a[i].first * a[(i+1)%n].second;
    s2 += a[(i+1)%n].first * a[i].second;
  }
  double ans = abs(s1 - s2) / 2;
  printf("%.1lf\n", ans);

  return 0;
}
