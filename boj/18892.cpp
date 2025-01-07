#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, k;
vector<ll> a, depth, chk, ch[505], sz;
vector<ll> ans;
bool flag = false;

ll f(int u) {
  if (chk[u]) return depth[u]; 
  chk[u] = 1;
  ll mx = 0;
  for (int i = u+1; i <= n; i++)
    if (a[i] > a[u]) {
      ll vd = f(i);
      if (mx == vd) {
        ch[u].push_back(i);
        sz[u] += sz[i];
      } else if (mx < vd) {
        mx = vd;
        ch[u].clear();
        ch[u].push_back(i);
        sz[u] = sz[i];
      }
    }
  if (sz[u] == 0) sz[u] = 1;
  return depth[u] = mx + 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  a.resize(n+1); depth.resize(n+1); chk.resize(n+1); sz.resize(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  f(0);
  for (int i = 0; i <= n; i++)
    sort(ch[i].begin(), ch[i].end(), [&](int u, int v) { return a[u] < a[v]; });
  int u = 0;
  while (k && ch[u].size()) {
    if (sz[u] < k) {
      cout<<"-1\n";
      return 0;
    }
    ll sum = 0;
    for (auto v : ch[u]) {
      if (sz[v] + sum >= k) {
        ans.push_back(v);
        k -= sum;
        u = v;
        break;
      }
      sum += sz[v];
    }
  }
  for (auto ai : ans) cout<<a[ai]<<" ";
  cout<<"\n";
}
