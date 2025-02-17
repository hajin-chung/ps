#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;

int ccw(pii a, pii b, pii c) {
  ll r = (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi); 
  return r < 0 ? -1 : r > 0;
}

int intersect(pii s1, pii e1, pii s2, pii e2) {
  int c1 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
  int c2 = ccw(s2, e2, s1) * ccw(s2, e2, e1);
  if (c1 == 0 && c2 == 0) return s2 <= e1 && s1 <= e2;
  return c1 <= 0 && c2 <= 0; 
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pii s1, e1, s2, e2;
  cin>>s1.fi>>s1.se>>e1.fi>>e1.se>>s2.fi>>s2.se>>e2.fi>>e2.se;
  if (s1 > e1) swap(s1, e1);
  if (s2 > e2) swap(s2, e2);
  int inter =  intersect(s1, e1, s2, e2);
  if (inter == 0) {
    cout<<"0\n";
    return 0;
  }
  double x, y;
  ll dx1 = e1.fi-s1.fi;
  ll dy1 = e1.se-s1.se;
  ll dx2 = e2.fi-s2.fi;
  ll dy2 = e2.se-s2.se;
  ll a1 = -dy1, b1 = dx1, k1 = dx1*s1.se-dy1*s1.fi;
  ll a2 = -dy2, b2 = dx2, k2 = dx2*s2.se-dy2*s2.fi;
  ll D = a1*b2-b1*a2, Dx = k1*b2-k2*b1, Dy = a1*k2-a2*k1;
  if (D == 0) {
    ll oxs = max(min(s1.fi, e1.fi), min(s2.fi, e2.fi));
    ll oxe = min(max(s1.fi, e1.fi), max(s2.fi, e2.fi));
    ll oys = max(min(s1.se, e1.se), min(s2.se, e2.se));
    ll oye = min(max(s1.se, e1.se), max(s2.se, e2.se));
    if (oxs < oxe && oys < oye) cout<<"1\n";
    else if (s1 == e2) cout<<"1\n"<<s1.fi<<" "<<s1.se<<"\n";
    else if (s2 == e1) cout<<"1\n"<<s2.fi<<" "<<s2.se<<"\n";
    else if (s1 == s2) cout<<"1\n"<<s1.fi<<" "<<s1.se<<"\n";
    else if (e1 == e2) cout<<"1\n"<<e1.fi<<" "<<e1.se<<"\n";
    return 0;
  }
  x = (double)Dx/D, y = (double)Dy/D;
  cout<<fixed<<setprecision(10);
  cout<<"1\n"<<x<<" "<<y<<"\n";
}
