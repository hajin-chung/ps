#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m, cnt = 0, wmn = INT_MAX, wmx = INT_MIN;
vector<int> w;
vector<int> traverse, lookup;
vector<bool> chk;
vector<vector<int>> e;
vector<set<int>> tree;

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
    tree[node].insert(w[traverse[l]]); 
    cout << l << " " << r << ": ";
    for (auto t : tree[node]) cout << t << " ";
    cout << endl;
    return;
  }

  int mid = (l+r)>>1;
  init(node*2, l, mid);
  init(node*2+1, mid+1, r);
  tree[node].insert(all(tree[node*2]));
  tree[node].insert(all(tree[node*2+1]));
  cout << l << " " << r << ": ";
  for (auto t : tree[node]) cout << t << " ";
  cout << endl;
}

// number of elements smaller or equal to v
int query(int node, int l, int r, int ql, int qr, int v) {
  cout << node << " " << l << " " << r << " " << ql << " " << qr << " " << v << endl;
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) {
    auto it = upper_bound(all(tree[node]), v);
    return distance(it, tree[node].begin());
  }

  int mid = (l+r) >> 1;
  int rl = query(node*2, l, mid, ql, qr, v);
  int rr = query(node*2+1, mid+1, r, ql, qr, v);
  return rl+rr;
}

int query(int ql, int qr, int k) {
  int l = wmn, r = wmx, mid;
  cout << "query: " << l << " " << r << endl;
  while (l < r) {
    mid = (l+r)>>1;
    cout << l << " " << r << endl;
    int cnt = query(1, 1, traverse.size()-1, ql, qr, mid);
    cout << "-> " << cnt << endl;
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
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    wmn = min(wmn, w[i]);
    wmx = max(wmx, w[i]);
  }
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v); 
    e[v].push_back(u); 
  }
  chk[1] = true;
  traverse.push_back(0);
  dfs();

  for (auto t : traverse) cout << t << " ";
  cout << endl;
  for (auto t : lookup) cout << t << " ";
  cout << endl;

  init(1, 1, traverse.size()-1);

  for (int i = 0; i < m; i++) {
    int ql, qr, k;
    cin >> ql >> qr >> k;
    if (lookup[ql] > lookup[qr]) swap(ql, qr);
    cout << query(lookup[ql], lookup[qr], k) << "\n";
  }
}
