#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b, u, v, pi;

int main() {
  scanf("%d", &n);
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    u.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(u.begin(), u.end());
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) a.push_back(i ? u[i] - u[i-1] : u[i]+360000-u[n-1]);
  for (int i = 0; i < n; i++) b.push_back(i ? v[i] - v[i-1] : v[i]+360000-v[n-1]);
  for (int i = 0; i < n; i++) a.push_back(a[i]);

  int j = 0;
  pi.resize(n);
  for (int i = 1; i < n; i++) {
    while (j > 0 && b[i] != b[j]) j = pi[j-1];
    if (b[i] == b[j]) pi[j] = ++j;
  }

  j = 0;
  bool possible = false;
  for (int i = 0; i < 2*n; i++) {
    while (j > 0 && b[j] != a[i]) j =pi[j-1];
    if (b[j] == a[i] && ++j == n) possible = true;
  }
  possible ? printf("possible\n") : printf("impossible\n");
}
