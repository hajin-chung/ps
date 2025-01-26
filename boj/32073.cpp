#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; string t, s; cin>>n>>t;
  bool flag = false, flag2 = true;
  int cnt = 0, ocnt = 0, zcnt = 0;
  for (int i = 0; i < (int)t.size(); i++) {
    if (t[i] == '0') zcnt++;
    if (t[i] == '1') flag = true;
    if (flag) {
      s.push_back(t[i]);
      if (t[i] == '0') flag2 = false;
      if (flag2 && t[i] == '1') cnt++;
      if (!flag2 && t[i] == '0') ocnt++;
    }
  }
  if (s.size() == 0) cout<<"0\n";
  else if (cnt == 0) cout<<"0\n";
  else if (ocnt == 0 && zcnt == 0) {
    for (int i = 0; i < (int)s.size()-1; i++) cout<<s[i];
    cout<<"0\n";
  } else if (ocnt == 0 && zcnt != 0) {
    cout<<s<<"\n";
  }else {
    int st = max(0, cnt-ocnt);
    for (int i = 0; i < (int)s.size(); i++) {
      int j = i-st-cnt;
      if (i < cnt) cout<<s[i];
      else cout<<(s[i]!=s[j]);
    }
    cout<<"\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) solve();
}
