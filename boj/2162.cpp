#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

vector<pair<pll, pll>> a;
vector<ll> parent, counts;

ll ccw(pll p1, pll p2, pll p3) {
  ll s = (p1.fi*p2.se + p2.fi*p3.se + p3.fi*p1.se) 
       - (p2.fi*p1.se + p3.fi*p2.se + p1.fi*p3.se);
  if (s > 0) return 1;
  else if (s < 0) return -1;
  return 0;
}

int isIntersect(pair<pll, pll> l1, pair<pll, pll> l2) {
  pll p1 = l1.first;
  pll p2 = l1.second;
  pll p3 = l2.first;
  pll p4 = l2.second;

  ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); 
  ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
  
  if (p1p2 == 0 && p3p4 == 0) {
    if (p1 > p2) swap(p2, p1);
    if (p3 > p4) swap(p3, p4);

    return p3 <= p2 && p1 <= p4;
  }
  return p1p2 <= 0 && p3p4 <= 0;
}

int find(int x) {
  if (parent[x] == x) return x;
  else return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

int main() {
  int n, i, j;
  ll cnt = 0, mx = 0;

  scanf("%d", &n);
  a.resize(n); parent.resize(n); counts.resize(n);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld %lld %lld", &a[i].fi.fi, &a[i].fi.se, &a[i].se.fi, &a[i].se.se);
    parent[i] = i;
  }

  for (i = 1; i < n; i++) 
    for (j = 0; j < i; j++) 
      if (find(i) != find(j) && isIntersect(a[i], a[j]))
        unite(i, j);

  for (i = 0; i < n; i++) {
    int p = find(i);
    counts[p]++;
    mx = max(mx, counts[p]);
    if (counts[p] == 1) cnt++;
  }

  printf("%lld\n%lld\n", cnt, mx);
}
