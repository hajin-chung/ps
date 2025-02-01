#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;
const ll INF = 1e12;
ll bit[N+1];
int n;

void update(int i) {
  for (; i <= n; i += i&-i) bit[i]++;
}

ll query(int i) {
  int ret = 0;
  for (; i; i -= i&-i) ret += bit[i];
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  vector<int> a(n+1), b(n+1), c(n+1), to(n+1), idx(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) cin>>b[i];
  ll ans = INF;
  for (int it = 0; it < 2; it++) {
    c = b;
    for (int i = 1; i <= n; i++) idx[a[i]] = i;
    for (int i = 1; i <= n; i++) c[i] = idx[c[i]];
    for (int i = 1; i <= n; i++) to[c[i]] = i;
    for (int i = 1; i <= n; i++) bit[i] = 0;
    ll cnt = 0;
    for (int i = n; i >= 1; i--) {
      cnt += query(to[i]);
      update(to[i]);
    }
    ans = min(ans, cnt);
    for (int i = n; i >= 1; i--) {
      cnt += c[i]*2-n+1;
      ans = min(ans, cnt);
    }
    swap(a, b);
  }
  cout<<ans<<"\n";
}
