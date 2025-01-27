#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

void f() {
  string s; cin>>s;
  rope<char> r;
  for (auto c : s) r.push_back(c);
  while (1) {
    string q; cin>>q;
    if (q[0] == 'I') {
      string s; int idx; cin>>s>>idx;
      for (auto c : s) r.insert(idx++, c);
    } else if (q[0] == 'P') {
      int s, e; cin>>s>>e;
      for (int i = s; i <= e; i++) cout<<r[i];
      cout<<"\n";
    } else break;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
