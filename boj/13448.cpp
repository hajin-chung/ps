#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

typedef long long int ll;
struct P { 
  ll m, p, r; 
  ll f(ll t) { return m-t*p; };
};
ll dp[100005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; ll t; cin>>n>>t;
  vector<P> a(n);
  for (int i = 0; i < n; i++) cin>>a[i].m;
  for (int i = 0; i < n; i++) cin>>a[i].p;
  for (int i = 0; i < n; i++) cin>>a[i].r;
  sort(a.begin(), a.end(), [&](P &a, P &b) { return a.f(t) > b.f(t); });
  for (int i = 0; i < n; i++) {
    for (int j = t; j >= a[i].r; j--)
      dp[j] = max(dp[j], a[i].m-j*a[i].p+dp[j-a[i].r]);
    for (int j = 1; j <= t; j++)
      dp[j] = max(dp[j], dp[j-1]);
  }
  ll ans = 0;
  for (int i = 0; i <= t; i++) ans = max(dp[i], ans);
  cout<<ans<<"\n";
}
