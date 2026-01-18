#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef int64_t ll;
const int N = 5e5;
ll a[N+1];
vector<int> g[N+1];

ll dfs(int u, int p) {
  ll ret = 0, sum = 0, mx = 0;
  int cnt = 0;
  for (auto v : g[u])
    if (v != p) {
      ll res = dfs(v, u);
      cout<<v<<" "<<res<<endl;
      mx = max(mx, res);
      if (res > 0) {
        sum += res;
        cnt++;
      }
    }
  if (cnt == 1) return max({(ll)0, sum, a[u]});
  return max({(ll)0, a[u], sum+a[u], mx});
}

void f() {
  int n; cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int u = 0;
  for (int i = 1; i <= n; i++)
    if (g[i].size() == 1)
      u = i;
  ll ret = dfs(u, -1);
  cout<<u<<" "<<ret<<endl;
  cout<<u<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
