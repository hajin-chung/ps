#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 1e9
#define N 1000
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
struct Q { pii s, e; };
int n, q;
int d[N+5][N+5], psum[N+5][N+5], a[N+5][N+5], chk[N+5][N+5];
pii p[N+5][N+5];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
vector<Q> queries;

bool comp(pip a, pip b) {
  return a.fi > b.fi;
}

pii find(pii a) {
  if (a == p[a.fi][a.se]) return a;
  else return p[a.fi][a.se] = find(p[a.fi][a.se]);
}

void merge(pii a, pii b) {
  a = find(a), b = find(b);
  if (a < b) p[b.fi][b.se] = a;
  else p[a.fi][a.se] = b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; 
  for (int i = 1; i <= n; i++) {
    string tmp;
    cin>>tmp;
    for (int j = 1; j <= n; j++) {
      if (tmp[j-1] == '#') 
        a[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      psum[i][j] = a[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 1) continue;
      int l = 0, r = min(min(i-1, n-i), min(j-1, n-j))+1;
      while (l < r) {
        int m = (l+r)>>1; 
        int sum = psum[i+m][j+m] - psum[i-m-1][j+m] - psum[i+m][j-m-1] + psum[i-m-1][j-m-1];
        if (sum == 0) l = m+1;
        else r = m;
      }
      d[i][j] = l*2-1;
    }
  vector<pii> e[N+1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      e[d[i][j]].push_back({i, j});
  cin>>q; queries.resize(q);
  for (auto &[s, e] : queries) cin>>s.fi>>s.se>>e.fi>>e.se; 
  vector<int> lo(q, 0), hi(q, n);
  while (true) {
    bool flag = true;
    vector<int> g[N+1];
    for (int i = 0; i < q; i++)
      if (lo[i] < hi[i]) {
        flag = false;
        g[(lo[i]+hi[i])>>1].push_back(i);
      }
    /*cout <<"\n";*/
    /*for (int i = 0; i < edges.size(); i++)*/
    /*  if (g[i].size()) {*/
    /*    cout << i << ": ";*/
    /*    for (auto idx : g[i])*/
    /*      cout << idx << " ";*/
    /*    cout<<"\n";*/
    /*  }*/
    if (flag) break;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        p[i][j] = {i, j};
        chk[i][j] = 0;
      }
    for (int dist = n; dist >= 0; dist--) {
      for (auto xy : e[dist]) {
        auto [yy, xx] = xy;
        chk[yy][xx] = 1;
        for (int i = 0; i < 4; i++) {
          int ty = yy + dy[i];
          int tx = xx + dx[i];
          if (ty < 1 || ty > n || tx < 1 || tx > n) continue;
          if (chk[ty][tx]) merge(xy, {ty, tx});
        }
      }
      for (auto idx : g[dist]) {
        if (find(queries[idx].s) == find(queries[idx].e))
          lo[idx] = dist+1;
        else
          hi[idx] = dist;
      }
    }
  }
  for (auto ans : hi) cout << ans-1 << "\n";
}
