#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string tmp, s = "";
  cin >> tmp;
  for (int i = 0; i < tmp.size(); i++) {
    s += "#";
    s += tmp[i];
  }
  s += "#";

  vector<int> p(s.size());
  int r, c;
  r = c = 0;
  for (int i = 1; i < s.size(); i++) {
    if (r < i) p[i] = 0;
    else p[i] = min(p[2*c-i], r-i);
    while (i-p[i] >= 0 && i+p[i] < s.size() && s[i-p[i]] == s[i+p[i]]) p[i]++;
    if (r < i + p[i]) {
      r = i+p[i];
      c = i;
    }
  }

  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ll pi = (ll)p[i] - 1;
    if (pi <= 0) continue;
    if (pi % 2 == 0) ans += pi/2;
    else ans += pi/2+1;
  }
  cout << ans << "\n";
}
