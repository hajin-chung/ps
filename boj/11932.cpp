#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int;

int n, m, cnt = 0;
vector<int> w, traverse, lookup;
vector<bool> chk;
vector<vector<int>> e;
vector<vector<int>> tree;

void dfs(int curr = 1) {
  lookup[curr] = traverse.size();
  traverse.push_back(curr);
  for (auto next : e[curr])
    if (!chk[next]) {
      chk[next] = true;
      dfs(next);
      traverse.push_back(curr);
    }
}

void init(int node, int l, int r) {
  if (l == r) {
    tree[node].push_back(w[traverse[l]]); 
    return;
  }

  int mid = (l+r)>>1;
  init(node*2, l, mid);
  init(node*2+1, mid+1, r);
  merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

// number of elements smaller or equal to v
int query(int node, int l, int r, int ql, int qr, int v) {
  if (r < ql || qr < l) return 0;
  if (l <= ql && qr <= r) {
    auto it = lower_bound(all(tree[node]), v);
    return it - tree[node].begin();
  }

  int mid = (l+r) >> 1;
  return query(node*2, l, mid, ql, qr, v) + query(node*2+1, mid+1, r, ql, qr, v);
}

int query(int ql, int qr, int k) {
  int l = 0, r = INT_MAX, mid;
  while (l < r) {
    mid = (l+r)>>1;
    int cnt = query(1, 1, traverse.size()-1, l, r, mid);
    if (k <= cnt) r = mid;
    else l = mid+1;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m; 
  w.resize(n+1); e.resize(n+1); chk.resize(n+1); lookup.resize(n+1);
  tree.resize(8*n+5);
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v); 
    e[v].push_back(u); 
  }
  chk[1] = true;
  traverse.push_back(0);
  dfs();
  init(1, 1, traverse.size()-1);

  for (int i = 0; i < m; i++) {
    int ql, qr, k;
    cin >> ql >> qr >> k;
    if (lookup[ql] > lookup[qr]) swap(ql, qr);
    cout << query(lookup[ql], lookup[qr], k) << "\n";
  }
}
