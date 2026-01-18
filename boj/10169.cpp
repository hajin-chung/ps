#include <bits/stdc++.h>
#define N 100000
#define LOG_N 20
#define M 300000
#define MAX 2000000000
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, pii> plp;
struct Edge {
  int idx;
  int u, v;
  ll w;
  Edge(int idx, int u, int v, ll w) : idx(idx), u(u), v(v), w(w) {}
};
int n, m;
ll mst;
vector<Edge> edges;
vector<pil> me[N+1];
int p[N+1], dep[N+1];
int dp[N+1][LOG_N];
ll wdp[N+1][LOG_N];
bool chk[N+1], isme[M+1];

bool comp(Edge a, Edge b) { return a.w < b.w; }

int find(int u) {
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}
void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u < v) p[v] = u;
  else p[u] = v;
}

void dfs(int curr, int lev=0) {
  dep[curr] = lev;
  for (auto [next, w] : me[curr])
    if (!chk[next]) {
      chk[next] = 1;
      dp[next][0] = curr;
      wdp[next][0] = w;
      dfs(next, lev+1);
    }
}

ll query(int u, int v) {
  ll ret = MAX;
  bool log = u ==1 && v == 2;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = LOG_N-1; i >= 0; i--) {
    if (dep[dp[u][i]] >= dep[v]) {
      ret = min(ret, wdp[u][i]);
      u = dp[u][i];
    }
  }
  if (log) cout << "uv: " << u << " " << v << " " << ret << endl;
  if (u == v) return ret;
  for (int i = LOG_N-1; i >= 0; i--) {
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i]; v = dp[v][i];
      ret = min(ret, min(wdp[u][i], wdp[v][i]));
    }
  }
  ret = min(ret, min(wdp[u][0], wdp[v][0]));
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin>>u>>v>>w;
    edges.pb({i, u, v, w});
  }
  auto e = edges;
  sort(all(edges), comp);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (auto [idx, u, v, w] : edges)
    if (find(u) != find(v)) {
      mst += w;
      merge(u, v);
      me[u].pb({v, w});
      me[v].pb({u, w});
      isme[idx] = 1;
    }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < LOG_N; j++)
      wdp[i][j] = MAX;

  dep[0] = -1;
  chk[1] = 1;
  dfs(1, 0);
  for (int i = 1; i < LOG_N; i++)
    for (int j = 1; j <= n; j++) {
      dp[j][i] = dp[dp[j][i-1]][i-1];
      wdp[j][i] = min(wdp[j][i-1], wdp[dp[j][i-1]][i-1]);
    }

  for (int i = 1; i <= n; i++) cout << dep[i] << " ";
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout<<i<<": ";
    for (int j = 0; j < 7; j++)
      cout<<"("<<dp[i][j]<<", "<<wdp[i][j]<<"), ";
    cout<<endl;
  }
  
  cout << mst << endl;
  for (int i = 0; i < m; i++) {
    auto [idx, u, v, w] = e[i];
    cout << "query(" << u << ", "<<v<<") = " << query(u, v) << endl;
    if (isme[idx]) cout<<mst+w-query(u, v)<<"\n";
    else cout<<mst<< "\n";
  } 
}
