#include <stdio.h>
#include <map>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int mn1, mn2, mx1, mx2, cnt;
    int n, x;
    map<int, int> mp;
    cnt = 0;
    mn1 = mn2 = 1000000005;
    mx1 = mx2 = 0;
    scanf("%d", &n);
    while(n--) {
      scanf("%d", &x);
      if (!mp.count(x)) {
        cnt++;
        mp[x] = 1;
      }
      if (x < mn1) mn2 = mn1, mn1 = x;
      else if (mn1 < x && x < mn2) mn2 = x;
      if (x > mx1) mx2 = mx1, mx1 = x;
      else if (mx1 > x && x > mx2) mx2 = x;
    }
    // printf("%d %d %d\n", mx1, mx2, mn);
    if (cnt == 1) printf("0\n");
    else if (cnt == 2) printf("%d\n", 2*(mx1-mn1));
    else printf("%d\n", max((mx1-mx2+mx1-mn1), (mx1-mn1+mn2-mn1)));
  }
}