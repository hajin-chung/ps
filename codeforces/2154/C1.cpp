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
 ans = INF;
  if (ei != -1) {
    ans = 1;
  } else {
    vector<bool> mults(N+1);
    for (int i = 0; i < n; i++)
      if (a[i] != 1 && mults[a[i]] == 0)
        for (int j = a[i]; j < N; j += a[i])
          mults[j] = 1;
    ans = 2;
    for (int i = 0; i < n; i++)
      if (a[i] != 1 && mults[a[i]+1])
        ans = 1;
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; cin>>t;
  while(t--) f();
}
