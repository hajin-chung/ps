#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long int ll;
int n, m;
ll bit[N];

// bit[i] = a[i] - a[i-1]
// a[i] = bit[i] + bit[i-1] + ... + bit[1]
// add 4 on 1 to 3 -> bit[1] += 4, bit[3+1] -= 4

void update(int idx, ll diff) {
  while (idx <= n) {
    bit[idx] += diff;
    idx += idx&-idx;
  }
}

void update(int s, int e, ll diff) {
  update(s, diff);
  update(e+1, -diff);
}

ll sum(int idx) {
  ll ret = 0; 
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx&-idx;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    update(i, i, x);
  }
  scanf("%d", &m);
  while (m--) {
    int q;
    scanf("%d", &q);
    if (q == 1) {
      int s, e;
      ll diff;
      scanf("%d%d%lld", &s, &e, &diff);
      update(s, e, diff);
    } else {
      int idx;
      scanf("%d", &idx);
      printf("%lld\n", sum(idx));
    }
  }
}
