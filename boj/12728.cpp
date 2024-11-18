#include <bits/stdc++.h>
#define M 1000
using namespace std;

typedef long double ld;

ld sanitize(ld x) {
  x -= (int)(x/M)*M;
  return x;
}

ld pow(ld x, int n) {
  if (n == 0) return 1.0;
  if (n == 1) return x;
  if (n%2 == 0) {
    ld y = pow(x, n/2);
    return sanitize(y*y);
  } else {
    ld y = pow(x, (n-1)/2);
    return sanitize(x*y*y);
  }
}

int main() {
  int t; scanf("%d", &t);
  ld x = 3.0+sqrt(5);
  while (t--) {
    int n; cin>>n;
    printf("%03d\n", (int)pow(x, n)%1000);
  }
}
