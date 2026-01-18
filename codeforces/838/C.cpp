#include <bits/stdc++.h>
using namespace std;
 
#define MOD 998244353
 
int64_t powmod(int64_t x, int64_t y, int64_t p) {
  int64_t res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % p;
    y = y / 2;
    x = (x * x) % p;
  }
  return res;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int64_t n, expt = 0;
    cin >> n;
    string s;
    cin >> s;
    int64_t ans = 1;
    for (int i = 1; i < n; i++) {
      expt++;
      if (s[i] != s[i - 1]) {
        expt = 0;
      }
      ans += powmod(2, expt, MOD);
      ans %= MOD;
    }
    cout << ans << endl;
  }
}
