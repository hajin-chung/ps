#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> a, ft;
int n, m, k;

void update(int idx, ll val) {
  ll diff = val - a[idx];
  a[idx] = val;
  while (idx <= n) {
    ft[idx] += diff;
    idx += idx & -idx;
  }
}

ll sum(int idx) {
  ll ret = 0;
  while (idx > 0) {
    ret += ft[idx];
    idx -= idx & -idx;
  }
  return ret;
}

ll query(int a, int b) {
  return sum(b) - sum(a-1);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  a.resize(n+1, 0);
  ft.resize(n+1, 0);
  for (int i = 1; i <= n; i++) {
    ll c;
    scanf("%lld", &c);
    update(i, c);
  }

  ll x, y, z;
  for (int i = 0; i < m+k; i++) {
    scanf("%lld%lld%lld", &x, &y, &z);
    if (x == 1) update(y, z);
    else printf("%lld\n", query(y, z));
  }
}
