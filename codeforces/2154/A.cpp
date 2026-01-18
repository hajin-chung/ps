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

void f() {
  int n, k; cin>>n>>k;
  string s; cin>>s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') continue;
    bool flag = 0;
    for (int j = max(0, i-k+1); j < i; j++)
      if (s[j] == '1')
        flag = 1;
    if (!flag) cnt++;
  }
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
