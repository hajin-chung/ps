#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)
#define fi first
#define se second
#define INF 2000000000
#define N 100000
using namespace std;

struct Node { int L, R, M; };
Node tree[4*N];
int a[N+1], sum[N+1], n;

int max(Node n) { return max(n.M, max(n.L, n.R)); }

void init(int node, int l, int r) {
  tree[node] = {-INF, -INF, -INF};
  if (l == r) {
    tree[node] = {a[l], a[l], a[l]};
    return;
  }
  
  int m = (l+r)>>1;
  init(node*2, l, m); init(node*2+1, m+1, r);
  tree[node].L = max(tree[node*2].L, sum[m]-sum[l-1]+tree[node*2+1].L);
  tree[node].R = max(tree[node*2+1].R, sum[r]-sum[m]+tree[node*2].R);
  tree[node].M = max({
    tree[node*2].M, 
    tree[node*2+1].M, 
    tree[node*2].R+tree[node*2+1].L
  });
}

Node query(int node, int l, int r, int ql, int qr) {
  Node ret = {-INF, -INF, -INF}; 
  if (qr < l || r < ql) return ret;
  if (ql <= l && r <= qr) return tree[node];

  int m = (l+r)>>1;
  Node lq = query(node*2, l, m, ql, qr);
  Node rq = query(node*2+1, m+1, r, ql, qr);
  ret.L = max(lq.L, rq.L+sum[m]-sum[l-1]);
  ret.R = max(rq.R, lq.R+sum[r]-sum[m]);
  ret.M = max({lq.M, rq.M, lq.R+rq.L});
  return ret;
}

int main() {
  FASTIO;
  int n; cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
  }
  init(1, 1, n);
  int t; cin>>t;
  while(t--) {
    int l, r; cin>>l>>r;
    cout<<query(1,1,n,l,r).M<<"\n";
  }
}
