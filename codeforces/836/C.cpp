#include <stdio.h>
#include <math.h>

int flag[200005], ans[200005];

int main() {
  int t, n, x, i, j;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &x);

    for(i=1; i<=n; i++) flag[i] = ans[i] = 0;
    flag[x] = 1;
    flag[1] = 1;
    ans[1] = x;
    ans[n] = 1;
    int p = 0;
    for(i=n-1; i>=2; i--) {
      int tp = 0;
      for(j=(int)floor(n/i)*i; j>=i; j-=i) 
        if (flag[j] == 0) {
          tp = 1;
          ans[i] = j;
          flag[j] = 1;
          break;
        }
      if (tp == 0) p = 1;
    }
    if (p == 1) {
      printf("-1");
    } else {
      for(i=1; i<=n; i++) printf("%d ", ans[i]);
    }
    printf("\n");
  }
}