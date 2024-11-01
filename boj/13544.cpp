#include <algorithm>
#include <bits/stdc++.h>
#define N 100000
using namespace std;

vector<int> tree[4*N+5];
int a[N+5], n;

void init(int node, int s, int e) {
  if (s == e) {
    tree[node].push_back(a[s]);
  } else {
    int m = (s+e)>>1;
    init(node*2, s, m);
    init(node*2+1, m+1, e);
    merge(
      tree[node*2].begin(), 
      tree[node*2].end(), 
      tree[node*2+1].begin(),
      tree[node*2+1].end(),
      back_inserter(tree[node])
    );
  }
}

int count(int node, int k) {
  auto b = tree[node].begin(), e = tree[node].end();
  return e - upper_bound(b, e, k);
}

int query(int node, int s, int e, int qs, int qe, int k) {
  if (e < qs || qe < s) return 0;
  if (qs <= s && e <= qe) {
    return count(node, k);
  }
  else {
    int m = (s+e)>>1;
    return query(node*2, s, m, qs, qe, k) + query(node*2+1, m+1, e, qs, qe, k);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) 
    scanf("%d", &a[i]);
  init(1, 1, n);
  int la = 0, a, b, c, m;
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &a, &b, &c);
    int s = a^la, e = b^la, k = c^la;
    la = query(1, 1, n, s, e, k);
    printf("%d\n", la);
  }
}
