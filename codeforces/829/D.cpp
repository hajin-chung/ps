#include <stdio.h>

int count[500005];

int main() {
  int n, x, i, t;
  scanf("%d %d", &n, &x);
  for(i=1 ; i<=n ; i++) {
    scanf("%d", &t);
    count[t]++;
  }
  int mn = 0;
  for(i=1; i<=x;i++) {
    if (count[i] >= i+1) {
      count[i+1] += count[i] / (i+1);
      count[i] %= (i+1);
    }
    if (count[i] != 0) {
      mn = i;
      break;
    }
  }
  if (x <= i) printf("Yes\n");
  else printf("No\n");
}