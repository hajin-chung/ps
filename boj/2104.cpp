#include <bits/stdc++.h>
#define INF 5000000
using namespace std;

typedef long long int ll;
int n;
vector<ll> a, tree, psum;

void init(int node, int l, int r) {
  if (l == r) tree[node] = l;
  else {
    int m = (l+r)>>1;
    init(node*2, l, m);
    init(node*2+1, m+1, r);
    if (a[tree[node*2]] < a[tree[node*2+1]]) tree[node] = tree[node*2];
    else tree[node] = tree[node*2+1];
  }
}

int query(int node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return INF;
  if (ql <= l && r <= qr) return tree[node];
  int m = (l+r)>>1;
  int rl = a[query(node*2, l, m, ql, qr)];
  int rr = a[query(node*2+1, m+1, r, ql, qr)];
  if (a[rl] < a[rr]) return rl;
  else return rr;
}

ll query(int ql, int qr) { return query(1, 1, n, ql, qr); }

ll rec(int l = 1, int r = n) {
  cout<<l<< " "<<r<<endl;
  if (l == r) return a[l]*a[l];
  int midx = query(l, r);
  ll sum = (psum[r]-psum[l-1])*a[midx];
  ll rl = rec(l, midx-1);
  ll rr = rec(midx+1, r);
  return max(sum, max(rl, rr));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n; a.resize(n+1); tree.resize(4*n+1); psum.resize(n+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    psum[i] = psum[i-1]+a[i];
  }
  init(1, 1, n);
  cout << rec() << "\n";
}
