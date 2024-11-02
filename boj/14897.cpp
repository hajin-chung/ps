#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int sn;
struct Q {
  int idx, s, e;
  bool operator<(Q &x) {
    if (s/sn != x.s/sn) return s < x.s;
    return e < x.e;
  }
};
vector<Q> query;
vector<int> a, ans;
int cnt[MAX+5];
int n, m;

int main() {
  scanf("%d", &n); 
  sn = sqrt(n);
  a.resize(n+1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  ans.resize(m);
  for (int i = 0; i < m; i++) {
    int s, e;
    scanf("%d%d", &s, &e);
    query.push_back({i, s, e});
  }
  sort(query.begin(), query.end());
  
  int res = 0;
  Q q = query[0];
  int s = q.s, e = q.e;
  for (int i = s; i <= e; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) res++;
  }
  ans[q.idx] = res;
  for (int i = 1; i < m; i++) {
    q = query[i];
    while (s < q.s) {
      cnt[a[s++]]--;
      if (cnt[a[s-1]] == 0) res--;
    }
    while (s > q.s) {
      cnt[a[--s]]++;
      if (cnt[a[s]] == 1) res++;
    }
    while (e < q.e) {
      cnt[a[++e]]++;
      if (cnt[a[e]] == 1) res++;
    }
    while (e > q.e) {
      cnt[a[e--]]--;
      if (cnt[a[e+1]] == 0) res--;
    }
    ans[q.idx] = res;
  }
  for (auto a : ans) printf("%d\n", a);
}
