#include <bits/stdc++.h>
#define INF 1000000000
#define N 500000
#define all(x) (x).begin(), (x).end()
using namespace std;

struct t3i {
  int x, y, z;
};
int n;
vector<t3i> a;
int tree[4*N+1];

bool comp(t3i a, t3i b) {
  if (a.x == b.x) {
    if (a.y == b.y) return a.z < b.z;
    return a.y < b.y;
  }
  return a.x < b.x;
}

int update(int node, int l, int r, int idx, int val) {
  if (idx < l || r < idx) return tree[node];
  if (l == r) return tree[node] = val;
  int m = (l+r)>>1;
  return tree[node] = min(
    update(node*2, l, m, idx, val), 
    update(node*2+1, m+1, r, idx ,val)
  );
}

int query(int node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return INF; 
  if (ql <= l && r <= qr) return tree[node];
  int m = (l+r)>>1;
  return min(
    query(node*2, l, m, ql, qr),
    query(node*2+1, m+1, r, ql, qr)
  );
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  a.resize(n+1);
  int x;
  for (int i = 1; i <= n; i++) {cin>>x; a[x].x = i;}
  for (int i = 1; i <= n; i++) {cin>>x; a[x].y = i;}
  for (int i = 1; i <= n; i++) {cin>>x; a[x].z = i;}
  sort(all(a), comp);
  int ans = 0;
  for (int i = 1; i <= n; i++) update(1, 1, n, i, INF);
  for (int i = 1; i <= n; i++) {
    if (query(1, 1, n, 1, a[i].y) > a[i].z) ans++;
    update(1, 1, n, a[i].y, a[i].z);
  }
  cout << ans << "\n";
}
