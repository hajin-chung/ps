#include <bits/stdc++.h>
using namespace std;

void f() {
  int n; cin>>n;
  string s; cin>>s;

  bool c5 = 0, c6 = 0;
  for (int i = 4; i <= s.size(); i++) {
    if (s[i-4] == '2' && s[i-3] == '0' && s[i-2] == '2' && s[i-1] == '5') c5 = 1;
    if (s[i-4] == '2' && s[i-3] == '0' && s[i-2] == '2' && s[i-1] == '6') c6 = 1;
  }
  if (c6 || !c5) cout<<0<<"\n";
  else cout<<1<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
