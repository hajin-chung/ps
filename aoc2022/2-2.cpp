#include <stdio.h>

int abs(int x) {
  return x < 0 ? -x : x;
}

int main()
{
  // FILE *f = fopen("2.input.test.txt", "r");
  FILE *f = fopen("2.input.txt", "r");

  int n;
  int sum = 0;
  char a, b;
  int ac, bc;

  fscanf(f, "%d", &n);
  for (int i = 0; i < n; i++)
  {
    fscanf(f, " %c %c", &a, &b);
    ac = a - 'A';
    bc = b - 'X';

    sum += bc * 3;

    // if (bc == 0)
    //   sum += abs(ac - 1) % 3 + 1;
    // else if (bc == 1)
    //   sum += ac + 1;
    // else
    //   sum += (ac + 1) % 3 + 1;

    if (bc == 0) {
      if (ac == 0) sum += 3;
      else if(ac == 1) sum += 1;
      else sum += 2;
    } else if(bc == 1) {
      sum += ac +1;
    } else {
      if (ac == 0) sum += 2;
      else if (ac== 1) sum += 3;
      else sum += 1;
    }

    printf("%d\n", sum);
  }

  printf("%d\n", sum);
}