#include <stdio.h>

int main() {
  int m, l, h;
  int lc, hc;
  int n;
  int x;

  l = -10001;
  h = 10001;
  lc = 1;
  hc = 0;

  scanf("%d", &n);
  scanf("%d", &m);
  printf("%d\n", m);

  for (int i=0; i<n-1; i++) {
    scanf("%d", &x);

    if (x <= m) lc++;
    else hc++;

    if (l < x && x <= m) {
      if (lc > hc) {
        l = m; 
        m = x;
      } else {
        l = x;
      }
    } else if (m < x && x < h) {
      if (hc > lc) {
        m = h;
        h = x;
      }
    }
  }
}