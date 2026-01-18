#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, j, x;
  vector<int> a;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    a.push_back(x);
  }

  for (i = 0; i < n; i++) {
    printf("%d", 111 + i);
    for (j = 0; j < a[i] - 1; j++) printf("0");
    printf("\n");
  }
}
