#include <bits/stdc++.h>
#define M 1000
using namespace std;

typedef long double ld;

ld sanitize(ld x) {
  x -= (int)(x/M)*M;
  return x;
}

ld pow(ld x, int n) {
  if (n == 0) return 1.0;
  if (n == 1) return x;
  if (n%2 == 0) {
    ld y = pow(x, n/2);
    return sanitize(y*y);
  } else {
    ld y = pow(x, (n-1)/2);
    return sanitize(x*y*y);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  ld y = 3.0-sqrt(5);
  ld x = 3.0+sqrt(5);
  cout<<fixed<<setprecision(100);
  cout<<x<<"\n"<<(ld)4.0/y<<"\n";
  for (int i = 1; i <= t; i++) {
    int n; cin>>n;
    /*int ans = (int)pow(4, n)/pow(y, n);*/
    int ans = (int)pow(x, n);
    ans %= 1000;
    cout<<"Case #"<<i<<": ";
    if (ans < 100) cout<<"0";
    if (ans < 10) cout<<"0";
    cout<<ans<<"\n";
  }
}
