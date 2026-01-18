#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int t[4000005];

void update(int node, int l, int h, int idx, int diff) {
  if (idx < l || h < idx) return;
  t[node] += diff;
  if (l != h) {
    int mid = (l+h)>>1;
    update(node*2, l, mid, idx, diff);
    update(node*2+1, mid+1, h, idx, diff);
  }
}

int query(int node, int l, int h, int nl, int nh) {
  if (nh < l || h < nl) return 0;
  if (nl <= l && h <= nh) return t[node];
  int mid = (l+h)>>1;
  return query(node*2, l, mid, nl, nh) + query(node*2+1, mid+1, h, nl, nh);
}

int main() {
  int n, f, c, q, l, h;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &q);
    if (q == 2) {
      scanf("%d %d", &f, &c);
      update(1, 1, N, f, c);
    } else {
      scanf("%d", &c);
      l = 1, h = N;
      while (l < h) {
        int mid = (l+h)>>1;
        int sum = query(1, 1, N, 1, mid);
        if (c <= sum) h = mid;
        else l = mid+1;
      }
      printf("%d\n", l);
      update(1, 1, N, l, -1);
    }
  }
}
