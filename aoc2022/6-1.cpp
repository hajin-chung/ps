#include <stdio.h>
#include <string.h>

char a[1000];
int main() {
  FILE* f = fopen("6.input.txt", "r");

  fscanf(f, "%s", a);
  int len = strlen(a);
  for(int i=0; i<len-4; i++) {
    if (a[i] != a[i+1] && a[i] != a[i+2] && a[i] != a[i+3] && a[i+1] != a[i+2] && a[i+1] != a[i+3] && a[i+2] != a[i+3]) {
      printf("%d", i+1);
      break;
    }
  }

}