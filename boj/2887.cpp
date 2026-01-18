#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii; 
typedef pair<ll, int> pli; 
typedef pair<ll, pii> plii; 

vector<pli> ex, ey, ez;
priority_queue<plii, vector<plii>, greater<plii>> e;
vector<int> parent;
int n;

int get_parent(int a) {
  if (parent[a] == a) return a;
  else return parent[a] = get_parent(parent[a]);
}

int main() {
  int i;
  ll ans = 0, x, y, z;

  scanf("%d", &n);
  parent.resize(n);
  for (i = 0; i < n; i++) {
    parent[i] = i;
    scanf("%lld %lld %lld", &x, &y, &z);
    ex.push_back({x, i});
    ey.push_back({y, i});
    ez.push_back({z, i});
  }

  sort(ex.begin(), ex.end());
  sort(ey.begin(), ey.end());
  sort(ez.begin(), ez.end());

  for (i = 1; i < n; i++) {
    e.push({abs(ex[i].fi - ex[i-1].fi), {ex[i].se, ex[i-1].se}});
    e.push({abs(ey[i].fi - ey[i-1].fi), {ey[i].se, ey[i-1].se}});
    e.push({abs(ez[i].fi - ez[i-1].fi), {ez[i].se, ez[i-1].se}});
  }

  while (!e.empty()) {
    plii p = e.top(); 
    e.pop();
    int pa = get_parent(p.se.fi);
    int pb = get_parent(p.se.se);
    if (pa != pb) {
      ans += p.fi;
      parent[pb] = pa;
    }
  }

  printf("%lld\n", ans);
}
