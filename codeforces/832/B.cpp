#include <stdio.h>

int main() {
  int t, i;
  scanf("%d", &t);
  while(t--) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      printf("1\n1 2\n");
      continue;
    }
    if (x % 2 == 1) {
      printf("%d\n", x/2+1);
      for(i=1; i<=x/2+1; i++) {
        printf("%d %d\n", 3*(i-1)+2, 3*x-(3*(i-1)));
      }
    } else {
      printf("%d\n", x/2);
      for(i=1; i<=x/2; i++) {
        printf("%d %d\n", 3*(i-1)+2, 3*x-(3*(i-1)));
      }
    }
  }
}