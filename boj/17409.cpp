#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
const ll MOD = 1000000007;
ll dp[4*N+5][11];

void update(int node, int l, int r, int idx, int k, ll v) {
  if (idx < l || r < idx) return;
  if (l == r) {
    dp[node][k] += v;
    dp[node][k] %= MOD;
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, idx, k, v);
  update(node*2+1, m+1, r, idx, k, v);
  dp[node][k] = (dp[node*2][k]+dp[node*2+1][k])%MOD;
}

ll query(int node, int l, int r, int ql, int qr, int k) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return dp[node][k];
  int m = (l+r)>>1;
  ll rl = query(node*2, l, m, ql, qr, k);
  ll rr = query(node*2+1, m+1, r, ql, qr, k);
  return (rl+rr)%MOD;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, a[i], 1, 1);
    for (int j = 2; j <= k; j++)
      update(1, 1, n, a[i], j, query(1, 1, n, 1, a[i]-1, j-1));
  }
  cout<<query(1, 1, n, 1, n, k)<<"\n";
}
