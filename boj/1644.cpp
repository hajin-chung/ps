#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> primes;
vector<bool> v;

void eratos(int n) {
  for (int i = 2; i*i <= n; i++)
    if (!v[i]) {
      for (int j = i * i; j <= n; j+=i)
        v[j] = true;
    }
  for (int i = 2; i <= n; i++) if (!v[i]) primes.push_back(i);
}

int main() {
  int i, lo, hi, s, ans = 0;
  scanf("%d", &n);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  v.resize(n+5);
  eratos(n);
  lo = hi = 0;
  s = primes[0];
  while (lo <= hi && hi < primes.size()) {
    if (s == n) ans++;
    if (s > n) {
      if (lo < primes.size()) s -= primes[lo];
      lo++;
    } else {
      hi++;
      if (hi < primes.size()) s += primes[hi];
    }
  }
  printf("%d\n", ans);
}
