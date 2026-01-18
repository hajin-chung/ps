#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef long long ll;
const int N = 8e4;
const int M = 1e5;

void f() {
  int n; cin>>n;
  vector<int> a(n);
  vector<int> c(M+1), up(M+1);
  vector<ll> g(M+1);
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    c[a[i]]++;
  }
  int sum = 0;
  for (int i = M; i >= 1; i--) {
    up[i] = sum;
    sum += c[i];
  }
  for (int i = M; i >= 1; i--) {
    int cnt = 0;
    ll h = 0;
    for (int j = i; j <= M; j += i) {
      cnt += c[i];
      if (j > i) h += g[j];
    }
    g[i] = (ll)cnt*(cnt-1)/2 - h; 
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
