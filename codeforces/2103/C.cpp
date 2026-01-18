#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 2e5;
int n, k; 
vector<int> a;
vector<int> sum[2];

bool chk(vector<int> &sum) {
  int zcnt = 0, mn = N+5;
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i-1] + ((a[i] > k) ? 1 : -1);
    mn = min(sum[i], mn);
    zcnt += (sum[i] == 0);
  } 
  return zcnt >= 2 || (a[1] <= k && mn <= -2) || (a[1] > k && mn <= -1);
}

bool chk2() {
  int l = -1, r = -1;
  for (int i = 1; i < n; i++)
    if (sum[0][i] <= 0) {
      l = i;
      break;
    }
  for (int i = 1; i < n; i++)
    if (sum[1][i] <= 0) {
      r = n-i+1;
      break;
    }
  if (l == -1 || r == -1) return 0;
  return (r-l >= 2);
}

void f() {
  cin>>n>>k;
  a.clear(); a.resize(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  bool flag = 0;
  sum[0].clear();
  sum[1].clear();
  sum[0].resize(n+1);
  sum[1].resize(n+1);
  flag |= chk(sum[0]);
  reverse(a.begin()+1, a.end());
  flag |= chk(sum[1]);
  flag |= chk2();
  if (flag) cout<<"YES\n";
  else cout<<"NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
