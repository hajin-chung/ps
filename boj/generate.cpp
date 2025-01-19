#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 20;
  cout<<n<<"\n";
  for (int i = 0; i < n; i++)
    cout<<1<<" "<<i+20<<"\n";
  int q = n*(n-1)/2;
  cout<<q<<"\n";
  for (int i = 1; i <= n; i++)
    for (int j = i+1; j <= n; j++)
      cout<<i<<" "<<j<<"\n";
}
