#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, i;
    int a, b, mn = 1000000004;
    scanf("%d %d", &n, &a);
    for(i=1 ; i<n; i++) scanf("%d", &b), mn = (mn < b) ? mn : b;
    if (mn >= a) printf("Bob\n");
    else printf("Alice\n");
  }
}