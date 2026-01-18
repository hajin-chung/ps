#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1e9;

int f() {
  int cnt = 0;
  int n; cin>>n;
  int a[N]; for (int i = 0; i < n; i++) cin>>a[i];
  for (int i = n-2; i >= 0; i--) {
    for (int j = i+1; j < n; j++)
      if (a[j] < a[i]) {
        a[j] = INF;
        cnt++;
      }
   }
  return cnt;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t; cin>>t;
  while(t--) cout<<f()<<"\n";
}
