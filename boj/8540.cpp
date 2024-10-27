#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

vector<vector<int>> adj;
vector<int> order, lookup;
int a, n, b, k, m;
int ans = INF;

void dfs(int curr, int cnt, int idx, vector<bool>& chk) {
  if (curr > a+n && idx == k+1) {
    ans = min(ans, cnt);
    return;
  }

  for (auto next : adj[curr]) {
    if (a < next && next <= a + n) {
      if (lookup[next] > idx) continue;
      if (chk[next]) continue;
      if (lookup[next] == idx) {
        vector<bool> chk2(a+b+n+1, false);
        dfs(next, cnt+1, idx+1, chk2);
      } else {
        chk[next] = true;
        dfs(next, cnt+1, idx, chk);
        chk[next] = false;
      }
    } else if (a + n < next) {
      if (idx == k+1) dfs(next, cnt, idx, chk);
    }
  }
}

int main() {
  scanf("%d%d%d%d%d",&a,&n,&b,&k,&m);
  adj.resize(a+n+b+1);
  lookup.resize(a+n+b+1);
  order.push_back(0);
  for (int i=0;i<k;i++) {
    int x;
    scanf("%d",&x);
    order.push_back(x);
    lookup[x] = i+1;
  }
  for (int i=0;i<m;i++) {
    int u, v;
    scanf("%d%d",&u,&v);
    if (u > v) swap(u, v);
    if (u <= a+n && v > a) adj[u].push_back(v);
    if (v <= a+n && u > a) adj[v].push_back(u);
  }

  for (int i = 1; i <= a; i++) {
    vector<bool> chk(a+b+n+1, false);
    dfs(i, 0, 1, chk);
  }
  printf("%d\n", ans >= INF ? -1 : ans);
}
