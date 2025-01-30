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
    sort(all(a));
    reverse(all(a));
    while (a.size() && a.back() == 0) a.pop_back();
    ans ^= a[0];
    for (auto &x : a)
      x &= ~ans; 
  }
  cout<<ans<<"\n";
}
