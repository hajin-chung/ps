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
const int N = 2e5;
ll a[N+1], b[N+1];

void f() {
  int n; cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i];
  ll ans = 0;
  for (int i = 1; i <= n; i+=2) {
    ll mn = 1<<30;
    if (i-1 >= 1) mn = min(mn, a[i-1]);
    if (i+1 <= n) mn = min(mn, a[i+1]);
    if (a[i] > mn) {
      ans += a[i]-mn;
      a[i] = mn;
    }
  }
  for (int i = 1; i <= n; i++) b[i] = a[i];
  ll fsum = 0, esum = 0;
  for (int i = 2; i <= n-1; i+=2) {
    if (b[i] < b[i-1]+b[i+1]) {
      fsum += b[i+1] + b[i-1] - b[i];
      b[i+1] = b[i] - b[i-1];
    }
  }
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = (n-2)+n%2; i >= 2; i-=2) {
    if (b[i] < b[i-1]+b[i+1]) {
      esum += b[i+1] + b[i-1] - b[i];
      b[i-1] = b[i] - b[i+1];
    }
  }
  cout<<ans+min(fsum, esum)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
