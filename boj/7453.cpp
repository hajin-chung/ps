#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
ll cnt;
vector<ll> a[4], s1, s2;

int main() {
  int i, j;
  ll x;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < 4; j++) {
      scanf("%lld", &x);
      a[j].push_back(x);
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      s1.push_back(a[0][i] + a[1][j]);
      s2.push_back(a[2][i] + a[3][j]);
    }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  for (auto sum1 : s1) {
    auto lo = lower_bound(s2.begin(), s2.end(), -sum1);
    auto hi = upper_bound(s2.begin(), s2.end(), -sum1);
    cnt += hi - lo;
  }
  printf("%lld\n", cnt);
}
