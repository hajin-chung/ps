#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const ll MOD = 998244353;
const int N = 2e5;
int rowc[N+1], colc[N+1];

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, m, q; ll k; cin>>n>>m>>k>>q;
  vector<pair<int, int>> rc(q);
  for (int i = 0; i < q; i++) {
    int r, c; cin>>r>>c;
    rc[i] = {r, c};
    rowc[r]++; colc[c]++;
  }
  bool rowm = 1, colm = 1;
  for (int i = 1; i <= n; i++)
    if (rowc[i] == 0)
      rowm = 0;
  for (int i = 1; i <= m; i++)
    if (colc[i] == 0)
      colm = 0;
  int cnt = q;
  for (int i = 0; i < q; i++) {
    auto [r, c] = rc[i];
    rowc[r]--;
    colc[c]--;
    if (rowc[r] == 0) rowm = 0;
    if (colc[c] == 0) colm = 0;
    if (rowc[r] && colc[c] || rowm || colm) cnt--;
  }
  ll ans = 1;
  while (cnt--)
    ans = (ans*k)%MOD; 
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
