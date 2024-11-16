#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
int n, m;
ll k;
vector<pii> edges;
ll cnt[101010];
int p[101010];

void end(int x) {
  cout<<x<<"\n";
  exit(0);
}

int find(int u) {
  if (u == p[u]) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v) {
  u = find(u); v = find(v); 
  if (u < v) p[v] = u;
  else p[u] = v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin>>u>>v;
    edges.push_back({u, v});
  }
  if (m > n) end(0);

  for (int i = 1; i <= n; i++) p[i] = i;
  for (auto [u, v] : edges) {
    if (find(u) == find(v)) end(0);
    merge(u, v);
  }

  for (int i = 1; i <= n; i++) cnt[find(i)]++;

  ll ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) continue;
    if (sum != 0) ans += sum * cnt[i];
    sum += cnt[i];
    if (ans > k) end(-1);
  }
  cout<<ans<<"\n";
}
