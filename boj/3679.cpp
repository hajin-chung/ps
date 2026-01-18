#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
ppi pivot;

int ccw(ppi a, ppi b, ppi c) {
  pii v1 = {b.fi.fi - a.fi.fi, b.fi.se - a.fi.se};
  pii v2 = {c.fi.fi - a.fi.fi, c.fi.se - a.fi.se};
  int crs = v1.fi*v2.se-v1.se*v2.fi;
  if (crs > 0) return 1;
  else if (crs == 0) return 0;
  else return -1;
}

int dist(ppi a, ppi b) {
  int dy = b.fi.fi - a.fi.fi;
  int dx = b.fi.se - a.fi.se;
  return dy*dy + dx*dx;
}

bool cmp(ppi a, ppi b) {
  int c = ccw(pivot, a, b);
  if (c != 0) return c > 0;
  else return dist(pivot, a) < dist(pivot, b);
}

void solve() {
  int n, idx = 0;
  vector<ppi> a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a.push_back({{x, y}, i});
    if (i == 0) pivot = a[i], idx = 0;
    else if (pivot > a[i]) pivot = a[i], idx = i;
  }
  swap(a[idx], a[0]);
  sort(a.begin()+1, a.end(), cmp);
  idx = n-1;
  while (ccw(a[0], a[idx], a[idx-1]) == 0) idx--;
  for (int i = 0; i < idx; i++) printf("%d ", a[i].se);
  for (int i = n-1; i >= idx; i--) printf("%d ", a[i].se);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
