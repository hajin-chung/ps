#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  string a, b; cin>>a>>b;
  int aecnt = 0, aocnt = 0, becnt = 0, bocnt = 0;
  for (int i = 0; i < n; i++) {
    if (i%2) aocnt += a[i] == '0';
    else aecnt += a[i] == '0';
  }
  for (int i = 0; i < n; i++) {
    if (i%2) bocnt += b[i] == '0';
    else becnt += b[i] == '0';
  }
  if (aecnt + bocnt >= (n+1)/2 && aocnt + becnt >= (n)/2) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
