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

bool ask(int i, int x) {
  cout<<"? "<<i<<" "<<x<<"\n";
  cout.flush();
  int b; cin>>b;
  return b;
}

void f() {
  int n; cin>>n;
  vector<int> a;
  for (int i = 1; i <= n-1; i++) a.push_back(i);
  int round = 0, x = 0;
  while (sz(a)) {
    vector<int> o, e; 
    for (auto i : a) {
      if (ask(i, (1<<(round)))) o.push_back(i);
      else e.push_back(i);
    }
    if (sz(o) < sz(e) || (sz(o) == sz(e) && x == 0)) {
      x += (1<<round);
      a = o;
    } else a = e;
    round++;
  }
  if (x == 0) x = (1<<round);
  cout<<"! "<<x<<"\n";
  cout.flush();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
