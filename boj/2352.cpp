#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x; cin>>n;
  vector<pii> a(n), t;
  for (auto &[s, e] : a) cin>>x>>s>>e;
  sort(all(a), [](pii &u, pii &v) {
    if (u.se == v.se) return u.fi > v.fi;
    return u.se < v.se;
  });
  t.push_back(a[0]);
  for (int i = 1; i < n; i++)
    if (a[i] != a[i-1])
      t.push_back(a[i]);
  vector<int> v;
  reverse(all(t));
  for (auto [s, e] : t) {
    int i = lower_bound(all(v), s)-v.begin();
    if (i == (int)v.size()) v.push_back(s);
    else v[i] = s;
  }
  cout<<v.size()<<"\n";
}
