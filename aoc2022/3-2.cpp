#include <stdio.h>
#include <string.h>

int main()
{
  char a[1000];
  int flags[60], fsum[60];

  FILE *f = fopen("3.input.txt", "r");
  // FILE* f = fopen("3.input.test.txt", "r");

  int n;
  int sum = 0;

  fscanf(f, "%d", &n);
  for (int i = 0; i < n;)
  {
    for (int j = 0; j < 60; j++)
      fsum[j] = flags[j] = 0;
    for (int k = 0; k < 3; i++, k++)
    {
      for (int j = 0; j < 1000; j++)
        a[j] = 0;
      fscanf(f, "%s", &a);

      int len = strlen(a);
      for (int j = 0; j < len; j++)
      {
        int idx = 'a' <= a[j] && a[j] <= 'z' ? a[j] - 'a' + 1 : a[j] - 'A' + 1 + 26;
        flags[idx] = 1;
      }
      for (int j = 0; j < 60; j++)
      {
        fsum[j] += flags[j];
        flags[j] = 0;
      }
    }

    for (int j = 0; j < 60; j++)
      sum += fsum[j] == 3 ? j : 0;
  }
  printf("%d", sum);
}