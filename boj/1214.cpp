#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll d, p, q;

// d <= ap + bq find min ap+bq
// [1] d <= ap + bq
// [2] d <= xpq + a'p + b'q (a' < q && b' < p)
// [3] d-xpq = d' <= a'p + b'q 
// => pq <= d = a'p + b'q <= 2pq
// 0 <= a' <= q

int main() {
  scanf("%lld%lld%lld", &d, &p, &q);
  ll ret = d / (p * q) * (p * q);
  if (ret > 0) ret -= p*q;
  d -= ret;
  if (p < q) swap(p, q);
  ll ans = 1000000000;
  for (ll i = 0; i * p <= d + p; i++) {
    ans = min(ans, p*i+((d-p*i+q-1)/q)*q);
  }
  printf("%lld\n", ret+ans);
}
