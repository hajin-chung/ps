#include <stdio.h>

int main() {
  FILE* f = fopen("2.input.test.txt", "r");

  int n;
  int sum = 0;
  char a, b;
  int ac, bc;

  fscanf(f, "%d", &n);
  for(int i=0 ; i<n; i++) {
    fscanf(f, " %c %c", &a, &b); 
    ac = a-'A';
    bc = b-'X';
    sum += bc+1;

    if (bc == ac) sum += 3;
    else if ((ac+1)%3 == bc) sum += 6;
  }

  printf("%d\n", sum);
}