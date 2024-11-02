#include <bits/stdc++.h>
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
int cnt[1010101];
vector<pair<int, int>> compress;
int n, m;
int now = 0;

void sub(int i) {
  cnt[a[i]]--;
  if (cnt[a[i]] == 0) now--;
}

void add(int i) {
  if (cnt[a[i]] == 0) now++;
  cnt[a[i]]++;
}

int main() {
  scanf("%d", &n); 
  sn = sqrt(n);
  a.resize(n+1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    compress.push_back({a[i], i});
  }

  sort(compress.begin(), compress.end());
  a[compress[0].second] = 0;
  for (int i = 1; i < n; i++) {
    auto [curr, cidx] = compress[i];
    auto [prev, pidx] = compress[i-1];
    if (curr == prev) a[cidx] = a[pidx];
    else a[cidx] = a[pidx]+1;
  }

  scanf("%d", &m);
  ans.resize(m);
  for (int i = 0; i < m; i++) {
    int s, e;
    scanf("%d%d", &s, &e);
    query.push_back({i, s, e});
  }
  sort(query.begin(), query.end());
  
  Q q = query[0];
  int s = q.s, e = q.e;
  for (int i = s; i <= e; i++) add(i); 
  ans[q.idx] = now;
  for (int i = 1; i < m; i++) {
    q = query[i];
    while (s < q.s) sub(s++);
    while (s > q.s) add(--s); 
    while (e < q.e) add(++e);
    while (e > q.e) sub(e--);
    ans[q.idx] = now;
  }
  for (auto a : ans) printf("%d\n", a);
}
