#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

int f() {
  int n, m; ll k; cin>>n>>m>>k;
  vector<int> a(m);
  for (auto &x: a) cin>>x;
  vector<pil> p(n);
  for (int i = 0; i < n; i++) {
    int x; ll y, z; cin>>x>>y>>z;
    k -= y; z -= y;
    p[i] = {x, z};
  }

  sort(all(a));
  sort(all(p));
  int ans = 0;
  multiset<pli> ss;
  int pi = 0;
  auto iter = a.begin();
  for (auto z: a) {
    for (; pi < n && p[pi].fi <= z; pi++)
      ss.insert({p[pi].se, p[pi].fi});
    if (!ss.empty()) {
      ss.erase(ss.find(*ss.rbegin()));
      ans++;
    }
  }
  for (; pi < n; pi++) ss.insert({p[pi].se, p[pi].fi});

  vector<ll> left;
  for (auto [z, x] : ss) left.push_back(z);
  sort(all(left));
  for (auto z : left)
    if (k - z >= 0) {
      k -= z;
      ans++;
    }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}

// 3 4 4
// 1 1 2 2
// 3 3
// 4 2
// 3 2
//
// 2 1 1
// 4
// 3 100
// 2 20
// 2 1
//
// 2 1 2
// 4
// 5 2
// 4 1
//
// 상자를 먼저 주고 그다음에 코인을 뿌렸을 때 아쉬울 경우가 있을까? 
// 상자를 아껴두고 코인을 준 후 그 상자를 나중에 쓸 경우가 있을까?
// 반대로 코인을 먼저 썼을 때 아쉬울 겨우
// 상자를 쓰긴 할텐데 xi <= aj 인것중에 z가 가장 큰거
