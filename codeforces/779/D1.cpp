#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int x, l, r, mx = 0;
    scanf("%d %d", &l, &r);
    for(int i=1; i<=r-l+1; i++) {
      scanf("%d", &x);
      mx = (mx > x) ? mx : x;
    }
    printf("%d\n", mx);
  }
}