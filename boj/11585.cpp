#include <bits/stdc++.h>
#define N 1000000
using namespace std;

char str[2*N], pat[N];
int pi[N];
int n;

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a%b);
}

int main() {
  scanf("%d", &n);
  char c;
  for (int i = 0; i < n; i++) {
    scanf(" %c", &c);
    str[i] = str[i+n] = c;
  }
  for (int i = 0; i < n; i++) {
    scanf(" %c", &c);
    pat[i] = c;
  }

  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && pat[i] != pat[j]) j = pi[j-1];
    if (pat[i] == pat[j]) pi[i] = ++j;
  }

  j = 0;
  int cnt = 0;
  for (int i = 0; i < 2*n-1; i++) {
    while (j > 0 && str[i] != pat[j]) j = pi[j-1];
    if (str[i] == pat[j]) {
      if (j == n-1) {
        cnt++;
        j = pi[j];
      } else {
        j++;
      }
    }
  }
  int g = gcd(cnt, n);
  printf("%d/%d\n", cnt/g, n/g);
}
