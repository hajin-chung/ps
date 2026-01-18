#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll f() {
  ll n, m; cin>>n>>m;
  ll ans = 0;

  return ans%m;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}
