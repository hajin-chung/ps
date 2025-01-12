#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int INF = 1e9;
vector<int> g[N];
int d[N], chk[N];
int n, k, s, ans;
bool stop = 0;

int f(int u, int p) {
  if (stop) return -1;
  int h = 0;
  for (auto v : g[u]) 
    if (v != p && !chk[v] && !stop)
      h = max(h, f(v, u));
  if (h == k) {
    s = u;
    ans++;
    stop = 1;
  }
  return h + 1;
}

void h(int u, int p, int lev) {
  if (lev == k+1) return;
  chk[u] = 1;
  for (auto v : g[u])
    h(v, u, lev+1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  memset(d, INF, sizeof(d));
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (!chk[i]) {
      if (f(i, -1) < k) {
        ans++;
        h(i, -1, 0); 
      } else h(s, -1, 0);
    }
  cout<<ans<<"\n";
}
