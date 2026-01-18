#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 300000;
const int MAX = 1000005;
int n;
double a[N+1], mxseg[4*N+5], mnseg[4*N+5];
vector<double> seg[4*N+5];

void init(int node, int l, int r) {
  if (l == r) {
    seg[node].push_back(a[l]);
    return;
  }
  int m = (l+r)>>1;
  init(node*2, l, m); init(node*2+1, m+1, r);
  merge(all(seg[node*2]), all(seg[node*2+1]), back_inserter(seg[node]));
}

// mode 0 : find number of elements bigger
// mode 1 : find number of elements smaller
int query(int node, int l, int r, int ql, int qr, double v, int mode) {
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) {
    if (mode == 0) {
      auto it = upper_bound(all(seg[node]), v);
      return seg[node].end()-it;
    } else {
      auto it = lower_bound(all(seg[node]), v);
      return it-seg[node].begin();
    }
  }
  int m = (l+r)>>1;
  int rl = query(node*2, l, m, ql, qr, v, mode);
  int rr = query(node*2+1, m+1, r, ql, qr, v, mode);
  return rl+rr;
}

int query(int pos) {
  double l = -1, r = MAX, m = (l+r)/2;
  int iter = 100;
  while (iter--) {
    double m1 = (2*l+r)/3, m2 = (l+2*r)/3;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) cin>>a[i];
  init(1, 1, n);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    cnt += query(1, 1, n, i+1, n, a[i], 1);
  cout<<cnt<<"\n";
}
