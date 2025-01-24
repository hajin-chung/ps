#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  cout<<"YES\n";
  if (n == 1 && k == 1) {
    cout<<"0\n";
    return 0;
  }
  if ((1<<n) == k) {
    for (int i = 0; i < (1<<n); i++) cout<<i<<" ";
    cout<<"\n";
    return 0;
  }
  for (int i = 0; i <= 12; i++)
    if (k&(1<<i))
      for (int j = 1<<i; j < (1<<(i+1)); j++)
        cout<<j<<" ";
  cout<<"\n";
}
