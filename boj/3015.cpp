#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;

int main() {
  int n, x;
  ll cnt = 0;
  stack<pair<int, int>> S;

  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    while (!S.empty() && S.top().fi < x) {
      cnt += S.top().se;
      S.pop();
    }
    int v = 1;
    if (!S.empty() && S.top().fi == x) {
      v += S.top().se;
      cnt += S.top().se;
      S.pop();
    }
    if (!S.empty()) cnt++;
    S.push({x, v});
  }
  printf("%lld\n", cnt);
}
