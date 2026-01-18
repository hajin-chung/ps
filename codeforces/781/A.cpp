#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);

    if (n % 4 == 0) {
      printf("%d %d %d %d\n", n/4, n/4, n/4, n/4);
    } else if (n%4 == 1) {
      printf("1 %d 1 1\n", n-3);
    } else if (n % 4 == 2) {
      printf("%d %d 1 1\n", (n-2)/2-1, (n-2)/2+1);
    } else {
      printf("2 %d 2 1\n", (n-5));
    }
  }
}