#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<ll> a(n);
  multiset<ll> ms;
  for (int i = 0; i < n*n; i++) {
    ll x; cin>>x; ms.insert(x);
  }
  for (auto it = ms.begin(); it != ms.end();) {
    if (ms.count(*it)%2 == 0) {
    }
  }
}
