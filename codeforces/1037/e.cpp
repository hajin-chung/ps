#include <bits/stdc++.h>
using namespace std;

bool f() {
  int n; cin>>n;
  vector<int> p(n), s(n);
  for (int &x : p) cin>>x;
  for (int &x : s) cin>>x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<(f()?"YES":"NO")<<"\n";
}
