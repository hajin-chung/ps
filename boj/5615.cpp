#include <bits/stdc++.h>
using namespace std;

typedef uint32_t u32;
typedef uint64_t u64;
typedef __uint128_t u128;

u64 binpow(u64 a, u64 d, u64 n) {
  u64 ret = 1;
  a %= n;
  while (d) {
    if (d & 1) ret = (u128)ret*a%n;
    a = (u128)a*a%n;
    d>>=1;
  }
  return ret;
}

bool comptest(u64 n, u64 a, u64 d, int s) {
  u64 x = binpow(a, d, n);
  if (x == 1 || x == n-1) return false;
  for (int r = 1; r < s; r++) {
    x = (u128)x*x%n;
    if (x == n-1) return false;
  }
  return true;
}

bool mrtest(u64 n) {
  if (n < 2) return false;
  u64 d = n-1; 
  int s = 0;
  while ((d & 1) == 0) {
    s++;
    d>>=1;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (comptest(n, a, d, s)) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  int ans = 0;
  while (n--) {
    u64 x; cin>>x; 
    if (mrtest(2*x+1)) ans++;
  }
  cout<<ans<<"\n";
}
