#include <bits/stdc++.h>
using namespace std;

const int MAX = 1500;
int a[MAX+5][MAX+5];
struct XT { 
  int v; XT *l, *r; 
  XT(): v(0), l(0), r(0) {}
};
struct YT { 
  XT *v; YT *l, *r; 
  YT(): v(new XT()), l(0), r(0) {}
};

void init(XT *node, int l, int r, int pos) {
  if (l == r) {
    node->v = a[pos][l];
    return;
  }
  int m = (l+r)>>1;
  node->l = new XT(); init(node->l, l, m, pos);
  node->r = new XT(); init(node->r, m+1, r, pos);
  node->v = max(node->l->v, node->r->v);
}

void init(YT *node, int l, int r) {
  if (l == r) {
    init(node->v, 0, MAX, l);
    return;
  }
  int m = (l+r)>>1;
  node->l = new YT(); init(node->l, l, m);
  node->r = new YT(); init(node->r, m+1, r);
}

int query(XT *node, int l, int r, int x1, int x2) {
  cout<<"xq: "<<l<<" "<<r<<" "<<x1<<" "<<x2<<endl;
  if (x2 < l || r < x1) return 0;
  if (x1 <= l && r <= x2) return node->v;
  int m = (l+r)>>1;
  int rl = query(node->l, l, m, x1, x2);
  int rr = query(node->r, m+1, r, x1, x2);
  return max(rl, rr);
}

int query(YT *node, int l, int r, int y1, int y2, int x1, int x2) {
  cout<<"yq: "<<l<<" "<<r<<" "<<y1<<" "<<y2<<endl;
  if (y2 < l || r < y1) return 0;
  if (y1 <= l && r <= y2) return query(node->v, 0, MAX, x1, x2);
  int m = (l+r)>>1;
  int rl = query(node->l, l, m, y1, y2, x1, x2);
  int rr = query(node->r, m+1, r, y1, y2, x1, x2);
  return max(rl, rr);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  while (n--) {
    int y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
    a[y1][x1] = 1; a[y1][x2] = -1;
    a[y2][x1] = -1; a[y2][x2] = 1;
  }
  for (int i = 0; i <= MAX; i++) {
    for (int j = 1; j <= MAX; j++)
      a[i][j] += a[i][j-1];
    if (i == 0) continue;
    for (int j = 0; j <= MAX; j++)
      a[i][j] += a[i-1][j];
  }
  YT *seg = new YT();
  init(seg, 0, MAX);
  while (m--) {
    int y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
    cout<<query(seg, 0, MAX, y1, y2, x1, x2)<<"\n";
  }
}
