#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n%2 == 0) {
    for (int i = 1; i <= n/2; i++) printf("%d %d ", i, -i);
    printf("0\n");
  } else {
    for (int i = 1; i <= n/2; i++) printf("%d %d ", i, -i);
    printf("%d %d\n", n*n, n);
  }
}
