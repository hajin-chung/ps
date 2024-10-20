#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll bit[100005], a[100005];
int n, m;

void update(int idx, int val) {
  ll diff = val - a[idx];
  a[idx] = val;
  while (idx <= n) {
    bit[idx] += diff;
    idx += idx&-idx;
  }
}

ll sum(int idx) {
  ll ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx&-idx;
  }
  return ret;
}

ll query(int s, int e) {
  return sum(e) - sum(s-1);
}

int main() {
  ll x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    update(i, x);
  }
  scanf("%d", &m);
}
