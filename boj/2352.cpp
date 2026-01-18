#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x; cin>>n;
  vector<pii> a(n);
  for (auto &[s, e] : a) cin>>x>>s>>e;
  sort(all(a), [](pii &u, pii &v) {
    if (u.se == v.se) return u.fi > v.fi;
    return u.se < v.se;
  });
  a.erase(unique(all(a)), a.end());
  vector<int> v;
  reverse(all(a));
  for (auto [s, e] : a) {
    int i = upper_bound(all(v), s)-v.begin();
    if (i == (int)v.size()) v.push_back(s);
    else v[i] = s;
  }
  cout<<v.size()<<"\n";
}
