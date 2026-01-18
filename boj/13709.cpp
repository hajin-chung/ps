#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n);
  for (auto &x : a) cin>>x;
  sort(all(a)); reverse(all(a));
  vector<ll> b(61, 0);
  ll ans = 0;
  for (ll x : a) {
    for (int i = 60; i >= 0; i--)
      if ((x>>i)&1) {
        if (!b[i]) {
          b[i] = x;
          break;
        }
        x ^= b[i];
      }
  }
  for (int i = 60; i >= 0; i--)
    if (b[i] && (ans^b[i])>ans)
      ans ^= b[i];
  cout<<ans<<"\n";
}
