#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
vector<pii> lr;
vector<int> c;

void f() {
  int n, k; cin>>n>>k;
  lr.resize(0); c.resize(0);
  for (int i = 0; i < n; i++) {
    int ll, rr, cc;
    cin>>ll>>rr>>cc;
    lr.push_back({ll, rr});
    c.push_back(cc);
  }

  set<int> chk;
  queue<int> q;
  q.push(k);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (chk.count(u)) continue;
    chk.insert(u);
    for (int i = 0; i < n; i++)
      if (lr[i].fi <= u && u <= lr[i].se && chk.count(c[i]) == 0)
        q.push(c[i]);
  }
  cout<<*chk.rbegin()<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
