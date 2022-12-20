#include <stdio.h>

typedef long long int ll;

ll pow2(ll n) {
  ll res = 1;
  while (n--) res *= 2;
  return res;
}

ll gcd(ll a,ll b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  ll ans = 1000000000; // test
  ll i;
  int r = 0;
  int n = 30;
  
  for(i=1; i<=n; i++) {
    printf("? %lld %lld\n", pow2(i) + r, pow2(i+1) + r); 
    fflush(stdout); // real
    ll x;
    scanf("%lld", &x); // real

    // x = gcd(ans+pow2(i)+r, ans+pow2(i+1)+r); // test
    // printf("gcd(%lld, %lld) = %lld\n", ans+(1LL<<i)+r, ans+(1LL<<i+1)+r, x); //test

    if (x != pow2(i)) {
      r = pow2(i-1) + r;
      // printf("dsafdsa\n"); //test
      // printf("%lld\n", 1LL<<(i-1)); //test
    }

    // printf("==============\n1<<i = %lld\nr = %lld\n===============\n", 1LL<<i, r); // test
  }
  printf("! %d\n", (int)pow2(n)-r);
  fflush(stdout); // real
}

int main() {
  int t;
  scanf("%d", &t); 
  while(t--) solve();
}