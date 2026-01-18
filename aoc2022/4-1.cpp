#include <stdio.h>

int main() {
  FILE* f = fopen("4.input.txt", "r");

  int cnt = 0;
  int a, b, c, d;
  int n;

  fscanf(f, "%d", &n);
  for(int i=0; i<n; i++) {
    fscanf(f, "%d-%d,%d-%d", &a, &b, &c, &d);
    if (a <= c && d <= b) cnt ++;
    else if (c <= a && b <= d) cnt ++;
  }

  printf("%d", cnt);
}