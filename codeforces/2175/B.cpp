#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, l, r; cin>>n>>l>>r;
  vector<int> pre(n+1);
  for (int i = 1; i <= n; i++) {
    if (i == r) pre[i] = l-1;
    else pre[i] = i;
  }
  for (int i = 1; i <= n; i++)
    cout<<(pre[i]^pre[i-1])<<" ";
  cout<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
