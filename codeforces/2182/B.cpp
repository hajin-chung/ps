#include <bits/stdc++.h>
using namespace std;

int chk(int a, int b) {
  for (int i = 0; ; i++) {
    if (i % 2 == 1) {
      if (a < (1<<i)) return i;
      a -= (1<<i);
    } else {
      if (b < (1<<i)) return i;
      b -= (1<<i);
    }
  }
}

int f() {
  int a, b;
  cin>>a>>b;
  return max(chk(a, b), chk(b, a));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while (t--) cout<<f()<<"\n";
}
