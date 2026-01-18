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

const uint64_t MOD = 676767677;

int fill(vector<int> &a, bool start) {
  vector<bool> b;
  b.push_back(start);
  for (int i = 1; i < a.size(); i++) {
    if (a[i] == a[i-1]) b.push_back(!b[i-1]);
    else if (a[i] == a[i-1]+1) {
      if (b[i-1] == 0) return 0;
      else b.push_back(1);
    } else if (a[i] == a[i-1]-1) {
      if (b[i-1] == 1) return 0;
      else b.push_back(0);
    } else {
      return 0;
    }
  }

  int lr = 0, rl = 0;
  for (int i = 0; i < a.size(); i++)
    if (!b[i])
      rl++;
  for (int i = 0; i < a.size(); i++) {
    if (!b[i]) rl--;
    if (a[i] != lr + rl + 1) return 0;
    if (b[i]) lr++;
  }
  return 1;
}

void f() {
  int n; cin>>n;
  vector<int> a(n); for (auto &x: a) cin>>x;
  int cnt = fill(a, 0) + fill(a, 1);
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
