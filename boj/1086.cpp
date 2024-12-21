#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, k;
ll dp[1<<15][105], a[105];
string s[105];
unordered_map<int, int> ttable;

int tmod(int n) {
  if (ttable.count(n)) return ttable[n];
  int ret = 1;
  while (n--) ret = (ret*10)%k;
  return ttable[n] = ret;
}

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 0; i < n; i++) cin>>s[i];
  cin>>k;
  for (int i= 0; i < n; i++) {
    int m = s[i].size();
    for (int j = 0; j < m; j++)
      a[i] = (a[i]*10+(s[i][j]-'0'))%k;
  }
  dp[0][0] = 1;
  for (int mask = 0; mask < (1<<n); mask++) {
    for (int i = 0; i < n; i++)
      if ((mask & (1<<i)) == 0) {
        int next = mask | (1<<i);
        for (int j = 0; j < k; j++) {
          int r = ((j*tmod(s[i].length()))%k+a[i])%k;
          dp[next][r] += dp[mask][j];
        }
      }
  }
  ll fact = 1, ans = dp[(1<<n)-1][0];
  for (int i = 1; i <= n; i++) fact *= i;
  ll g = gcd(ans, fact);
  cout<<ans/g<<"/"<<fact/g<<"\n";
}
