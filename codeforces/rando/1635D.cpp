#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const ll MOD = 1e9+7;
const int N = 2e5;
ll cnt[N+5];

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

int bl(uint64_t x) {
  int cnt = 0;
  for (; x; x>>=1) cnt++;
  return cnt;
}

void solve() {
  int n, p; cin>>n>>p;
  set<uint64_t> st;
  vector<uint64_t> a(n); 
  for (auto &x: a) {
    cin>>x;
    st.insert(x);
  }

  for (auto x : a) {
    int t = x;
    while (x) {
      if (x%4 == 0) x>>=2;
      else if (x&1) x>>=1;
      else break;

      if (st.count(x)) {
        st.erase(t);
        break;
      }
    }
  }

  for (auto x : st) cnt[bl(x)]++;
  cnt[1] += cnt[0];
  for (int i = 2; i <= p; i++)
    cnt[i] = (cnt[i] + cnt[i-1]+cnt[i-2])%MOD;

  int64_t sum = 0;
  for (int i = 0; i <= p; i++)
    sum = (sum + cnt[i])%MOD;
  cout<<sum<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
