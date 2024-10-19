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
  int x, y, z;
  scanf("%d%d%d", &n, &m, &k);
  a.resize(n+1, 0);
  ft.resize(n+1, 0);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    update(i, a[i]);
  }

  for (int i = 0; i < m+k; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1) update(y, (ll)z);
    else printf("%lld\n", query(y, z));
  }
  for (int i = 1; i <= n; i++) printf("%lld ", ft[i]);
  printf("\n");
}
