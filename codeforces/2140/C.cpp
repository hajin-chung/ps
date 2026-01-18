#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

typedef int64_t ll;

void f() {
  int n; cin>>n;
  vector<ll> a(n+1); 
  for (int i = 1; i <= n; i++) cin>>a[i];
  ll f = 0;
  for (int i = 1; i <= n; i++) f += (i%2 == 1) ? a[i] : -a[i];
  set<ll> eo, oe;
  for (int i = 2; i <= n; i+=2)
    eo.insert(2*a[i]+i);
  ll mx = -(1LL<<60);
  for (int i = 1; i<= n; i+=2) {
    if (!eo.empty()) {
      ll eomx = *eo.rbegin();
      mx = max(mx, eomx - (2*a[i]+i));
    }
    if (!oe.empty()) {
      ll oemx = *oe.rbegin();
      mx = max(mx, oemx - (2*a[i]-i));
    }
    if (i+1 <= n) {
      eo.erase(2*a[i+1]+i+1);
      oe.insert(2*a[i+1]-i-1);
    }
  }
  f = max({
    f, f+mx, f+(n-(1-n%2))-1, f+(n-n%2)-2
  });
  cout<<f<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
