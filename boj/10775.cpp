#include <bits/stdc++.h>
using namespace std;

int par[100005];

int find(int u) {
  if (u == par[u]) return u;
  return par[u] = find(par[u]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u < v) par[v] = u;
  else par[u] = v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int g, p, x; cin>>g>>p;
  for (int i = 1; i <= g; i++) par[i] = i;
  int ans = -1;
  for (int i = 0; i < p; i++) {
    cin>>x;
    if (ans == -1) {
      x = find(x);
      if (x == 0) ans = i;
      else merge(x, x-1);
    }
  }
  if (ans == -1) cout<<p<<"\n";
  else cout<<ans<<"\n";
}
