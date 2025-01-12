#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin>>n;
  int sum = 0;
  vector<int> a(n);
  for (auto &i : a) {
    cin>>i; sum += i;
  }
  if (sum != n*(n-1)/2) return -1;
  sort(a.begin(), a.end());
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];  
    if (sum < i*(i+1)/2) return -1;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout<<solve()<<"\n";
} 
