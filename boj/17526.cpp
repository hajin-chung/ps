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
  ll f(ll x) const { return p*x + q; }
}; 
deque<Line> lines;

double intersect(Line a, Line b) {
  return (double)(b.q-a.q)/(a.p-b.p);
}

void insert(ll p, ll q) {
  Line f = {p, q, 0}; 
  while (lines.size() >= 2) {
    Line first = lines.back();
    Line second = lines[lines.size()-2];
    double i1 = intersect(second, first);
    double i2 = intersect(first, f);
    if (i1 >= i2) lines.pop_back();
    else break;
  }
  if (!lines.empty()) f.s = intersect(lines.back(), f);
  lines.push_back(f);
}

ll query(ll x) {
  while (lines.size() >= 2 && lines[0].f(x) >= lines[1].f(x))
    lines.pop_front();
  return lines.front().f(x);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n; n--;
  vector<tuple<ll,ll,ll>> a(n+1);
  for (int i = 1; i <= n; i++) cin>>get<2>(a[i]);
  vector<ll> p(n), q(n);
  for (int i = 1; i <= n; i++) cin>>get<1>(a[i])>>get<0>(a[i]);
  sort(all(a));
  ll dp = 0, s;
  for (int i = 1; i <= n; i++) {
    auto [p, q, x] = a[i];
    insert(p, -s*p+q+dp);
    s += x;
    dp = query(s);
  }
  cout<<dp<<"\n";
}
