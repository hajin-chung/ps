#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
const ll INF = 1e12;
ll bit[N+1];
int n;

void update(int i, ll v) {
  for (; i <= n; i += i&-i) bit[i]+=v;
}

ll query(int i) {
  int ret = 0;
  for (; i; i -= i&-i) ret += bit[i];
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  vector<int> a(n+1), b(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) cin>>b[i];
  ll ans = INF;
  vector<int> idx(n+1);
  for (int i = 1; i <= n; i++) idx[b[i]] = i;
  ll icnt = 0;
  for (int i = n; i >= 1; i--) {
    icnt += query(idx[a[i]]);
    update(idx[a[i]], 1);
  }
  for (int it = 0; it < 2; it++) {
    ll cnt = icnt;
    ans = min(ans, cnt);
    for (int i = 1; i <= n; i++) idx[b[i]] = i;
    for (int i = 1; i <= n; i++) {
      cnt = cnt - (idx[a[i]]-1) + (n-idx[a[i]]);
      ans = min(ans, cnt);
    }
    swap(a, b);
  }
  cout<<ans<<"\n";
}
