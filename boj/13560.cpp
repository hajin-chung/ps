#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    int x; cin>>x;
    sum += x;
    if (x == n-1) cnt++;
  }
  if (sum != n*(n-1)/2 || cnt > 1) cout<<"-1\n";
  else cout<<"1\n";
} 
