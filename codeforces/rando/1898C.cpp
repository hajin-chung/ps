#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n, m, k; cin>>n>>m>>k;
  if (k < n+m-2 || ((n+m-k)%2+2)%2) {
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
  for (int i = 1; i < m; i++) cout<<(i%2?"R":"B")<<" ";
  cout<<"\n";
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) cout<<"R ";
    cout<<"\n";
  }
  cout<<"B B ";
  for (int i = 3; i <= m; i++) {

    cout<<""
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
