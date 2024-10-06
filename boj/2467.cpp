#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<int> a;

int main() {
  int i, k, x, mn = 2000000000;
  pair<int, int> ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    a.pb(x);
  }

  for (i = 0; i < n; i++) {
    int j = lower_bound(a.begin(), a.end(), -a[i]) - a.begin();
    for (k = -1; k <= 1; k++) {
      if (j + k != i && j + k >= 0 && j + k < n 
          && abs(a[i] + a[j+k]) < abs(mn)) {
        mn = abs(a[i] + a[j+k]);
        if (a[i] > a[j+k]) ans = {a[j+k], a[i]};
        else ans = {a[i], a[j+k]};
      }
    }
  }

  printf("%d %d\n", ans.first, ans.second);
}
