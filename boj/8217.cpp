#include <bits/stdc++.h>
#define N 303030
#define pb push_back
using namespace std;

typedef long long int ll;

int n, m, q;
vector<int> a[N];
vector<tuple<int, int, ll>> queries;
ll tree[N], goal[N];
int l[N], r[N], ans[N];

ll query(int i) {
  ll sum = 0;
  while (i > 0) {
    sum += tree[i];
    i -= i&-i;
  }
  return sum;
}

void update(int i, ll v) {
  while (i <= m) {
    tree[i] += v;
    i += i&-i;
  }
}

void range_update(int lo, int hi, ll v) {
  if (hi < lo) {
    update(lo, v);
    update(1, v);
    update(hi+1, -v);
  } else {
    update(lo, v);
    update(hi+1, -v);
  }
}

int main() {
  int i, j, k, x;
  bool flag;

  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    a[x].pb(i);
  }
  for (i = 1; i <= n; i++) 
    scanf("%lld", &goal[i]);
  for (i = 1; i <= n; i++) ans[i] = -1;

  scanf("%d", &q);
  queries.resize(q+1);
  for (i = 1; i <= q; i++) {
    int lo, hi;
    ll v;
    scanf("%d %d %lld", &lo, &hi, &v);
    queries[i] = {lo, hi, v};
  }

  for (i = 1; i <= n; i++) {
    l[i] = 1; r[i] = q;
  }

  while (true) {
    for (i = 0; i <= m+1; i++) tree[i] = 0;    

    vector<int> g[N];
    flag = false;
    for (i = 1; i <= n; i++)
      if (l[i] <= r[i]) {
        flag = true;
        g[(l[i]+r[i])>>1].pb(i);
      }
    if (!flag) break;

    for (i = 1; i <= q; i++) {
      auto [lo, hi, v] = queries[i];
      range_update(lo, hi, v);
      for (j = 0; j < g[i].size(); j++) {
        int qi = g[i][j];
        ll sum = 0;
        for (k = 0; k < a[qi].size(); k++) {
          sum += query(a[qi][k]);
          if (sum >= goal[qi]) break;
        }
        if (goal[qi] <= sum) {
          r[qi] = i - 1;
          ans[qi] = i;
        } else l[qi] = i + 1;
      }
    }
  }

  for (i = 1; i <= n; i++) {
    if (ans[i] == -1) printf("NIE\n");
    else printf("%d\n", ans[i]);
  }
}
