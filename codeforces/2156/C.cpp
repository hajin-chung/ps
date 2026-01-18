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

const int N = 2e5;

void f() {
  int n, k; cin>>n>>k;
  vector<int> a(n+1, 0), psum(n+1, 0), cnt(n+1, 0);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    psum[i] = cnt[i] + psum[i-1];
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    int toe = psum[i-1];
    toe += psum[min(n, 2*i-1)]-psum[i];
    toe += psum[min(n, 3*i-1)]-psum[min(n, 2*i)];
    toe += psum[min(n, 4*i-1)]-psum[min(n, 3*i)];
    if (toe <= k) ans = i;

  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
