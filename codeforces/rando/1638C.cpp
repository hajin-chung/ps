#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 1e5;
const int INF = 1e9;
int ft[N+1], n, a[N+5];

int query(int i) {
  int ret = 0;
  for (; i; i -= (i&-i)) ret += ft[i];
  return ret;
}

void update(int i) {
  for (; i <= n; i +=(i&-i)) ft[i]++;
}

void f() {
  cin>>n;
  for (int i = 1; i <= n; i++) ft[i] = 0;
  for (int i = 1; i <= n; i++) cin>>a[i];
  a[n+1] = INF;
  int p = 0, cnt = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    update(a[i]);
    mx = max(mx, a[i]);
    if (a[i] > a[i+1]) continue;
    if (query(mx)-query(p) == mx-p) {
      cnt++;
      p = mx;
    }
  }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}

