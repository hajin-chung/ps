#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long ll;

void f() {
  int n; cin>>n;
  ll sum = 0, mx = 0;
  int ecnt = 0, ocnt = 0;
  for (int i = 1; i <= n; i++) {
    ll x; cin>>x;
    sum += x;
    mx = max(mx, x);
    if (x%2 == 1) ocnt++;
    else ecnt++;
  } 
  if (ocnt == 0 || ecnt == 0) {
    cout<<mx<<"\n";
  } else {
    cout<<sum-(ocnt-1)<<"\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
