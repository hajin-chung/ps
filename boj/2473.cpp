#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long int ll;
int n;
vector<ll> a;
ll mn = 3e9 + 10;
array<ll, 3> ans;

void sol(int x) {
  int i, j, k;
  int m = n-1;
  for (i = 0; i < m; i++) {
    int j = lower_bound(a.begin(), a.end(), -(a[i]+x)) - a.begin();
    for (k = -1; k <= 1; k++) {
      if (j + k != i && j + k >= 0 && j + k < m
          && abs(a[i] + x + a[j+k]) < abs(mn)) {
        mn = abs(a[i] + x + a[j+k]);
        ans = {a[j+k], a[i], x};
      }
    }
  }
}

int main() {
  int i, j, lo, hi;
  ll x, sum;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &x);
    a.pb(x);
  }
  sort(a.begin(), a.end());
  for (i = 0; i < n; i++) {
    x = a[i];
    a.erase(a.begin() + i);
    sol(x);
    a.insert(a.begin() + i, x);
  }
  sort(ans.begin(), ans.end());
  printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
}
