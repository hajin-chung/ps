#include <bits/stdc++.h>
#include <iostream>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 2e5;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

vector<int> g[N+1];
int w[N+1], dp[N+1][2], ans, cnt;
ll sum[N+1][2];

void r1(int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = 1;
  sum[u][0] = 1;
  sum[u][1] = g[u].size();
  for (auto v : g[u])
    if (v != p) {
      r1(v, u);
      dp[u][1] += dp[v][0];
      sum[u][1] += sum[v][0];
      dp[u][0] += max(dp[v][0] ,dp[v][1]);
      if (dp[v][0] == dp[v][1]) sum[u][0] += min(sum[v][0], sum[v][1]);
      else sum[u][0] += sum[v][dp[v][0]<dp[v][1]];
    }
}

void r2(int u, int p, int par) {
  w[u] = par ? g[u].size() : 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (par == 1) r2(v, u, 0);
    else {
      if (dp[v][0] == dp[v][1]) r2(v, u, sum[v][0]>sum[v][1]);
      else r2(v, u, dp[v][0]<dp[v][1]);
    }
  }
}

void solve() {
  int n; cin>>n;
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n == 2) {
    cout<<"2 2\n1 1\n";
    return;
  }
  r1(1, -1);
  if (dp[1][0] == dp[1][1]) r2(1, -1, sum[1][0]>sum[1][1]);
  else r2(1, -1, dp[1][0]<dp[1][1]);

  cout<<max(dp[1][0], dp[1][1])<<" ";
  if (dp[1][0] == dp[1][1]) cout<<min(sum[1][0], sum[1][1])<<"\n";
  else cout<<(dp[1][0]>dp[1][1]?sum[1][0]:sum[1][1])<<"\n";
  for (int i = 1; i <= n; i++) cout<<w[i]<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
