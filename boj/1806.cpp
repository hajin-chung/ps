#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s;

int main() {
  int i, lo, hi, x, m;
  int mn = 100005;
  scanf("%d %d", &n, &m);
  s.push_back(0);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    s.push_back(s[i] + x);
  }

  lo = 1;
  hi = 1;
  while (lo <= hi && hi <= n) {
    int sum = -s[lo-1] + s[hi];
    if (sum >= m && hi - lo + 1 < mn) mn = hi - lo + 1;
    if (sum >= m) lo++;
    else hi++;
  }
  if (mn == 100005) printf("0\n");
  else printf("%d\n", mn);
}
