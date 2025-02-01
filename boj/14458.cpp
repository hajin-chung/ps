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
  vector<int> a(n+1), idx(n+1);
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    idx[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    a[idx[x]] = i;
  }
  ll cnt = 0, ans;
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, a[i]);
    if (a[i] != n) cnt += query(1, 1, n, a[i]+1);
  }
  ans = cnt;
  for (int i = 1; i <= n; i++) {
    cnt = cnt-(a[i]-1)+(n-a[i]);
    ans = min(ans, cnt);
  }
  cout<<ans<<"\n";
}
