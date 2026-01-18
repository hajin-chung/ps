#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

int n;
vector<pll> a;
pll pivot = {40001, 40001};

ll ccw(pll a, pll b, pll c) {
  ll v = (b.fi-a.fi)*(c.se-a.se) - (b.se-a.se)*(c.fi-a.fi);
  if (v > 0) return 1;
  else if (v == 0) return 0;
  else return -1;
}

ll dist(pll a) {
  ll dx = pivot.fi-a.fi;
  ll dy = pivot.se-a.se;
  return dx*dx+dy*dy; 
}

bool comp(pll a, pll b) {
  int p = ccw(pivot, a, b);
  if (p == 0) return dist(a) < dist(b);
  else return p > 0;
}

int main() {
  int i, idx;
  ll x, y;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld", &x, &y);
    a.push_back({x, y});
    if (a[i] < pivot) {
      pivot = a[i];
      idx = i;
    }
  }
  swap(a[idx], a[0]);
  sort(a.begin()+1, a.end(), comp);

  stack<pll> S;
  S.push(a[0]);
  S.push(a[1]);
  for (i = 2; i < n; i++) {
    while (S.size() >= 2) {
      pll second = S.top(); S.pop();
      pll first = S.top();
      if (ccw(first, second, a[i]) > 0) {
        S.push(second);
        break;
      }
    }
    S.push(a[i]);
  }
  printf("%d\n", S.size());
}
