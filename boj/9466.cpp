#include <bits/stdc++.h>
using namespace std;

vector<int> chk, adj;
int ans;

int dfs(int curr, int id) {
  chk[curr] = id;
  int next = adj[curr];
  if (next == curr) {
    ans++;
    return -1;
  } else if (chk[next] == id) {
    ans++;
    return next;
  } else if (chk[next] == 0) {
    int v = dfs(adj[curr], id);
    if (v > 0) ans++;
    if (curr == v) return -1;
    else return v;
  }
  return -1;
}

void solve() {
  int n;
  adj.resize(0);
  chk.resize(0);
  ans = 0;
  scanf("%d", &n);
  adj.resize(n+1, 0);
  chk.resize(n+1, 0);
  ans = 0;

  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &adj[i]);
  }

  for (int i = 1; i <= n; i++) 
    if (!chk[i])
      dfs(i, i);
  printf("%d\n", n - ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) solve();
}

