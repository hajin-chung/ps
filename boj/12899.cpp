#include <bits/stdc++.h>
#define N 2000000
using namespace std;

int tree[4*N+5];

void update(int node, int l, int r, int idx, int val) {
  if (l == r) {
    tree[node] += val;
    return;
  }
  int m = (l+r)>>1;
  if (idx <= m) update(node*2, l, m, idx, val);
  else update(node*2+1, m+1, r, idx, val);
  tree[node] = tree[node*2]+tree[node*2+1];
}

int query(int node, int l, int r, int idx) {
  if (l == r) return l;
  int m = (l+r)>>1;
  if (idx <= tree[node*2]) return query(node*2, l, m, idx);
  else return query(node*2+1, m+1, r, idx-tree[node*2]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int q, x;
    cin>>q>>x;
    if (q == 1) update(1, 1, N, x, 1);
    else {
      int ans = query(1, 1, N, x);
      cout << query(1, 1, N, x) << "\n";
      update(1, 1, N, ans, -1);
    }
  }
}
