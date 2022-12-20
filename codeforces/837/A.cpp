#include <stdio.h>

typedef long long int ll;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    ll mn, mx, mncnt, mxcnt;  
    mx = mncnt = mxcnt = 0;
    mn = 100005;
    scanf("%d", &n);
    while(n--) {
      ll x;
      scanf("%lld", &x);
      if (x > mx) {
        mx = x;
        mxcnt = 1;
      } else if (x == mx) mxcnt++;
      if (x < mn) {
        mn = x;
        mncnt = 1;
      } else if (x == mn) mncnt++;
    }
    if (mn != mx)
      printf("%lld\n", 2*mxcnt*mncnt);
    else printf("%lld\n", mxcnt * (mxcnt-1));
  }
}