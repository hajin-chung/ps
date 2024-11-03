#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
int n;
vector<pll> a;
vector<ll> bit;

void update(int idx) {
  while (idx <= n) {
    bit[idx]++;
    idx += idx&-idx;
  }
}

ll sum(int idx) {
  ll ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx&-idx;
  }
  return ret;
}

ll query(ll idx) {
  return sum(n) - sum(idx);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n+1); bit.resize(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].fi;
    a[i].se = i;
  }
  sort(a.begin()+1, a.end());

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += query(a[i].se); 
    update(a[i].se);
  }
  cout << sum << "\n";
}
