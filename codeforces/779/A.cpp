#include <stdio.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    int l1, l2;
    char c;
    int cnt = 0;
    l1 = l2 = 1;
    scanf("%d ", &n);
    while (n--) {
      scanf("%c", &c);
      if (c == '0' && l1 == 1 && l2 == 0) cnt++;
      else if (c == '0' && l1 == 0) cnt += 2;
      l2 = l1;
      l1 = c-'0';
    }
    printf("%d\n", cnt);
  }
}