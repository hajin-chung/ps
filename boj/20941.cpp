#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; string s; cin>>n>>s;
  cout<<s<<"\n";
  for (int i = 1; i < (1<<n); i++) {
    for (int i = 0; i < n; i++) 
      s[i] = (s[i]-'0'?'0':'1');
    if (i%2 == 0) {
      int t = n-__builtin_ctz(i);
      s[t] = (s[t]-'0'?'0':'1');
    }
    cout<<s<<"\n";
  }
}
