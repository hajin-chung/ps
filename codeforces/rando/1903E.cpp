#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int pp(pair<int, int> p) {
  return (p.fi+p.se)%2;
}

void f() {
  int n; cin>>n;
  pair<int, int> s; cin>>s.fi>>s.se;
  set<int> ps[2];
  for (int i = 1; i <= n; i++) {
    int y, x; cin>>y>>x;
    if (pp(s) == pp({y, x})) ps[0].insert(i);
    else ps[1].insert(i);
  }
  int tp = ps[0].size() >= ps[1].size();
  if (tp) cout<<"First\n";
  else cout<<"Second\n";
  cout.flush();
  for (int i = 1; i <= n; i++) {
    if (i%2 == tp) {
      int g = tp;
      if (ps[tp].size() == 0) g = 1-tp;

      auto it = ps[g].begin();
      cout<<*it<<"\n";
      cout.flush();
      ps[g].erase(it);
    } else {
      int idx; cin>>idx;
      if (ps[0].count(idx)) ps[0].erase(idx); 
      if (ps[1].count(idx)) ps[1].erase(idx);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
