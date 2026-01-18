#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
const ll MOD = 998244353;
const int N = 2e5;
const int K = 6;
vector<int> primes;
int ww[N+1];

ll mpow(ll x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  ll p = mpow(x, n/2);
  if (n%2==0) return p*p%MOD;
  else return (p*p%MOD)*x%MOD;
}

ll f() {
  int n, k; cin>>n>>k;
  vector<int> a(n); for (auto &x: a) cin>>x;
  const int mx = *max_element(all(a));
  vector<vector<ll>> cnt(mx+1, vector<ll>(K+1));

  for (auto x: a)
    cnt[x][ww[x]]++;
  for (int k = 0; k <= K; k++)
    for (int i = 1; i <= mx; i++)
      for (int j = 2*i; j <= mx; j+=i)
        cnt[i][k] += cnt[j][k];

  vector<vector<ll>> dp(mx+1, vector<ll>(2*K+1));
  for (int g = 1; g <= mx; g++)
    for (int l1 = 0; l1 <= K; l1++)
      for (int l2 = l1; l2 <= K; l2++) {
        if (l1 == l2) dp[g][l1+l2] += cnt[g][l1]*(cnt[g][l1]-1)/2;
        else dp[g][l1+l2] += cnt[g][l1]*cnt[g][l2];
      }

  for (int l = 0; l <= 2*K; l++)
    for (int g = mx; g >= 1; g--)
      for (int m = 2*g; m <= mx; m+=g)
        dp[g][l] -= dp[m][l];

  ll ans = 0;
  for (int l = 0; l <= 2*K; l++)
    for (int g = 1; g <= mx; g++)
      ans = (ans + mpow(l-ww[g], k)*(dp[g][l]%MOD)%MOD)%MOD;

  return ans;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  vector<bool> chk(N+5, 1);
  chk[1] = 0;
  for (int i = 2; i*i <= N; i++) {
    if (!chk[i]) continue;
    for (int j = i*i; j <= N; j+=i) chk[j] = 0;
  }
  for (int i = 2; i <= N; i++)
    if (chk[i])
      primes.push_back(i);
  for (auto p : primes) {
    for (int i = p; i <= N; i+=p)
      ww[i]++;
  }

  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}
