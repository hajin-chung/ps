#include <bits/stdc++.h>
#define N 200000
using namespace std;

int n, m;
int bit[N+5], lookup[N+5], top;

void update(int idx, int diff) {
  while (idx <= N) {
    bit[idx] += diff;
    idx += idx&-idx;
  }
}

int sum(int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx&-idx;
  }
  return ret;
}

int query(int idx) {
  int ret = sum(N) - sum(lookup[idx]);
  update(lookup[idx], -1);
  lookup[idx] = top++;
  update(lookup[idx], 1);
  return ret;
}

void solve() {
  scanf("%d %d", &n, &m);
  memset(bit, 0, sizeof(bit));
  memset(lookup, 0, sizeof(lookup));
  top = n+1;
  for (int i = 1; i <= n; i++) {
    update(i, 1);
    lookup[i] = n - i + 1;
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    printf("%d ", query(x));
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
