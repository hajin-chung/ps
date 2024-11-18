#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
struct Line { // f(x) = px+q, x >= s
  ll p, q; 
  double s; 
  ll f(ll x) { return p*x + q; }
  bool operator<(Line &l) { return p < l.p; }
}; 
multiset<Line> lines;

double intersect(Line a, Line b) {
  return (double)(b.q-a.q)/(a.p-b.p);
}

void insert(ll p, ll q) {
  Line f = {p, q, 0}; 
  auto it = lines.end(); it--;
  while (it != lines.begin()) {
    f.s = intersect(*it, f); /*f.s = intersect(lines.back(), f);*/
    if (it->s < f.s) break;
    lines.erase(it);
    it--;
  }
  lines.insert(f);
}

ll query(ll x) {
  Line tmp;
  tmp.s = x;
  /*int l = 0, r = lines.size()-1;*/
  /*while (l<r) {*/
  /*  int m = (l+r)>>1;*/
  /*  if (x < lines[m].s) r = m;*/
  /*  else l = m+1;*/
  /*} */
  /*if (l > 0 && x < lines[l].s) return lines[l-1].f(x);*/
  /*return lines[l].f(x);*/
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n; n--;
  vector<ll> s(n+1);
  for (int i = 1; i <= n; i++) {
    ll x; cin>>x;
    s[i] = s[i-1]+x;
  }
  vector<ll> p(n), q(n);
  for (int i = 0; i < n; i++)
    cin>>q[i]>>p[i];
  ll dp = 0;
  for (int i = 1; i <= n; i++) {
    insert(p[i-1], -s[i-1]*p[i-1]+q[i-1]+dp);
    dp = query(s[i]);
    cout << dp << endl;
  }
  cout<<dp<<"\n";
}
