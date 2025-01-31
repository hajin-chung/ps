#include <bits/stdc++.h>
#define fi first
#define se second
#define N 15000
#define M 1500
using namespace std;

typedef pair<int, int> pii;
vector<vector<int>> a;
int d[N+1][M+1];

void solve() {
  int n, m; cin>>n>>m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    string s; cin>>s;
    a[i].resize(m);
    for (int j = 0; j < m; j++) a[i][j] = (s[j] == '1');
  }
  sort(a.begin(), a.end(), [&](vector<int> &u, vector<int> &v) {
    for (int i = 0; i < m; i++) {
      if (u[i] && !v[i]) return 1;
      if (!u[i] && v[i]) return 0;
    }
    return 0;
  });
  for (int j = 0; j < m; j++) {
    d[0][j] = a[0][j];
    for (int i = 1; i < n; i++) {
      if (a[i][j]) d[i][j] = d[i-1][j] + 1;
      else d[i][j] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    stack<pii> s;
    for (int j = 0; j < m; j++) {
      while (!s.empty() && s.top().se >= d[i][j]) {
        auto [idx, h] = s.top(); s.pop();
        int w = s.empty() ? j : j - s.top().fi - 1;
        ans = max(ans, h * w);
      }
      s.push({j, d[i][j]});
    }
    while (!s.empty()) {
      auto [idx, h] = s.top(); s.pop();
      int w = s.empty() ? m : m - s.top().fi - 1;
      ans = max(ans, h * w);
    }
  }
  cout<<ans<<endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
