#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
int n;
vector<pii> a;

bool comp(pii x, pii y) { return abs(x.fi-x.se) < abs(y.fi-y.se); }
bool contains(pii x, pii y) {
  if (x.se < x.fi) swap(x.se, x.fi);
  if (y.se < y.fi) swap(y.se, y.fi);
  return x.fi < y.fi && y.se < x.se;
}

int solve() {
  vector<int> dp(n, 1);
  sort(all(a), comp); 
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++)
      if (contains(a[i], a[j]) && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
  int ret = 0;
  for (auto d : dp) 
    ret = max(ret, d);
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n);
  for (auto &[x, y]: a) {
    cin >> x >> y;
    x--; y--;
  }

  int ans = 0;
  for (int i = 0; i < 100; i ++) {
    for (auto &[s, e] : a) {
      s = (s - 1 + 100) % 100;
      e = (e - 1 + 100) % 100;
    }
    ans = max(ans, solve());
  }
  cout << ans << "\n";
}
