#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 2e5;
pair<int, int> p[N+1], q[N+1];

int diry(char s) {
  if (s == 'U') return 1;
  else if (s == 'D') return -1;
  return 0;
}

int dirx(char s) {
  if (s == 'R') return 1;
  else if (s == 'L') return -1;
  return 0;
}

void f() {
  int n, qn; cin>>n>>qn;
  string s; cin>>s;
  for (int i = 1; i <= n; i++)
    p[i] = {p[i-1].fi+dirx(s[i-1]), p[i-1].se+diry(s[i-1])};
  for (int i = n; i >= 1; i--)
    q[i] = {q[i+1].fi-dirx(s[i-1]), q[i+1].se-diry(s[i-1])};
  map<pair<int, int>, vector<int>> ps, qs;
  ps[{0, 0}].push_back(0);
  for (int i = 1; i <= n; i++) {
    ps[p[i]].push_back(i);
    qs[q[i]].push_back(i);
  }

  while (qn--) {
    int xx, yy, ll, rr; cin>>xx>>yy>>ll>>rr;
    vector<int> &pv = ps[{xx, yy}];
    if (!pv.empty() && (*pv.begin() < ll || *pv.rbegin() > rr)) {
      cout<<"YES\n";
      continue;
    }
    pair<int, int> qq = {-xx+p[ll-1].fi+q[rr+1].fi, -yy+p[ll-1].se+q[rr+1].se};
    vector<int> &qv = qs[qq];
    auto qit = lower_bound(all(qv), ll);
    if (qit != qv.end() && *qit <= rr) {
      cout<<"YES\n";
      continue;
    }
    cout<<"NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}

  // for (int i = 1; i <= n; i++) cout<<"("<<p[i].fi<<", "<<p[i].se<<"), ";
  // cout<<endl;
  // for (int i = 1; i <= n; i++) cout<<"("<<q[i].fi<<", "<<q[i].se<<"), ";
  // cout<<endl;
  //
  // cout<<"ps\n";
  // for (auto [pi, pv] : ps) {
  //   cout<<pi.fi<<", "<<pi.se<<": ";
  //   for (auto v : pv) cout<<v<<", ";
  //   cout<<endl;
  // }
  // cout<<"qs\n";
  // for (auto [qi, qv] : qs) {
  //   cout<<qi.fi<<", "<<qi.se<<": ";
  //   for (auto v : qv) cout<<v<<", ";
  //   cout<<endl;
  // }
  //
