#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef long long int ll;
vector<vector<int>> adj;
vector<bool> chk;
vector<ll> d;
ll ans, n;

ll nsum(ll n) { return n*(n-1)/2; }
ll rec(int curr) {
  d[curr] = 1;
  chk[curr] = true;
  for (auto next : adj[curr])
    if (!chk[next]) 
      d[curr] += rec(next);
  ans += nsum(n) - nsum(n-d[curr]);
  return d[curr];
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; adj.resize(n+1); chk.resize(n+1); d.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  rec(1);
  cout<<ans-nsum(n)<<"\n";
}
