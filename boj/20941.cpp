#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; string s, ns; cin>>n>>s;
  cout<<s<<"\n";
  for (int i = 1; i < (1<<n); i++) {
    ns = s;
    for (int i = 0; i < n; i++) 
      ns[i] = (s[i]-'0'?'0':'1');
    if (i%2 == 0) {
      int t = n-__builtin_ctz(i);
      ns[t] = s[t];
    }
    cout<<ns<<"\n";
    s = ns;
  }
}
