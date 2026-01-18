#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, res;
  cin >> n; 
  res = n;

  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= res / i;
    }
  }
  if (n > 1) res -= res / n;
  cout << res << "\n";
}
