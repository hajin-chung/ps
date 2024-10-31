#include <bits/stdc++.h>
using namespace std;

int sqrtN;
struct Q {
  int idx, s, e;
  bool operator<(Q &x) {
    if (s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
    return e < x.e;
  }
};

vector<Q> query;
vector<int> a, ans;
int n, m, cnt[100005], mxcnt, mx;

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
  mx = mxcnt = 0;
  for (int i = query[0].s; i <= query[0].e; i++) {
    cnt[a[i]]++;
    mx = max(mx, cnt[a[i]]);
  }
}
