#include <stdio.h>
#include <string.h>

int main() {
  char a[1000];
  int flags[60];

  FILE* f = fopen("3.input.txt", "r");
  // FILE* f = fopen("3.input.test.txt", "r");

  int n;
  int sum = 0;

  fscanf(f, "%d", &n);
  for (int i = 0; i<n; i++) {
    for(int j=0; j<1000; j++) a[j] = 0;
    for(int j=0; j<60; j++) flags[j] = 0;
    fscanf(f, "%s", &a);

    int len = strlen(a);
    for(int j=0; j<len/2; j++) {
      int idx = 'a' <= a[j] && a[j] <= 'z' ? a[j] - 'a' + 1: a[j] - 'A' + 1 + 26;
      printf("%d %c\n", idx, a[j]);
      flags[idx] = 1;
    }
    printf("\n");
    for(int j=len/2; j<len; j++) {
      int idx = 'a' <= a[j] && a[j] <= 'z' ? a[j] - 'a' + 1: a[j] - 'A' + 1 + 26;
      if (flags[idx]) {
        printf("%d %c\n", idx, a[j]);
        sum += idx;
        break;
      }
    }
  }
  printf("%d", sum);
}