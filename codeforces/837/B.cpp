#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int min(int a, int b) {
  return a > b ? b : a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

ll sum(int n) {
  return n * (n+1) / 2;
}

void solve() {
  int n, p, i;
  int x, y, tx, ty;
  ll cnt = 0;
  scanf("%d %d", &n, &p);
  vector<int> a(n+1, n+1), b(n+1, 0);
  for(i=1 ; i<=p; i++) {
    scanf("%d %d", &tx, &ty);
    x = min(tx, ty);
    y = max(tx, ty);
    if (a[x] > y) a[x] = y;
  } 

  for(i=1 ; i<=n ; i++) {
    if (b[a[i]] < i) b[a[i]] = i;
  }

  int pivot = 1;
  for(i=1 ; i<=n ; i++) {
    if (b[i] != 0) {
      cnt += sum(i-pivot);
      pivot = max(b[i]+1, i);
    }
  }
  if (pivot <= n)
    cnt += sum(n+1-pivot);
  printf("%lld\n", cnt);
}

int main() {
  int t;

  scanf("%d", &t);
  while(t--) {
    solve();
  }
}