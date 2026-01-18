#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 2e5;

void f() {
  int n; cin>>n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  vector<int> lv(n+1), rv(n+1);
  for (int i = 1; i <= n; i++) cin>>lv[i]>>rv[i];

  int h = 0;
  set<int> midx;
  bool flag = 1;
  for (int i = 1; i <= n; i++) {
    int l = lv[i], r = rv[i];

    if (a[i] == 1) h++;
    else if (a[i] == -1) midx.insert(i);

    if (h+midx.size() < l || h > r) {
      flag = 0;
      break;
    }

    int dn = max(l-h, 0);
    while (dn--) {
      int idx = *midx.begin(); midx.erase(idx);
      a[idx] = 1;
      h++;
    }
    dn = max((int)midx.size()+h-r, 0);
    while (dn--) {
      int idx = *midx.begin(); midx.erase(idx);
      a[idx] = 0;
    }

  }
  if (flag == 0) {
    cout<<"-1\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) cout<<"0 ";
    else cout<<a[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
