#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> t3i;
typedef pair<int, int> pii;

vector<pii> adj;
t3i dp[100005][30];
int chk[100005], depth[100005];

void dfs(int curr, int lev) {
  chk[curr] = 1; 
  depth[curr] = lev;
  for (auto [next, w] : adj[curr])
    if (!chk[next]) {
      dp[next][0] = {curr, w, w};
      make(next, lev+1);
    }
}

int lca(int a, int b) {
  
}

void query() {

}
