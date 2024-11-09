#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 2000000000
using namespace std;

typedef pair<int, int> pii;
int n;
vector<int> sum, mintree, maxtree;

void init(int node, int l, int r) {
  if (l == r) {
    mintree[node] = maxtree[node] = sum[l];
    return;
  }
  int m = (l+r)>>1;
  init(node*2, l, m);
  init(node*2, m+1, r);
  maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
  mintree[node] = min(mintree[node*2], mintree[node*2+1]);
}

pii query(int node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return {INF, -INF};
  if (ql <= l && r <= qr) return {mintree[node], maxtree[node]};
  int m = (l+r)>>1;
  pii rl = query(node*2, l, m, ql, qr);
  pii rr = query(node*2+1, m+1, r, ql, qr);
  return {min(rl.fi, rr.fi), max(rl.se, rr.se)};
}

int main() {
  cin>>n; sum.resize(n+1); mintree.resize(4*n+1); maxtree.resize(4*n+1);
  for (int x, i = 1; i <= n; i++) {
    cin>>x;
    sum[i] = sum[i-1]+x;
  }
  init(1, 1, n);
  int m;
  cin>>m;
  while(m--) {
    int ql, qr;
    cin>>ql>>qr;
    pii res = query(1, 1, n, ql, qr);
    cout<<
  }
}
