#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int INF = 1e7;
const int MAX = 1e6;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int dist(pii u, pii v) { return abs(u.fi-v.fi)+abs(u.se-v.se); }

void solve() {
  int n; cin>>n;
  vector<pii> a(n); for (auto &p: a) cin>>p.fi>>p.se;
  set<pii> s(all(a));
  map<pii, pii> ans;
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int ty = a[i].fi+dy[j];
      int tx = a[i].se+dx[j];
      if (s.count({ty, tx}) == 0) {
        ans[a[i]] = {ty, tx};
        q.push(a[i]);
        break;
      }
    }
  }
  while (!q.empty()) {
    auto [yy, xx] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int ty = yy+dy[i];
      int tx = xx+dx[i];
      if (!s.count({ty, tx}) || ans.count({ty, tx})) continue;
      ans[{ty, tx}] = ans[{yy, xx}];
      q.push({ty, tx});
    }
  }
  for (int i = 0; i < n; i++) cout<<ans[a[i]].fi<<" "<<ans[a[i]].se<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while(t--) solve();
}
