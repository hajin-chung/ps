#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef uint64_t ll;

void f() {
  int n; cin>>n;
  vector<ll> a(n); for (auto &x: a) cin>>x;
  ll sum = 0;
  for (int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1]) sum += (ll)(i+1)*(n-i);
    else sum += (i+1);
  }
  sum += n;
  cout<<sum<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
