#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vector<int> a(n), s(n, 0);
  int sum = 0;
  for (auto &i : a) {
    cin>>i;
    sum += i;
  }
  if (sum != n*(n-1)/2) {
    cout<<"-1\n";
    return 0;
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < n; i++) {
    int win = a[i]-s[i], k = n-win;
    if (k <= i || k < 0 || k > n) {
      cout<<"-1\n";
      return 0;
    }
    for (int j = i+1; j < k; j++) s[j]++;
  }
  cout<<"1\n";
} 
