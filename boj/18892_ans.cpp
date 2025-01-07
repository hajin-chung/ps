#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int INF = 1e9 + 7, N = 500;
ll dp[N+1], cnt[N+1];
int idx[N+1];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  vector<int> a(n+1, 0);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    idx[a[i]] = i;
  }
  for (int i = n; i >= 0; i--) {
    int mx = 0;
    cnt[i] = 1;
    for (int j = i+1; j <= n; j++) {
      if (a[i] > a[j]) continue;
      if (mx < dp[j]) {
        mx = dp[j];
        cnt[i] = 1;
      } else if (mx == dp[j]) {
        cnt[i] += cnt[j];
      }
    }
    dp[i] = mx+1;
  }
  for (int i = 0; i <= n; i++) cout<<dp[i]<<" ";
  cout<<"\n";
  for (int i = 0; i <= n; i++) cout<<cnt[i]<<" ";
  cout<<"\n";
  if (cnt[0] < k) {
    cout<<"-1\n";
    return 0;
  }
  int u = 0;
  vector<int> ans;
  while (k) {
    bool flag = 0;
    ll sum = 0;
    for (int i = u+1; i <= n; i++) {
      if (idx[i] < u || dp[idx[i]] != dp[u]-1) continue;
      if (cnt[idx[i]] + sum >= k) {
        k -= sum;
        u = idx[i];
        ans.push_back(i);
        flag = 1;
        break;
      }
      sum += cnt[idx[i]];
    }
    if (!flag) break;
  }
  for (auto i: ans) cout<<i<<" ";
  cout<<"\n";
}
