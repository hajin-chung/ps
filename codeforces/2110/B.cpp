#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  string s; cin>>s;
  int cnt = 0, zcnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') cnt++;
    else if (s[i] == ')') cnt--;
    if (cnt == 0) zcnt++;
  }
  if (zcnt > 1) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
