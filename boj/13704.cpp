#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 1000000;
const int SN = 1000;

struct Q {
  int s, e, idx;
  bool operator<(Q &t) {
    if (t.s/SN != s/SN) return s/SN < t.s/SN;
    return e < t.e;
  }
};
ll chk[1<<20], cnt;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  vector<int> a(n+1), p(n+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    p[i] = p[i-1]^a[i];
  }
  int m; cin>>m;
  vector<Q> query(m);
  for (int i = 0; i < m; i++) {
    int s, e; cin>>s>>e;
    query[i] = {s-1, e, i};
  }
  sort(query.begin(), query.end());
  auto add = [&](int x) { cnt += chk[x^k]; chk[x]++; };
  auto del = [&](int x) { chk[x]--; cnt -= chk[x^k]; };
  vector<int> ans(m);
  auto [s, e, i] = query[0];
  for (int i = s; i <= e; i++) add(p[i]);
  ans[i] = cnt;
  for (int i = 1; i < m; i++) {
    auto q = query[i];
    while (s > q.s) add(p[--s]);
    while (e < q.e) add(p[++e]); 
    while (s < q.s) del(p[s++]);
    while (e > q.e) del(p[e--]); 
    ans[q.idx] = cnt;
  }
  for (auto i : ans) cout<<i<<"\n";
}
