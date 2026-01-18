#include <stdio.h>

int main() {
  int t;
  int x, i;

  scanf("%d", &t);
  while(t--) {
    scanf("%d", &x);
    if (x%2 == 1) {
      for(i=0; i<x; i++) printf("1 ");
    } else {
      printf("1 3 ");
      for(i=0; i<x-2; i++) printf("2 ");
    }
    printf("\n");
  }
}