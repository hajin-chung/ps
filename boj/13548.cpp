#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int sn;
struct Q {
  int s, e, idx;
  bool operator<(Q &x) {
    if (s/sn != x.s/sn) return s/sn < x.s/sn; 
    return e < x.e;
  }
};

int n, m;
int a[MAX+5], cnt[MAX+5], ccnt[MAX+5];
vector<Q> query;
vector<int> ans;

int main() {
  scanf("%d", &n);
  sn = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  ans.resize(m);
  int s, e;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &s, &e);
    query.push_back({s, e, i});
  }
  sort(query.begin(), query.end());

  Q q = query[0];
  s = q.s, e = q.e;
  ccnt[0] = n;
  int mx = 0;
  for (int i = s; i <= e; i++) {
    cnt[a[i]]++;
    ccnt[cnt[a[i]]-1]--;
    ccnt[cnt[a[i]]]++;
    mx = max(mx, cnt[a[i]]);
  }
  ans[q.idx] = mx;

  for (int i = 1; i < m; i++) {
    int nmx = 0;
    q = query[i];
    while (s < q.s) {
      cnt[a[s++]]--;
      ccnt[cnt[a[s-1]]+1]--;
      ccnt[cnt[a[s-1]]]++;
      if (ccnt[cnt[a[s-1]]+1]) nmx = max(nmx, cnt[a[s-1]+1]);
      if (ccnt[cnt[a[s-1]]]) nmx = max(nmx, cnt[a[s-1]]);
    }
    while (s > q.s) {
      cnt[a[--s]]++;
      ccnt[cnt[a[s]]-1]--;
      ccnt[cnt[a[s]]]++;
      if (ccnt[cnt[a[s]]-1]) nmx = max(nmx, cnt[a[s]]-1);
      if (ccnt[cnt[a[s]]]) nmx = max(nmx ,cnt[a[s]]);
    }
    while (e < q.e) {
      cnt[a[++e]]++;
      ccnt[cnt[a[e]]-1]--;
      ccnt[cnt[a[e]]]++;
      if (ccnt[cnt[a[e]]-1]) nmx = max(nmx, cnt[a[e]]-1);
      if (ccnt[cnt[a[e]]]) nmx = max(nmx, cnt[a[e]]);
    }
    while (e > q.e) {
      cnt[a[e--]]--;
      ccnt[cnt[a[e+1]]+1]--;
      ccnt[cnt[a[e+1]]]++;
      if (ccnt[cnt[a[e+1]]+1]) nmx = max(nmx, cnt[a[e+1]]+1);
      if (ccnt[cnt[a[e+1]]]) nmx = max(nmx, cnt[a[e+1]]);
    }
    if (ccnt[mx] == 0) mx = nmx;
    else mx = max(mx, nmx);
    ans[q.idx] = mx;
  }

  for (auto aa : ans) printf("%d\n", aa);
}
