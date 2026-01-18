#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const int N = 2e5;
const int INF = 1<<30;
int a[N+1], b[N+1];
int seg[4*N+5][2];

void init(int node, int l, int r) {
  if (l == r) {
    seg[node][0] = b[l];
    seg[node][1] = a[l];
    return;
  }
  int m = (l+r)>>1;
  init(node*2, l, m);
  init(node*2+1, m+1, r);
  seg[node][0] = min(seg[node*2][0], seg[node*2+1][0]);
  seg[node][1] = max(seg[node*2][1], seg[node*2+1][1]);
}

int minquery(int node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return INF;
  if (ql <= l && r <= qr) return seg[node][0];
  int m = (l+r)>>1;
  int rl = minquery(node*2, l, m, ql, qr);
  int rr = minquery(node*2+1, m+1, r, ql, qr);
  return min(rl, rr);
}

int maxquery(int node, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return seg[node][1];
  int m = (l+r)>>1;
  int rl = maxquery(node*2, l, m, ql, qr);
  int rr = maxquery(node*2+1, m+1, r, ql, qr);
  return max(rl, rr);
}

void f() {
  int n; cin>>n;
  vector<vector<int>> aidx(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  for (int i = 1; i <= n; i++) {
    cin>>b[i];
    aidx[a[i]].push_back(i);
  }
  init(1, 1, n);

  bool flag = 1;
  for (int i = 1; i <= n && flag; i++) {
    if (a[i] > b[i]) flag = 0;
    if (a[i] >= b[i]) continue;
    if (aidx[b[i]].size() == 0) {
      flag = 0;
      continue;
    }

    bool ok = 0;

    auto rit = upper_bound(all(aidx[b[i]]), i);
    if (rit != aidx[b[i]].end()) {
      int r = *rit;
      if (maxquery(1, 1, n, i, r) <= b[i] && minquery(1, 1, n, i+1, r) >= b[i])
        ok = 1;
    }

    auto lit = lower_bound(all(aidx[b[i]]), i);
    if (lit != aidx[b[i]].begin()) {
      --lit;
      int l = *lit;
      if (maxquery(1, 1, n, l, i) <= b[i] && minquery(1, 1, n, l, i-1) >= b[i])
        ok = 1;
    }

    if (!ok) flag = 0;
  }
  if (flag) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
