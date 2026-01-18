#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 5000000;
const int K = 50;
const int MAX = 100000;
ll bit[K+1][MAX+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  auto update = [&](int k, int i, ll v) {
    for (; i <= MAX; i+=-i&i) bit[k][i] = (bit[k][i] + v)%MOD; };
  auto query = [&](int k, int i) {
    ll ret = 0;
    for (; i > 0; i -= i&-i) ret = (ret+bit[k][i])%MOD;
    return ret;
  };
  for (int i = 0; i < n; i++) {
    ll x; cin>>x;
    update(1, x, 1);
    for (int j = 2; j <= k; j++)
      update(j, x, query(j-1, x-1));
  }
  cout<<query(k, MAX)<<"\n";
}
