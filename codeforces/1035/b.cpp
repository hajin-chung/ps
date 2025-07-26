#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool f() {
  int n; ll px, py, qx, qy;
  cin>>n>>px>>py>>qx>>qy;
  vector<ll> a(n);
  for (auto &x: a) cin>>x;

  ll mn = a[0], mx = a[0];
  for (int i = 1; i < n; i++) {
    mn = min(abs(mn-a[i]), abs(mx-a[i]));
    mx = mx+a[i];
  }

  ll dx = px-qx, dy = py-qy;
  dx *= dx; dy *= dy;
  mn *= mn; mx *= mx;

  return mn <= dx+dy && dx+dy <= mx;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<(f()?"Yes":"No")<<"\n";
}
