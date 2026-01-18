#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
int sn;
struct Q {
  int s, e, idx;
  bool operator<(Q &x) {
    if (s/sn != x.s/sn) return s < x.s;
    return e < x.e;
  }
};
vector<ll> a, ans;
vector<Q> query;
ll cnt[1010101];
ll now;
int n, t;

ll pow2(ll x) { return x*x; }

void add(int i) {
  cnt[a[i]]++;
  now += (pow2(cnt[a[i]]) - pow2(cnt[a[i]]-1))*a[i];
}

void sub(int i) {
  now -= (pow2(cnt[a[i]]) - pow2(cnt[a[i]]-1))*a[i];
  cnt[a[i]]--;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> t;
  a.resize(n);
  ans.resize(t);
  sn = sqrt(n);
  for (auto &x : a) cin >> x;
  for (int i = 0, s, e; i < t; i++) {
    cin >> s >> e;
    query.push_back({s-1, e-1, i});
  }
  sort(all(query));

  Q q = query[0];
  int s = q.s, e = q.e, idx = q.idx;
  for (int i = s; i <= e; i++) add(i);
  ans[idx] = now;
  
  for (int i = 1; i < t; i++) {
    q = query[i];
    while (s < q.s) sub(s++);
    while (s > q.s) add(--s);
    while (e < q.e) add(++e);
    while (e > q.e) sub(e--);
    ans[q.idx] = now;
  }
  
  for (auto x : ans) cout << x << "\n";
}
