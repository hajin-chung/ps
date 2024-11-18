#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
struct Line { // f(x) = px+q, x >= s
  ll p, q; 
  double s; 
  ll f(ll x) { return p*x + q; }
}; 
ll a, b, c;
int n;
vector<Line> lines;
int lp;

double intersect(Line a, Line b) {
  return (double)(b.q-a.q)/(a.p-b.p);
}

void insert(ll p, ll q) {
  Line f = {p, q, 0}; 
  cout << p << " * x + " << q << "\n";
  while (!lines.empty()) {
    f.s = intersect(lines.back(), f);
    if (lines.back().s < f.s) break;
    lines.pop_back();
  }
  lines.push_back(f);
}

int query(ll x) {
  int l = 0, r = lines.size()-1;
  while (l<r) {
    int m = (l+r)>>1;
    if (x < lines[m].s) r = m;
    else l = m+1;
  } 
  return lines[l].f(x);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>a>>b>>c;
  ll s = 0, x, dp = 0;
  for (int i = 1; i <= n; i++) {
    insert(-2*a*s, a*s*s-b*s+dp);
    cin>>x;
    s += x;
    dp = query(s) + a*s*s + b*s + c;
    cout << dp << " " << s << " " << a*s*s + b*s + c << "\n";
  }
  for (auto line : lines) cout << line.p << " * x + " << line.q << "  x >= " << line.s <<  "\n";
  cout<<dp<<"\n";
}
