#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> ppi;
ll bit[100005], a[100005];
int n, m;
vector<vector<ppi>> sum_query;
vector<pil> update_query;
vector<ll> ans;

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
  int sqcnt = 0;
  sum_query.resize(m+1);
  update_query.push_back({0, 0});
  for (int i = 0; i < m; i++) {
    int q; 
    scanf("%d", &q);
    if (q == 1) {
      int idx;
      ll v;
      scanf("%d%lld", &idx, &v);
      update_query.push_back({idx, v});
    } else {
      int k, l, h;
      scanf("%d%d%d", &k, &l, &h);
      sum_query[k].push_back({{l, h}, sqcnt++});
    }
  }

  for (int i = 1; i <= n; i++) printf("%lld ", query(i, i));

  ans.resize(sqcnt);
  for (int i = 0; i < update_query.size(); i++) {
    if (i != 0) {
      auto [idx, v] = update_query[i];
      update(idx, v);
    }
    for (auto [lh, sqidx] : sum_query[i]) {
      auto [l, h] = lh;
      ans[sqidx] = query(l, h);
    }
  }

  for (auto a : ans) printf("%lld\n", a);
}
