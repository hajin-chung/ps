#include <stdio.h>
#define MOD 998244353

typedef long long int ll;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    ll n;
    scanf("%lld", &n);
    if (n % 2 == 1) printf("0\n");
    else {
      ll ans = 1;
      for(; n>0; n-=2) ans = (ans * n/2) % MOD;
      printf("%d\n", (ans)*(ans) % MOD);
    }
  }
}