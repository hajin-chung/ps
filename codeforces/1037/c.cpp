#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];

bool f() {
  int n, k; cin>>n>>k;
  for (int i = 0; i < n; i++) cin>>a[i];
  int s = a[k-1], si;
  sort(a, a+n);
  for (int i = 0; i < n; i++)
    if (a[i] == s) {
      si = i;
      break;
    }

  int t = 0, curr = s;
  for (int i = si+1; i < n; i++) {
    int next = a[i];
    t += next - curr;
    if (t > curr) return false;
    curr = next;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<(f()?"YES":"NO")<<"\n";
}
