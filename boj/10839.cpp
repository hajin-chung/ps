#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c) {
  ll r = 1LL*(b.fi-a.fi)*(c.se-a.se)-1LL*(b.se-a.se)*(c.fi-a.fi);
  return r < 0 ? -1 : r > 0;
}

vector<int> f(vector<pii> &a, int s, int e) {
  int n = a.size()-1;
  if (s + 1 == e) return {s, e};
  vector<int> hull;
  if (s == 0) {
    hull = f(a, e, n);
    hull.back() -= n;
    return hull;
  }
  hull.push_back(s);
  hull.push_back(s+1);
  for (int i = s+2; i <= e; i++) {
    while (hull.size() >= 2) {
      int se = hull.back(); hull.pop_back();
      int fi = hull.back();
      if (ccw(a[fi], a[se], a[i]) < 0) {
        hull.push_back(se);
        break;
      }
    }
    hull.push_back(i);
  }
  return hull;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pii> a(n+1);
  for (int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
  a[n] = a[0];
  int s, e; cin>>s>>e;
  auto ans = f(a, min(s, e), max(s, e));
  if (ans[0] == e) reverse(ans.begin(), ans.end());
  cout<<ans.size()<<"\n";
  for (auto idx : ans) cout<<idx<<" ";
  cout<<"\n";
}
