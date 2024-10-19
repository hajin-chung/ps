#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  int n, x;
  ll cnt = 0;
  stack<int> S;

  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    cnt += (ll)S.size();
    while (!S.empty() && S.top() < x) S.pop();
    S.push(x);
  }
  printf("%lld\n", cnt);
}
