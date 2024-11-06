#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define N 100000
using namespace std;

int n, m;
int w[N+5];
vector<int> wset;
vector<int> tree[4*N+5];

void init(int node, int l, int r) {
  if (l == r) {
    tree[node].push_back(w[l]);
    return;
  }
  int mid = (l+r)>>1;
  init(node*2, l, mid);
  init(node*2+1, mid+1, r);
  merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

int query(int node, int l, int r, int ql, int qr, int v) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) {
    auto it = upper_bound(all(tree[node]), v);
    return it - tree[node].begin();
  }
  int mid = (l+r)>>1;
  int rl = query(node*2, l, mid, ql, qr, v);
  int rr = query(node*2+1, mid+1, r, ql, qr, v);
  return rl + rr;
}

int query(int ql, int qr, int k) {
  int l = 0, r = n-1;
  while (l < r) {
    int mid = (l+r)>>1;
    int cnt = query(1, 1, n, ql, qr, wset[mid]);
    if (k <= cnt) r = mid;
    else l = mid+1;
  }
  return wset[l];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    wset.push_back(w[i]);
  }
  sort(all(wset));
  init(1, 1, n);
  while (m--) {
    int ql, qr, k;
    cin >> ql >> qr >> k;
    cout << query(ql, qr, k) << "\n";
  }
}
