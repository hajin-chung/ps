#include <bits/stdc++.h>
using namespace std;

char str[1000000];
int n, pi[1000000];

int main() {
  scanf("%d\n%s", &n, str);
  pi[0] = 0;
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && str[i] != str[j]) j = pi[j-1];
    if (str[i] == str[j]) {
      pi[i] = j+1;
      j++;
    }
  }
  printf("%d\n", n - pi[n-1]);
}
