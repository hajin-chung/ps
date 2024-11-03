#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
int n;
vector<pii> a;
vector<int> dp;

int range_size(pii x) { return abs(x.fi - x.se); }
bool comp(pii x, pii y) { return range_size(x) < range_size(y); }
bool contains(pii x, pii y) {
  if (x.se < x.fi) swap(x.se, x.fi);
  if (y.se < y.fi) swap(y.se, y.fi);
  return x.fi < y.fi && y.se < x.se;
}

int find_max(pii range) {
  int ret = 0;
  for (int i = 0; i < n; i++)
    if (contains(range, a[i]))
      ret = max(ret, dp[i]);
  /*cout << "range query: " << range.fi << " " << range.se << " " << ret << "\n";*/
  return ret;
}

int solve() {
  int ret = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (contains(a[i], a[j])) {
        int ls = a[i].fi, le = a[j].fi, rs = a[j].se, re = a[i].se;
        int cnt = find_max({ls, le}) + find_max({rs, re}) + dp[j] + 1;
        dp[i] = max(dp[i], cnt);
        ret = max(ret, dp[i]);
      }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n);
  dp.resize(n, 1);
  for (auto &[x, y]: a) {
    cin >> x >> y;
    x--; y--;
    if (x > y) swap(x, y);
  }

  int ans = 0;
  for (int i = 0; i < 100; i++) {
    for (auto &[s, e] : a) {
      s = (s+99)%100;
      e = (e+99)%100;
      if (e < s) swap(e, s);
    }
    sort(all(a), comp); 
    /*for (auto ai : a) */
    /*  cout << ai.fi << " " << ai.se << " " << range_size(ai) << endl;*/
    ans = max(ans, solve());
  }

  cout << ans << "\n";
}
