#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int mx, n; cin>>mx>>n;
  vector<int> d(mx+1, INF);
  queue<int> q;
  while (n--) {
    int s; cin>>s;
    d[s] = 0;
    q.push(s);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < 20; i++) {
      int v = u^(1<<i);
      if (v <= mx && d[v] > d[u]+1) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
  }
  cout<<*max_element(d.begin(), d.begin()+mx+1)<<"\n";
}
