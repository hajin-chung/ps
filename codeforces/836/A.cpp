#include <stdio.h>
#include <string.h>

char a[105];

int main() {
  int t;
  int i, len;

  scanf("%d", &t);
  while(t--) {
    for(i=0; i<=104; i++) a[i] = 0;
    scanf("%s", &a[1]);
    len = strlen(&a[1]);
    for(i=1; i<=len; i++) printf("%c", a[i]);
    for(i=len; i>=1; i--) printf("%c", a[i]);
    printf("\n");
  }
}