#include <bits/stdc++.h>
using namespace std;

int ans = 0, n, m;
int adj[404][404];

void dfs(int curr) {
  if (curr == 1) ans++;
  for (int next = 1; next <= n; next++)
    if (adj[curr][next] > 0) {
      adj[curr][next]--;
      adj[next][curr]--;
      dfs(next);
    }
  printf("%d ", curr);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v]++;
    adj[v][u]++;
  }

  dfs(1);
  cout << ans << "\n";
}
