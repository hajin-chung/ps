#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

bool solve() {
  ll n, x, ans = 0, i;
  stack<pll> S;

  scanf("%lld", &n);
  if (n == 0) return false;

  for (i = 0; i < n; i++) {
    scanf("%lld", &x);
    while (!S.empty() && S.top().first > x) {
      auto [h, idx] = S.top(); S.pop();
      ans = max(ans, h * (i - idx));
    }
    S.push({x, i});
  }
  while (!S.empty()) {
    auto [h, idx] = S.top();
    S.pop();
    ans = max(ans, h * (i - idx));
  }
  printf("%lld\n", ans);

  return true;
}

int main() {
  while (solve()) {}
}
