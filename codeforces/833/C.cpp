#include <stdio.h>
#define MIN(a, b) (((a) < (b))?(a):(b))

typedef long long int ll;

int main() {
  int t;
  ll a, b, d, x, rd, rx, cnt;
  scanf("%d", &t); 
  while(t--) {
    scanf("%lld %lld %lld", &a, &b, &d);
    if (MIN(a&(-a), b&(-b)) < d&(-d)) {
      printf("-1");
      continue;
    } 
    cnt = 0;
    rd = d;
    while(rd % 2 == 0) rd = rd >> 1, cnt++;
    x = 1<<30 - 1 - ((d&(-d) - 1);
    printf("%lld\n", x);
  } 
}