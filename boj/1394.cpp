#include <bits/stdc++.h>
#define MOD 900528
using namespace std;

typedef long long int ll;

char pattern[105], secret[1000005];
int table[200];

ll fpow(ll x, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    x = fpow(x, n/2) % MOD;
    return (x * x) % MOD;
  } else {
    ll y = fpow(x, (n-1)/2) % MOD;
    return (x * y * y) % MOD;
  }
}

int main() {
  int i, n, m;
  ll ans = 0;
  scanf("%s\n%s", pattern, secret);
  n = strlen(pattern);
  m = strlen(secret);
  for (i = 0; i < n; i++) if (table[pattern[i]] == 0) table[pattern[i]] = i+1;
  for (i = 0; i < m; i++) {
    ans += table[secret[i]] * fpow(n, m-i-1);
    ans %= MOD;
  }
  printf("%lld\n", ans);
}
