#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
const int MOD = 1e9;
typedef long long int ll;
vector<int> t[N+1], g[N+1];
int ind[N+1];
ll dp[N+1];
bool chk[N+1];

void f(int u) {
  g[u] = t[u];
  for (auto v : g[u])
    if (!chk[v]) {
      chk[v] = 1;
      f(v);
    }
}

int main() {
  int n, m; scanf("%d%d",&n,&m);
  while (m--) {
    int u, v; cin>>u>>v;
    t[u].push_back(v);
  }
  chk[1] = 1;
  f(1);
  for (int u = 1; u <= n; u++)
    for (auto v : g[u])
      ind[v]++;
  if (!chk[2]) {
    printf("0\n");
    return 0;
  }
  if (ind[1] != 0) {
    printf("inf\n");
    return 0;
  }
  queue<int> q;
  dp[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : g[u]) {
      dp[v] += dp[u]; dp[v] %= MOD;
      if (--ind[v] == 0) q.push(v);
    }
  }
  if (dp[2] == 0) printf("inf\n");
  else printf("%09d\n", (int)dp[2]);
}
