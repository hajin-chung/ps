#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 2e5;
vector<int> vv[20];
int ans[N+1], a[N+1];

void f() {
  int n; cin>>n;
  for (int i = 1; i <= 18; i++) vv[i].clear();
  int mxl = 0;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    mxl = max(mxl, a[i]);
  }
  mxl++;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) vv[mxl].push_back(i);
    else vv[a[i]].push_back(i);
  }
  set<int> alive;
  for (int i = 1; i <= n; i++) alive.insert(i);
  int l = 1, h = n;
  for (int i = 1; i < mxl; i++) {
    if (vv[i].size() == 0) continue;
    int vn = vv[i].size();
    int k = 0;
    for (; k < vn && vv[i][k] < vv[i+1][0]; k++) {
      int j = vv[i][k];
      if (i%2 == 1) ans[j] = h--;
      else ans[j] = l++;
    }
    for (int k2 = vn-1; k2 >= k; k2--) {
      int j = vv[i][k2];
      if (i%2 == 1) ans[j] = h--;
      else ans[j] = l++;
    }
  }
  if (mxl%2 == 1) ans[vv[mxl][0]] = h;
  else ans[vv[mxl][0]] = l;
  for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
