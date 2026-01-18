#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

const uint64_t INF = 1LL<<60;
const int N = 2e5;
int prime[N+1];

void pre() {
  for (uint64_t i = 2; i <= N; i++)
    if (prime[i] == 0) {
      prime[i] = i;
      for (uint64_t j = i*i; j <= N; j+=i)
        prime[j] = i;
    }
}

void f() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x : a) cin>>x;
  vector<uint64_t> b(n); for (auto &x : b) cin>>x;
  vector<int> cnt(N+1); 
  for (auto x : a) cnt[x]++;
  for (int i = 2; i <= N; i++)
    if (prime[i] == i) {
      int cocnt = 0;
      for (int j = i; j <= N; j+=i)
        cocnt += cnt[j];
      if (cocnt >= 2) {
        cout<<"0\n";
        return;
      }
    }

  int ei = -1;
  for (int i = 0; i < n; i++)
    if (a[i]%2 == 0)
      ei = i;

  uint64_t ans = INF;
  if (ei != -1) {
    uint64_t mnob = INF;
    vector<int> divs;
    for (int i = 0; i < n; i++)
      if (a[i]%2) {
        mnob = min(mnob, b[i]);
        int x = a[i];
        while (x > 1) {
          divs.push_back(prime[x]);
          x /= prime[x];
        }
      }
    ans = mnob;
    for (auto div : divs)
      ans = min(ans, b[ei]*(div-a[ei]%div));
  } else {
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
        if (a[i] == 1 && a[j] == 1) continue;
        if (a[i] == 1) ans = min(ans, b[i]*(prime[a[j]]-1));
        else if (a[j] == 1) ans = min(ans, b[j]*(prime[a[i]]-1));
        else ans = min({ans, b[i]*(a[j]-a[i]%a[j]), b[j]*(a[i]-a[j]%a[i])});
      }
    sort(all(b));
    ans = min(ans, b[0]+b[1]);
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; cin>>t;
  while(t--) f();
}
