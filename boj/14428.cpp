#include <bits/stdc++.h>
#define INF 1000000005
using namespace std;

typedef pair<int, int> pii;

vector<pii> d;
int n, m;

pii query(int node, int l, int r, int ql, int qr) {
  if (qr < l || ql > r) return {INF, -1};
  if (ql <= l && r <= qr) return d[node];

  int mid = (l+r)>>1;
  pii ret = {INF, -1};
  ret = min(ret, query(node*2, l, mid, ql, qr));
  ret = min(ret, query(node*2+1, mid+1, r, ql, qr));
  return ret;
}

void update(int node, int l, int r, int idx, int v) {
  if (l == r) {
    d[node] = {v, idx};
  } else {
    int mid = (l+r)>>1;
    if (idx <= mid) update(node*2, l, mid, idx, v);
    else update(node*2+1, mid+1, r, idx, v);
    d[node] = min(d[node*2], d[node*2+1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x, y, z;

  cin >> n;
  d.resize(4*n, {INF, -1});
  for (int i = 1; i <= n; i++) {
    cin >> x;
    update(1, 1, n, i, x);
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    if (x == 1) update(1, 1, n, y, z);
    else cout << query(1, 1, n, y, z).second << "\n";
  }
}
