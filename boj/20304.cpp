#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int mx, n; cin>>mx>>n;
  vector<int> d(mx+1, INF);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  while (n--) {
    int s; cin>>s;
    d[s] = 0;
    pq.push({d[s], s});
  }
  while (!pq.empty()) {
    auto [dist, u] = pq.top(); pq.pop();
    if (d[u] < dist) continue;
    for (int i = 0; i < 20; i++) {
      int v = u^(1<<i);
      if (v <= mx && d[v] > d[u]+1) {
        d[v] = d[u]+1;
        pq.push({d[v], v});
      }
    }
  }
  cout<<*max_element(d.begin(), d.begin()+mx+1)<<"\n";
}
