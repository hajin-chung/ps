#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool f() {
  int n; ll px, py, qx, qy;
  cin>>n>>px>>py>>qx>>qy;
  vector<ll> a(n);
  for (auto &x: a) cin>>x;

  ll mn = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    if (mn - a[i] == 0 || mx - a[i] == 0) mn = 0;
    else if (mn - a[i] < 0 && mx - a[i] > 0) mn = 0;
    else mn = min(abs(mn-a[i]), abs(mx-a[i]));
    mx = mx+a[i];
  }

  ll dx = px-qx, dy = py-qy;
  dx *= dx; dy *= dy;
  mn *= mn; mx *= mx;
  ll d = dx+dy;

  return mn <= d && d <= mx;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<(f()?"Yes":"No")<<"\n";
}
