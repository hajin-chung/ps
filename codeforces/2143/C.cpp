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

void f() {
  int n; cin>>n;
  vector<vector<int>> g(n+1);
  vector<int> ind(n+1);
  for (int i = 1; i < n; i++) {
    int u, v; uint64_t x, y;
    cin>>u>>v>>x>>y;
    if (x > y) {
      g[v].push_back(u);
      ind[u]++;
    } else {
      g[u].push_back(v);
      ind[v]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (ind[i] == 0)
      q.push(i);
  int num = 1;
  vector<int> ans(n+1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ans[u] = num++;
    for (auto v : g[u]) {
      ind[v]--;
      if (ind[v] == 0) q.push(v);
    }
  }
  for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";
  cout<<"\n";

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
