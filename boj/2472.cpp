#include <bits/stdc++.h>
#include <cstring>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;

const int INF = 1e9;
const int N = 100000;
typedef pair<int, int> pii;
int seg[4*N+5];

void update(int node, int l, int r, int i, int v) {
  if (i < l || r < i) return;
  if (l == r && r == i) {
    seg[node] = min(seg[node], v);
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, i, v);
  update(node*2+1, m+1, r, i, v);
  seg[node] = min(seg[node*2], seg[node*2+1]);
}

int query(int node, int l, int r, int ql, int qr) {
  if (r < ql || qr < l) return INF;
  if (ql <= l && r <= qr) return seg[node];
  int m = (l+r)>>1;
  int rl = query(node*2, l, m, ql, qr);
  int rr = query(node*2+1, m+1, r, ql, qr);
  return min(rl, rr);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  int s[3]; for (int i = 0; i < 3; i++) cin>>s[i];
  vector<vector<pii>> adj(n);
  vector<pii> d[3];
  vector<int> a[3];
  int m; cin>>m;
  while (m--) {
    int u, v, w; cin>>u>>v>>w; u--; v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for (int k = 0; k < 3; k++) {
    s[k]--; d[k].resize(n); a[k].resize(n);
    for (int i = 0; i < n; i++)
      d[k][i] = {INF, i};
  }
  for (int k = 0; k < 3; k++) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[k][s[k]].fi = 0;
    pq.push({0, s[k]});
    while (!pq.empty()) {
      auto [dist, u] = pq.top(); pq.pop();
      if (d[k][u].fi < dist) continue;
      for (auto [v, w] : adj[u])
        if (d[k][v].fi > dist + w) {
          d[k][v].fi = dist+w;
          pq.push({d[k][v].fi, v});
        }
    }
  }
  for (int k = 0; k < 3; k++) {
    sort(all(d[k]));
    for (int i = 0; i < n; i++) {
      int rank = lower_bound(all(d[k]), make_pair(d[k][i].fi, 0))-d[k].begin();
      a[k][d[k][i].se] = rank;
    }
  }
  vector<int> order(n);
  for (int i = 0; i < n; i++) order[i] = i;
  sort(all(order), [&](int u, int v) { 
    if (a[0][u] != a[0][v]) return a[0][u]<a[0][v]; 
    if (a[1][u] != a[1][v]) return a[1][u]<a[1][v];
    return a[2][u]<a[2][v];
  });
  for (int i = 0; i < 4*n+5; i++) seg[i] = INF;
  vector<bool> chk(n);
  int lr = -1; vector<int> ups;
  for (auto i : order) {
    if (lr != a[0][i])
      while (ups.size()) {
        int i = ups.back();
        update(1, 0, n-1, a[1][i], a[2][i]);
        ups.pop_back();
      }
    if (a[1][i] != 0 && query(1, 0, n-1, 0, a[1][i]-1) < a[2][i])
      chk[i] = 1;
    ups.push_back(i);
    lr = a[0][i];
  }
  int q; cin>>q;
  while (q--) {
    int x; cin>>x; x--;
    if (chk[x]) cout<<"NO\n";
    else cout<<"YES\n";
  }
}
