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
  }
  cout<<dp<<"\n";
}
