#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int sn = 2000;
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
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n);
  for (auto &x : a) cin >> x;
  auto tmp  = a;
  sort(all(tmp));
  tmp.erase(unique(all(tmp)), tmp.end());
  for (auto &x : a) x = lower_bound(all(tmp), x) - tmp.begin();

  cin >> m; ans.resize(m);
  for (int i = 0; i < m; i++) {
    int s, e;
    cin >> s >> e;
    query.push_back({i, s-1, e-1});
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
  for (auto a : ans) cout << a << "\n";
}
