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
}; 
vector<Line> lines;
int n;
vector<ll> a, b, dp;

double intersect(Line a, Line b) {
  return (double)(b.q-a.q)/(a.p-b.p);
}

void insert(ll p, ll q) {
  cout << "y = " << p << " * x + " << q << "\n";
  Line f = {p, q, 0}; 
  while (!lines.empty()) {
    f.s = intersect(lines.back(), f);
    if (lines.back().s < f.s) break;
    lines.pop_back();
  }
  lines.push_back(f);
}

ll query(ll x) {
  int l = 0, r = lines.size()-1;
  while (l<r) {
    int m = (l+r)>>1;
    if (x < lines[m].s) r = m;
    else l = m+1;
  } 
  if (l > 0 && x < lines[l].s) return lines[l-1].f(x);
  return lines[l].f(x);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  cin>>n; a.resize(n); b.resize(n);
  for (auto &ai : a) cin>>ai;
  for (auto &bi : b) cin>>bi;
  ll dp = 0;
  for (int i = 1; i < n; i++) {
    cout << dp <<"\n";
    insert(b[i-1], dp);
    dp = query(a[i]);
  }
  cout<<dp<<"\n";
}
