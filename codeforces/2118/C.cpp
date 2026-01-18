#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef int64_t ll;

void f() {
  int n; ll k; cin>>n>>k;
  vector<ll> a(n); for (auto &x: a) cin>>x;
  for (ll bit = 1LL; k >= bit ; bit<<=1LL) {
    for (auto &x : a) {
      if ((x & bit) == 0 && k >= bit) {
        k -= bit;
        x += bit;
      }
    }
  }
  int cnt = 0;
  for (auto &x : a) {
    while (x) {
      cnt+=(x&1);
      x >>=1;
    }
  }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
