#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long int ll;
int n, m;
vector<ll> a, cnt, lsum;

void update(int type, int idx, ll diff) {
  while (idx <= n) {
    if (type == 0) cnt[idx] += diff;
    else lsum[idx] += diff;
    idx += idx&-idx;
  }
}

void update(ll l, ll r) {
  update(0, l, (ll)1);  
  update(0, r+1, (ll)-1);  
  update(1, l, -l);
  update(1, r+1, l);
}

ll query(int type, int idx) {
  ll ret = 0;
  while (idx > 0) {
    if (type == 0) ret += cnt[idx];
    else ret += lsum[idx];
    idx -= idx&-idx;
  }
  return ret;
}

ll query(int idx) {
  return query(0, idx)*(idx+1) + query(1, idx) + a[idx];
}

int main() {
  scanf("%d", &n);
  a.resize(n+1);
  cnt.resize(n+1);
  lsum.resize(n+1);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  scanf("%d", &m);
  while (m--) {
    int q;
    scanf("%d", &q);
    if (q == 1) {
      ll l, r;
      scanf("%lld%lld", &l, &r);
      update(l, r);
    } else {
      int idx;
      scanf("%d", &idx);
      printf("%lld\n", query(idx));
    }
  }
}
