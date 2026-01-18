#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const int N = 2e5;
int n;
vector<vector<int>> g;
vector<int> par;

int dfs(int u, int p, int lev) {
  par[u] = p;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, lev+1);
  }
  return lev;
}

void f() {
  g.clear(); par.clear();

  cin>>n;
  g.resize(n+1); par.resize(n+1);
  for (int i = 1; i < n; i++) {
    int u, v; cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bool done = 1;
  for (int i = 1; i <= n; i++)
    if (g[i].size() != 2) 
      done = 0;

  if (done || n == 1 || n == 2 || n == 3) {
    cout<<"-1\n";
    return;
  }

  dfs(1, -1);
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n; j++)
      dp[j][i] = dp[dp[j][i-1]][i-1];
  for (int j = 0; j < 3; j++) {
    for (int i = 1; i <= n; i++)
       cout<<dp[i][j]<<" ";
    cout<<endl;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
