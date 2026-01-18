#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 2e5;
vector<pair<int, int>> rel[N+1];
vector<int> g[N+1];
bool ori[N+1]; // L => 0, R => 1
bool chk[N+1];
int ind[N+1], ord[N+1];
int n, m; 

int bg() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (chk[i]) continue;
    q.push(i);
    ori[i] = 0;
    chk[i] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto [v, t] : rel[u]) {
        if (chk[v]) {
          if (ori[v] == ori[u]) return -1;
          if (ori[u]^t) g[v].push_back(u);
          else g[u].push_back(v);
          continue;
        }
        ori[v] = !ori[u];
        chk[v] = 1;
        q.push(v);
      }
    }
  }
  return 0;
}

int tr() {
  for (int u = 1; u <= n; u++)
    for (auto v: g[u])
      ind[v]++;

  queue<int> q;
  for (int u = 1; u <= n; u++)
    if (ind[u] == 0)
      q.push(u);

  int cnt = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ord[u] = cnt++;
    for (auto v : g[u]) {
      ind[v]--;
      if (ind[v] == 0) q.push(v);
    }
  }

  if (cnt != n) return -1;
  return 0;
}

void f() {
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int t, u, v; cin>>t>>u>>v;
    rel[u].push_back({v, t-1});
    rel[v].push_back({u, t-1});
  }
  if (bg() == -1 || tr() == -1) {
    cout<<"NO\n";
  } else {
    cout<<"YES\n";
    for (int i = 1; i <= n; i++) {
      if (ori[i]) cout<<"R ";
      else cout<<"L ";
      cout<<ord[i]<<"\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}
