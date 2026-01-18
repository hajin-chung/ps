#include <stdio.h>
#include <string.h>

char a[5000];
int flags[1000];
int main()
{
  FILE *f = fopen("6.input.txt", "r");
  int flag = 0;

  fscanf(f, "%s", a);
  int len = strlen(a);
  printf("%d\n", len);
  for (int i = 14; i <= len; i++)
  {
    for (int j = 0; j < 1000; j++)
      flags[j] = 0;
    flag = 0;
    for (int j = i - 14; j < i; j++)
    {
      if (flags[a[j]] == 1)
      {
        flag = 1;
        break;
      }
      else
        flags[a[j]] = 1;
    }
    printf("%d", flag);
    if (flag == 0)
    {
      printf("%d", i);
      break;
    }
  }
}