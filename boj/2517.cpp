#include <bits/stdc++.h>
#include <iterator>
#define all(x) (x).begin(), (x).end()
#define N 500000
using namespace std;

int n;
int a[N];
vector<int> tree[4*N+1];

void init(int node, int l, int r) {
  if (l == r) {
    tree[node].push_back(a[l]);
    return;
  }
  int m = (l+r)>>1;
  init(node*2, l, m);
  init(node*2+1, m+1, r);
  merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

int query(int node, int l, int r, int ql, int qr, int k) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) 
    return tree[node].end() - upper_bound(all(tree[node]), k);
  int m = (l+r)>>1;
  return query(node*2, l, m, ql, qr, k) + query(node*2+1, m+1, r, ql, qr, k);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++) cin>>a[i];
  init(1, 0, n-1);
  for (int i = 0; i < n; i++) 
    cout << query(1, 0, n-1, 0, i-1, a[i])+1 << "\n";
}
