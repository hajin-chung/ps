#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 3e5;
int b[N+1], l[N+1], x[N+1], y[N+1], z[N+1];

void f() {
  int n, q; cin>>n>>q;
  for (int i = 1; i <= n; i++) cin>>b[i];
  for (int i = 1; i <= q; i++)
    cin>>x[i]>>y[i]>>z[i];
  for (int i = 1; i <= n; i++) l[i] = b[i];
  for (int i = q; i >= 1; i--) {
    l[x[i]] = max(l[x[i]], l[z[i]]);
    l[y[i]] = max(l[y[i]], l[z[i]]);
    l[z[i]] = 0;
  }
  for (int i = 1; i <= n;i++) cout<<l[i]<<" ";
  cout<<endl;
  for (int i = 1; i <= q; i++) {
    l[z[i]] = min(l[x[i]], l[y[i]]);
  }
  for (int i = 1;  i<= n; i++)
    if (l[i] != b[i]) {
      cout<<"-1\n";
      return;
    }
  for (int i = 1; i <= n; i++) cout<<l[i]<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
