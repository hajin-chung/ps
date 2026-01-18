#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  int a; cin>>a;
  int mn = a;
  bool flag = 1;
  for (int i = 2; i <= n; i++) {
    cin>>a; 
    int l;
    if (a%2 == 0) l = a/2+1;
    else l = (a+1)/2;
    if (mn < l) flag = 0;
    mn = min(mn, a);
  }
  if (flag) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
