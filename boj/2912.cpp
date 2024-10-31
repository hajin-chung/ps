#include <bits/stdc++.h>
#define N 300005
#define C 10005
using namespace std;

int sn;
struct Q {
  int s, e, idx;
  bool operator < (Q &x) {
    if (s/sn != x.s/sn) return e < x.e;
    return s/sn < x.s/sn;
  }
  int size() {
    return e-s+1;
  }
};

int n, m, mx;
int a[N], cnt[C];
vector<Q> query;
vector<int> ans;

int main() {
  scanf("%d%d", &n, &m);
  sn = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int q;
  scanf("%d", &q);
  ans.resize(q);
  for (int i = 0; i < q; i++) {
    int s, e;
    scanf("%d%d", &s, &e);
    query.push_back({s, e, i});
  }
  sort(query.begin(), query.end());

  mx = -1;
  int s = query[0].s, e = query[0].e;
  for (int i = s; i <= e; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] > query[0].size()/2) mx = a[i];
  }
  ans[query[0].idx] = mx;

  for (int i = 1; i < q; i++) {
    Q q = query[i];
    while (s < q.s) cnt[a[s++]]--;
    while (s > q.s) cnt[a[--s]]++;
    while (e < q.e) cnt[a[++e]]++;
    while (e > q.e) cnt[a[e--]]--;
    ans[q.idx] = -1;
    for (int j = 1; j <= m; j++) 
      if (cnt[j] > q.size()/2)
        ans[q.idx] = j;
  }
  for (auto aa : ans) {
    if (aa == -1) printf("no\n");
    else printf("yes %d\n", aa);
  }
}
