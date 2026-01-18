#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef uint64_t ll;

void f() {
  int n; cin>>n;
  vector<ll> a(n); for (auto &x : a) cin>>x;
  sort(all(a));
  ll ans = 0;
  for (int i = n-1; i >= 0; i-=2) {
    if (n-1 < 0) ans += a[i];
    else ans += a[i];
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
