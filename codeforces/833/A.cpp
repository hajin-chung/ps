#include <stdio.h>

int main() {
  int t, x;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &x);
    x += x%2;
    printf("%d\n", x/2);
  }
}