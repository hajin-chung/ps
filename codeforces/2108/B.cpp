#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long ll;

ll zz(int n) {
  if (n == 1) return -1;
  if (n%2 == 1) return n+3;
  else return n;
}

void f() {
  ll n, x; cin>>n>>x;
  ll cnt = __builtin_popcount(x);
  if (n <= cnt) { cout<<x<<"\n"; return; }
  if ((n-cnt)%2 == 0) { cout<<x+n-cnt<<"\n"; return; }
  else {
    if (x > 1) cout<<x+n-cnt+1<<"\n";
    else if (x == 1) cout<<n+3<<"\n";
    else {
      if (n == 1) cout<<"-1\n";
      else cout<<n+3<<"\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
