#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, int> pli;
const int N = 100;
const ll INF = 1e18;
ll d[N+5];

void f() {
  int s, e;
  ll x, y;
  cin>>s>>e>>x>>y;

  for (int i = 0; i <= N; i++) d[i] = INF;
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  d[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [w, u] = pq.top(); pq.pop();
    if (d[u] < w) continue;
    
    int v1 = u+1, v2 = u^1;
    if (v1 < 105 && d[v1] > w+x) {
      d[v1] = w+x;
      pq.push({d[v1], v1});
    }
    if (v2 < 105 && d[v2] > w+y) {
      d[v2] = w+y;
      pq.push({d[v2], v2});
    }
  }
  if (d[e] == INF) cout<<-1<<"\n";
  else cout<<d[e]<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) f();
}
