#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, i;
    ll x,  y, t;
    ll sum = 0, mx = 0;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
      scanf("%lld %lld", &y, &x);
      if (y < x) {
        t = x;
        x = y;
        y = t;
      }
      sum += x;
      mx = (mx < y) ? y : mx;
    }

    sum += mx;
    printf("%lld\n", sum*2);
  }
}