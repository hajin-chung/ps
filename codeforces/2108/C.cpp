#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin>>a[i];
  vector<int> b(1);
  b.push_back(a[1]);
  for (int i = 2; i <= n; i++)
    if (a[i] != a[i-1])
      b.push_back(a[i]);
  n = b.size()-1;
  if (n == 1 || n == 2) {
    cout<<"1\n";
    return;
  }
  int cnt = 0;
  if (b[1] > b[2]) cnt++;
  if (b[n] > b[n-1]) cnt++;
  for (int i = 2; i <= n-1; i++)
    if (b[i] > b[i-1] && b[i] > b[i+1])
      cnt++;
  cout<<cnt<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
