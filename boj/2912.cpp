#include <bits/stdc++.h>
#define N 300005
#define C 10005
using namespace std;

int sn;
struct Q {
  int s, e, idx;
  bool operator<(Q &x) {
    if (s/sn != x.s/sn) return s/sn < x.s/sn;
    return e < x.e;
  }
  int size() {
    return e-s+1;
  }
};

int n, c, m;
int a[N], cnt[C];
vector<Q> query;
vector<int> ans;

int main() {
  scanf("%d%d", &n, &c);
  sn = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  ans.resize(m);
  for (int i = 0; i < m; i++) {
    int s, e;
    scanf("%d%d", &s, &e);
    query.push_back({s, e, i});
  }
  sort(query.begin(), query.end());

  Q q = query[0];
  int s = q.s, e = q.e;
  for (int i = s; i <= e; i++) cnt[a[i]]++;
  ans[q.idx] = -1;
  for (int i = 1; i <= c; i++) if (cnt[i] > q.size()/2) ans[q.idx] = i;

  for (int i = 1; i < m; i++) {
    Q q = query[i];
    while (s < q.s) cnt[a[s++]]--;
    while (s > q.s) cnt[a[--s]]++;
    while (e < q.e) cnt[a[++e]]++;
    while (e > q.e) cnt[a[e--]]--;

    ans[q.idx] = -1;
    for (int j = 1; j <= c; j++) 
      if (cnt[j] > q.size()/2) {
        ans[q.idx] = j;
        break;
      }
  }
  for (auto aa : ans) {
    if (aa == -1) printf("no\n");
    else printf("yes %d\n", aa);
  }
}
