#include <bits/stdc++.h>
#define fi first
#define se second
#define N 1000
using namespace std;

typedef pair<int, int> pii;

bool solve() {
  int n, m; cin>>n>>m;
  if (n == 0 && m == 0) return false;
  int a[N+1][N+1], d[N+1][N+1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin>>a[i][j];
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
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (solve()) {};
}
