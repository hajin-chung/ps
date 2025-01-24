#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
struct E { int u, v; ll w; };
const int INF = 1e9;
vector<E> edges;
vector<ll> d;

bool relax() {
  bool ret = false;
  for (auto [u, v, w] : edges)
    if (d[v] > d[u]+w) {
      ret = true;
      d[v] = d[u]+w;
    }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, ml, md; cin>>n>>ml>>md;
  d.resize(n+1, INF);
  for (int i = 0; i < ml; i++) {
    int u, v; ll w; cin>>u>>v>>w; 
    if (u > v) swap(u, v);
    edges.push_back({u, v, w});
  }
  for (int i = 0; i < md; i++) {
    int u, v; ll w; cin>>u>>v>>w; 
    if (u > v) swap(u, v);
    edges.push_back({v, u, -w});
  }
  d[1] = 0;
  for (int i = 0; i < n; i++) relax();
  if (relax()) cout<<"-2\n";
  else if (d[n] >= INF)  cout<<"-1\n";
  else cout<<d[n]<<"\n";
}
