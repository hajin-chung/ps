#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const int N = 2e5;
set<pii> si;
int ft[N+5];

void pmax(int &x, int v) { x = max(x, v); }
void pmin(int &x, int v) { x = min(x, v); }

// check if therse point p which px >= qx and py >= qy
class PF {
  map<int, int> mp;

public:
  void add(pii p) {
    auto it = mp.lower_bound(p.fi);
    if (it != mp.end() && it->se >= p.se) return;

    while (it != mp.begin() && prev(it)->se <= p.se)
      it = mp.erase(prev(it));
    mp[p.fi] = p.se;

    if (p.se > 0) return;
    // cout<<mp.size()<<endl;
    // for (auto p : mp) cout<<p.fi<<" "<<p.se<<endl;
  }

  bool query(pii p) {
    auto it = mp.lower_bound(p.fi);
    if (it == mp.end()) return false;
    return it->se >= p.se;
  }
};

void solve() {
  int n, q; cin>>n>>q;
  PF pf, of;
  for (int i = 0; i < q; i++) {
    int t; cin>>t;
    if (t == 1) {
      int idx; cin>>idx;
      int l = idx, r = idx;
      auto it = si.upper_bound({idx, 2*N});
      if (it != si.begin() && prev(it)->se == idx-1) l = prev(it)->fi; 
      it = si.lower_bound({idx, -1});
      if (it != si.end() && it->fi == idx+1) r = it->se;
      if (pf.query({-idx, idx})) cout<<"NO\n";
      else if (of.query({l, -r})) cout<<"YES\n";
      else cout<<"N/A\n";
    } else {
      int l, r, x; cin>>l>>r>>x;
      if (x == 0) {
        pf.add({-l, r});
        auto it = si.lower_bound({l+1, -1});
        if (it != si.begin() && prev(it)->se >= l-1) {
          it = prev(it);
          l = min(l, it->fi);
          r = max(r, it->se);
          si.erase(it);
        }
        it = si.lower_bound({l, -1});
        while (it != si.end() && it->fi <= r+1) {
          pmax(r, it->se);
          it = si.erase(it);
        }
        si.insert({l, r});
      } else {
        of.add({l, -r});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
