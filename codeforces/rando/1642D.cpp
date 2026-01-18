#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void dbg(string label, deque<int> &dq) {
  cout<<label<<": ";
  int n = sz(dq);
  for (int i = 0; i < n; i++) {
    int x = dq.front();
    dq.pop_front();
    cout<<x<<" ";
    dq.push_back(x);
  }
  cout<<endl;
}

bool check(vector<int> &a) {
  set<int> st;
  for (auto x: a) {
    if (st.count(x)) st.erase(x);
    else st.insert(x);
  }
  return st.size() == 0;
}

void solve() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x: a) cin>>x;
  if (!check(a)) {
    cout<<"-1\n";
    return;
  }

  deque<int> dq(all(a)), past;
  vector<pii> ops;
  vector<int> ans;
  int st = -1, idx = 1;
  while (!dq.empty()) {
    int ff = dq.front(); dq.pop_front();
    past.push_back(ff);
    if (st == -1) {
      st = ff;
    } else if (st == ff) {
      int psz = sz(past);
      ans.push_back(2*(psz-1));
      past.pop_back(); past.pop_front();
      vector<int> t;
      for (int i = 0; !past.empty(); i++, past.pop_front()) {
        ops.push_back({i+idx, past.front()});
        dq.push_front(past.front());
      }
      idx += psz-2;
      st = -1;
    }  
    idx++;
  }

  cout<<sz(ops)<<"\n";
  for (auto [idx, v] : ops) cout<<idx<<" "<<v<<"\n";
  cout<<sz(ans)<<"\n";
  for (auto s: ans) cout<<s<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
