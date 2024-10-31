#include <bits/stdc++.h>
using namespace std;

int sqrtN;
struct Q {
  int idx, s, e;
  bool operator < (Q &x) {
    if (s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
    return e < x.e;
  }
};

vector<Q> query;
vector<int> a, ans;
int n, m, cnt[100005], ucnt;

int main() {
  scanf("%d", &n);
  sqrtN = sqrt(n);
  a.resize(n+1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  ans.resize(m);
  for (int i = 0; i < m; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    query.push_back({i, s, e});
  }
  sort(query.begin(), query.end());
  ucnt = 0;
  int s = query[0].s, e = query[0].e;
  for (int i = s; i <= e; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) ucnt++;
  }
  ans[query[0].idx] = ucnt;
  for (int i = 1; i < m; i++) {
    while (s < query[i].s) {
      if (cnt[a[s]] == 1) ucnt--;
      cnt[a[s++]]--;
    }
    while (s > query[i].s) {
      cnt[a[--s]]++;
      if (cnt[a[s]] == 1) ucnt++;
    }
    while (e < query[i].e) {
      cnt[a[++e]]++;
      if (cnt[a[e]] == 1) ucnt++;
    }
    while (e > query[i].e) {
      if (cnt[a[e]] == 1) ucnt--;
      cnt[a[e--]]--;
    }
    ans[query[i].idx] = ucnt;
  }
  for (auto a : ans) printf("%d\n", a);
}
