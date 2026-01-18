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
  int n; cin>>n;
  string s; cin>>s;
  int ocnt = 0;
  for (int i = 0; i < n; i++)
    ocnt += s[i] == '1';
  int cnt = 0;
  for (int i = 0; i < ocnt; i++)
    if (s[n-i-1] == '0')
      cnt++;
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
