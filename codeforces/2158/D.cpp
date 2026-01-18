#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

vector<pii> steps;

void dbg(string label, vector<bool> &a) {
  cout<<label<<": ";
  for (auto b: a) cout<<b;
  cout<<"\n";
}

void flip(vector<bool> &a, int l, int r) {
  steps.push_back({l, r});
  for (int i = l; i <= r; i++) a[i] = !a[i];
}

void make_zero(vector<bool> &a) {
  steps.resize(0);
  int n = a.size();
  for (int i = 1; i < n; i++) {
    if (a[i-1] && a[i]) flip(a, i-1, i);
    if (i >= 2 && a[i-2] && !a[i-1] && a[i]) flip(a, i-2, i);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) continue;
    if (i >= 2 && !a[i-2] && !a[i-1] && a[i]) {
      flip(a, i-2, i-1);
      flip(a, i-2, i);
    }
    if (n-i-1 >= 2 && a[i] && !a[i+1] && !a[i+2]) {
      flip(a, i+1, i+2);
      flip(a, i, i+2);
    }
  }
}

void solve() {
  int n; cin>>n;
  vector<bool> a(n), b(n);
  for (int i = 0; i < n; i++) {
    char x; cin>>x; a[i] = x == '1';
  }
  for (int i = 0; i < n; i++) {
    char x; cin>>x; b[i] = x == '1';
  }
  make_zero(a);
  vector<pii> as(steps);
  make_zero(b);
  vector<pii> bs(steps);
  reverse(all(bs));
  cout<<as.size()+bs.size()<<"\n";
  for (auto [l, r] : as) cout<<l+1<<" "<<r+1<<"\n";
  for (auto [l, r] : bs) cout<<l+1<<" "<<r+1<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) solve();
}
