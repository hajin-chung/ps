#include <stdio.h>

typedef long long int ll;

ll abs(ll x) {
  if (x < 0) return -x;
  return x;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    ll s1, s2, x, n;
    s1 = s2 = 0;
    scanf("%lld", &n);
    while(n--) {
      scanf("%lld", &x);
      if (x < 0) s2 += x;
      else s1 += x;
    }
    printf("%lld\n", abs(s1+s2));
  }
}