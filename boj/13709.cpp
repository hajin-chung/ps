#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n);
  for (auto &x : a) cin>>x;
  ll ans = 0;
  for (int i = 60; i >= 0; i--) {
    ll mx = -1;
    for (int j = 0; j < n; j++)
      if ((a[j]&(1ll<<i)) && a[j] > mx)
        mx = a[j];
    if (mx == -1) continue;
    ans ^= mx;
    for (auto &x : a)
      if (x&(1ll<<i))
        x ^= mx;
  }
  cout<<ans<<"\n";
}
