#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, depth, chk, ch[505], sz, idx;
vector<int> ans;
bool flag = false;

int f(int u) {
  if (chk[u]) return depth[u]; 
  chk[u] = 1;
  int mx = 0;
  for (int i = a[u]+1; i <= n; i++)
    if (u < idx[i]) {
      int v = idx[i];
      int vd = f(v);
      if (mx == vd) {
        ch[u].push_back(v);
        sz[u] += sz[v];
      } else if (mx < vd) {
        mx = vd;
        ch[u].clear();
        ch[u].push_back(v);
        sz[u] = sz[v];
      }
    }
  if (sz[u] == 0) sz[u] = 1;
  return depth[u] = mx + 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>k;
  a.resize(n+1); depth.resize(n+1); chk.resize(n+1); sz.resize(n+1), idx.resize(n+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    idx[a[i]] = i;
  }
  f(0);
  if (sz[0] < k) {
    cout<<"-1\n";
    return 0;
  }
  int u = 0;
  while (k && ch[u].size()) {
    int sum = 0;
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
