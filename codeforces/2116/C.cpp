#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 5000;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void f() {
  int n; cin>>n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];

  int g = a[1];
  for (int i = 2; i <= n; i++) g = gcd(g, a[i]);

  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt+=(a[i]==g);

  if (cnt) {
    cout<<n-cnt<<"\n";
    return;
  }

  vector<int> dp(N+1, N+1);
  for (int i = 1; i <= n; i++) {
    dp[a[i]] = 1;
    vector<int> t(dp);
    for (int j = 1; j <= N; j++) {
      int gg = gcd(j, a[i]);
      if (t[gg] > t[j]+1) 
        dp[gg] = min(dp[gg], t[j]+1);
    }
  }
  cout<<n-1+(dp[g]-1)<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
