#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<pii> a(n), b;
  for (auto &[f, s] : a) cin>>f>>s;
  sort(a.begin(), a.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(a[0].se);
  for (int i = 1; i < n; i++) {
    if (pq.top() <= a[i].fi) pq.pop();
    pq.push(a[i].se);
  }
  cout<<pq.size()<<"\n";
}
