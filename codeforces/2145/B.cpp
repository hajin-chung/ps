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
  int tcnt = 0, bcnt = 0, ecnt = 0;
  for (auto c : s) {
    if (c == '0') tcnt++;
    if (c == '1') bcnt++;
    if (c == '2') ecnt++;
  }
  string ret = "";
  for (int i = 1; i <= tcnt; i++) ret.push_back('-');
  int left = n-tcnt-bcnt;
  if (left <= ecnt) {
    for (int i = 1; i <= left; i++)
      ret.push_back('-');
  } else {
    if (left <= 2*ecnt) {
      for (int i = 1; i <= left; i++) ret.push_back('?');
    } else {
      for (int i = 1; i <= ecnt; i++) ret.push_back('?');
      for (int i = 1; i <= left-2*ecnt; i++) ret.push_back('+');
      for (int i = 1; i <= ecnt; i++) ret.push_back('?');
    }
  }
  for (int i = 1; i <= bcnt; i++) ret.push_back('-');
  cout<<ret<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
