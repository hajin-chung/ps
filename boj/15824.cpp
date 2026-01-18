#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;

vector<ll> a;

ll pw(ll x, int n) {
  if (n == 0) return 1;
  else if (n == 1) return x;
  if (n % 2 == 0) return ((pw(x, n/2) % MOD) * (pw(x, n/2) % MOD)) % MOD;
  else return (x * (pw(x, n-1) % MOD)) % MOD;
}


int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int i, n;
  ll x, ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  for (i = 0; i < n; i++) {
    ans += a[i] * (pw(2, i) + MOD - pw(2, n-i-1)) % MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
}
