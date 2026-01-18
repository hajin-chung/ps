#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const int N = 2e5;
const int INF = 1e9;
int seg[4*N+5];

void update(int node, int l, int r, int i, int v) {
  if (i < l || r < i) return;
  if (l == r && r == i) {
    seg[node] = min(seg[node], v);
    return;
  }
  int m = (l+r)>>1;
  update(node*2, l, m, i, v);
  update(node*2+1, m+1, r, i, v);
  seg[node] = min(seg[node*2], seg[node*2+1]);
}

int query(int node, int l, int r, int ql, int qr) {
  if (r < ql || qr < l) return INF;
  if (ql <= l && r <= qr) return seg[node];
  int m = (l+r)>>1;
  int rl = query(node*2, l, m, ql, qr);
  int rr = query(node*2+1, m+1, r, ql, qr);
  return min(rl, rr);
}

void solve() {
  set<int> pi;
  int n, q; cin>>n>>q;
  for (int i = 1; i <= n; i++) pi.insert(i);
  for (int i = 1; i <= 4*n; i++) seg[i] = INF;
  while (q--) {
    int t; cin>>t;
    if (t == 0) {
      int l, r, x; cin>>l>>r>>x;
      if (x == 0) {
        auto it = pi.lower_bound(l);
        while (it != pi.end() && *it <= r) {
          int v = *it; pi.erase(it);
          it = pi.upper_bound(v);
        }
      } else {
        update(1, 1, n, l, r);
      }
    } else {
      int idx; cin>>idx;
      if (!pi.count(idx)) {
        cout<<"NO\n";
        continue;
      }

      auto it = pi.lower_bound(idx);
      int l = it == pi.begin() ? 1 : *prev(it)+1;
      it = pi.lower_bound(idx+1);
      int r = it == pi.end() ? n : *it-1;
      if (query(1, 1, n, l, idx) <= r) cout<<"YES\n";
      else cout<<"N/A\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
