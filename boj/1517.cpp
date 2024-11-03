#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;
int n;
vector<pii> a;
vector<int> bit;

void update(int idx) {
  while (idx <= n) {
    bit[idx]++;
    idx += idx&-idx;
  }
}

int sum(int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += bit[idx];
    idx -= idx&-idx;
  }
  return ret;
}

int query(int idx) {
  return sum(n) - sum(idx);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; a.resize(n+1); bit.resize(n+1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].fi);
    a[i].se = i;
  }
  sort(all(a));

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (ll)query(a[i].se); 
    update(a[i].se);
  }
  cout << sum << "\n";
}
