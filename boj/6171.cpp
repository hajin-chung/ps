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
int n;
vector<pll> lands, tmp;
vector<Line> lines;

double intersect(Line a, Line b) {
  return (double)(b.q-a.q)/(a.p-b.p);
}

void insert(ll p, ll q) {
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
  cin>>n; tmp.resize(n);
  for (auto &[w, h] : tmp) cin>>w>>h;
  sort(all(tmp));
  for (int i = 0; i < n; i++) {
    while (
      !lands.empty()
      && lands.back().fi <= tmp[i].fi && lands.back().se <= tmp[i].se
    ) lands.pop_back();
    lands.push_back(tmp[i]);
  }
  ll dp = lands[0].fi*lands[0].se;
  for (int i = 1; i < lands.size(); i++) {
    insert(lands[i].se, dp);
    dp = query(lands[i].fi);
  }
  cout<<dp<<"\n";
}
