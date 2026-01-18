#include <stdio.h>
#include <vector>
#define INF 100000000000
using namespace std;

typedef long long int ll;

vector<ll> A, B;
vector<ll> tree;

ll min(ll a, ll b) {
  return (a<b)?a:b;
}

ll gcd(ll a, ll b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
  return a*b/gcd(a, b);
}

ll cost(ll a, ll b) {
  return lcm(a, b) / gcd(a, b);
}

ll update(int idx, int l, int h, int tl, int th, ll val) {
  if (th < l || h < tl) return tree[idx];
  if (l >= h) return tree[idx] = cost(val, B[l]);

  int mid = l + (h-l)/2;
  return tree[idx] = min(update(idx*2, l, mid, tl, th, val), update(idx*2+1, mid+1, h, tl, th, val));
}

ll query(int idx, int l, int h, int tl, int th) {
  if (th < l || h < tl) return INF;
  if (tl <= l && h <= th) return tree[idx];

  int mid = l + (h-l)/2;
  return min(query(idx*2, l, mid, tl, th), query(idx*2+1, mid+1, h, tl, th));
}

int main() {
  int n, q;
  int t, l, r;
  int i;

  scanf("%d %d",&n, &q);
  A.resize(n+1, 0);
  B.resize(n+1, 0);
  tree.resize(n*3 + 5, INF);
  for(i=1 ; i<=n; i++) scanf("%lld", &A[i]);
  for(i=1 ; i<=n; i++) scanf("%lld", &B[i]);

  for(i=1 ; i<=n; i++) update(1, 1, n, i, i, A[i]);
  for(i=1 ; i<=q ; i++) {
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      ll x;
      scanf("%lld", &x);
      update(1, 1, n, l, r, x);
    } else {
      printf("%lld\n", query(1, 1, n, l, r));
    }
  }
}