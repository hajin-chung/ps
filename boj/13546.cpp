#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int sn;
struct Q {
  int s, e, idx;
  bool operator<(Q &x) {
    if (s/sn == x.s/sn) return e < x.e;
    return s < x.s;
  }
};
vector<Q> queries;
int n, k, m;
vector<int> a;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k; a.resize(n+1);
  sn = sqrt(n);
  for (int i = 1; i <= n; i++) cin>>a[i];
  cin>>m;
  for (int i = 0; i < m; i++) {
    int s, e; cin>>s>>e;
    queries.push_back({s, e, i});
  }
  sort(all(queries));
  vector<int> ans(m);

  vector<set<int>> idx(k+1, set<int>());
  multiset<int> diffs;
  auto [s, e, qi] = queries[0];
  for (int i = s; i <= e; i++) {
    idx[a[i]].insert(i);
    int diff = max(*idx[a[i]].rbegin()-i, i-*idx[a[i]].begin());
    if (diff) diffs.insert(diff);
  }
  ans[qi] = diffs.empty()?0:*diffs.rbegin();
  for (int i = 1; i < m; i++) {
    auto q = queries[i];
    while (s < q.s) {
      idx[a[s]].erase(s);
      if (!idx[a[s]].empty()) {
        int diff = max(*idx[a[s]].rbegin()-s, s-*idx[a[s]].begin());
        if (diff) diffs.erase(diff);
      }
      s++;
    }
    while (s > q.s) {
      s--;
      idx[a[s]].insert(s);
      int diff = max(*idx[a[s]].rbegin()-s, s-*idx[a[s]].begin());
      if (diff) diffs.insert(diff);
    }
    while (e < q.e) {
      e++;
      idx[a[e]].insert(e);
      int diff = max(*idx[a[e]].rbegin()-e, e-*idx[a[e]].begin());
      if (diff) diffs.insert(diff);
    }
    while (e > q.e) {
      idx[a[e]].erase(e);
      if (!idx[a[e]].empty()) {
        int diff = max(*idx[a[e]].rbegin()-s, s-*idx[a[s]].begin());
        if (diff) diffs.erase(diff);
      }
      e--;
    }
    ans[q.idx] = diffs.empty()?0:*diffs.rbegin();
  }
  for (auto ai : ans) cout<<ai<<"\n";
}
