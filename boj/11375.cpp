#include <bits/stdc++.h>
using namespace std;

vector<int> a[1005];
int d[1005], c[1005];
int n, m;

bool dfs(int x) {
  for (auto t : a[x]) {
    if (c[t]) continue;
    c[t] = true;
    if (d[t] == 0 || dfs(d[t])) {
      d[t] = x;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    int k; cin>>k;
    while (k--) {
      int x; cin>>x;
      a[i].push_back(x);
    }
  }

  int cnt = 0;
  for (int i=1; i <= n; i++) {
    fill(c, c+1000, false);
    if (dfs(i)) cnt++;
  }
  cout<<cnt<<"\n";
}
