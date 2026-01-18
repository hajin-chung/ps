#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 1000;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x : a) cin>>x;
  vector<bool> c(N+1);
  int cnt = 0;
  for (auto x: a)
    if (!c[x]) {
      cnt++;
      c[x] = 1;
    }
  while (c[cnt] == 0) {
    c[cnt] = 1;
    cnt++;
  }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
