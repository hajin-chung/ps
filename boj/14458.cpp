#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
const ll INF = 1e12;
ll seg[4*N+5];

void update(int node, int l, int r, int i) {
  if (i < l || r < i) return; 
  if (l == r && r == i) {
    seg[node] = 1;
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, i);
  update(node*2+1, m+1, r, i);
  seg[node] = seg[node*2]+seg[node*2+1];
}

ll query(int node, int l, int r, int i) {
  if (r < i) return 0;
  if (i <= l) return seg[node];
  int m = (l+r)>>1;
  ll rl = query(node*2, l, m, i);
  ll rr = query(node*2+1, m+1, r, i);
  return rl + rr;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> a(n+1), b(n+1), c(n+1), idx(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) cin>>b[i];
  ll ans = INF;
  for (int it = 0; it < 2; it++) {
    for (int i = 1; i <= n; i++) idx[a[i]] = i;
    for (int i = 1; i <= n; i++) c[idx[i]] = b[i];
    for (int i = 0; i < 4*n+5; i++) seg[i] = 0;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
      update(1, 1, n, c[i]);
      if (c[i] != n) cnt += query(1, 1, n, c[i]+1);
    }
    ans = min(ans, cnt);
    for (int i = 1; i <= n; i++) {
      cnt = cnt-(c[i]-1)+(n-c[i]);
      ans = min(ans, cnt);
    }
    swap(a, b);
  }
  cout<<ans<<"\n";
}
