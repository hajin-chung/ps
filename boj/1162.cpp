#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 10000000000L
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, pii> plp;
vector<vector<pil>> adj;
vector<vector<ll>> dp;
priority_queue<plp, vector<plp>, greater<plp>> pq;
int n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  adj.resize(n+1);
  dp.resize(n+1, vector<ll>(k+1, INF));
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    scanf("%d %d %lld", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dp[1][0] = 0;
  pq.push({0, {1, 0}});
  while (!pq.empty()) {
    auto [d, p] = pq.top(); pq.pop();
    auto [curr, ck] = p;
    if (d > dp[curr][ck]) continue;
    for (auto [next, w] : adj[curr]) {
      if (ck < k && dp[next][ck+1] > dp[curr][ck]) {
        dp[next][ck+1] = dp[curr][ck];
        pq.push({dp[next][ck+1], {next, ck+1}});
      }
      if (dp[next][ck] > d + w) {
        dp[next][ck] = d + w;
        pq.push({dp[next][ck], {next, ck}});
      }
    }
  }
  ll mn = INF;
  for (int i = 0; i <= k; i++) mn = min(mn, dp[n][i]);
  printf("%lld\n", mn);
}
