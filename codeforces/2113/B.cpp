#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int w, h, a, b; cin>>w>>h>>a>>b;
  int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
  if (x1 != x2 && (x1-x2)%a == 0) cout<<"YES\n";
  else if (y1 != y2 && (y1-y2)%b == 0) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
