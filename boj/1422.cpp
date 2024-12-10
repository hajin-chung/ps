#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

bool comp(string &a, string &b) {
  return a+b>b+a;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin>>n>>m;
  vector<string> a(n);
  string mx = "";
  for (auto &ai : a) {
    cin>>ai;
    mx = max(mx, ai);
  }
  sort(all(a), comp);
  if (a[0] == mx) for (int i = 0; i < m-n; i++) cout<<mx;
  for (auto ai : a) cout<<ai;
  if (a[0] != mx) for (int i = 0; i < m-n; i++) cout<<mx;
  cout<<"\n";
}
