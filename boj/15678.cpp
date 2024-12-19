#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d; cin>>n>>d;
  vector<int> a(n), dp(n); 
  for (auto &ai : a) cin>>ai;
  int ans = INT_MIN;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    while (!pq.empty() && i - pq.top().second > d) pq.pop();
    if (!pq.empty() && pq.top().first > 0) dp[i] = a[i] + pq.top().first;
    else dp[i] = a[i];
    ans = max(ans, dp[i]);
    pq.push({dp[i], i});
  }
  cout<<ans<<"\n";
}
