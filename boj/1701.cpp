#include <bits/stdc++.h>
using namespace std;

char str[5000];
int pi[5000], n;

int main() {
  scanf("%s", str); 
  n = strlen(str);
  int mx = 0;
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && str[i] != str[j]) j = pi[j-1];
    if (str[i] == str[j]) pi[i] = ++j;
    mx = max(mx, pi[i]);
  }
  printf("%d\n", mx);
}
