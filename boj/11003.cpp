#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l; cin>>n>>l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin>>a[i];
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({a[i], i});
    if (i >= l)
      while (!pq.empty() && pq.top().second <= i-l) 
        pq.pop();
    cout<<pq.top().first<<" ";
  }
  cout<<"\n";
}
