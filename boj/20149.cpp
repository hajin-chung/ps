#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int bit[500005], n;

void update(int idx, int diff) {
  while (idx <= n) {
    bit[idx] += diff;
    idx += idx & -idx;
  }
}

ll sum(int idx) {
  ll ret = 0;
  while (idx > 0) {
    ret += bit[idx]; 
    idx -= idx & -idx;
  } 
  return ret;
}

ll query(int idx) {
  return sum(n) - sum(idx-1);
}

int main() {
  ll ans = 0;
  int x;
  map<int, int> idx;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    idx[x] = i+1;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    ans += query(idx[x]);
    update(idx[x], 1);
  }
  printf("%lld\n", ans);
}
