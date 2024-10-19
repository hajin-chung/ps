#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, sa = 0, t, cnt = 0;
  scanf("%d%d%d",&a,&b,&c);
  t = b;
  sa = a;
  while (t) {
    sa *= 10;
    t /= 10;
  }
  printf("%d\n%d\n", a+b-c, sa+b-c);
}
