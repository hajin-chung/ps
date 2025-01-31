#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;
const int N = 1000000;
int d[N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int mx, n; cin>>mx>>n;
  queue<int> q;
  for (int i = 0; i <= mx; i++) d[i] = INF;
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
  cout<<*max_element(d, d+mx+1)<<"\n";
}
