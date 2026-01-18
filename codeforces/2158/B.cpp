#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 2e5;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n; cin>>n;
  vector<int> cnt(2*n+1);
  for (int i = 0; i < 2*n; i++) {
    int x; cin>>x;
    cnt[x]++;
  }
  int fcnt = 0, gcnt = 0, ocnt = 0;
  for (int i = 1; i <= 2*n; i++) {
    if (cnt[i] == 0) continue;
    if (cnt[i]%2 == 1) ocnt++;
    else if (cnt[i]%4 == 0) fcnt++;
    else if (cnt[i]%4 == 2) gcnt++;
  }
  int ans = ocnt + 2*gcnt;
  ans += floor(fcnt/2)*4; fcnt %= 2;
  if (ocnt >= 2 && fcnt == 1) ans += 2;
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
