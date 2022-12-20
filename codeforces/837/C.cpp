#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

void solve() {
  int n, i, j;
  scanf("%d", &n);

  vector<int> a(n+1);
  for(i=1; i<=n ; i++) 
    scanf("%d", &a[i]);

  int size = 40000;
  vector<int> prime, filter(size+1, 0);
  for(i=2 ; i<=size ; i++) {
    if (filter[i] == 0) {
      prime.push_back(i);
      for(j=i*i ; j<=size ; j+=i) {
        filter[j] = 1;
      }
    }
  }

  int len = prime.size();
  for(i=0 ; i<len ; i++) {
    int d = prime[i];
    int cnt = 0;
    for(j=1 ; j <= n ; j++) {
      if (a[j] % d == 0) cnt ++;
    }
    if (cnt >= 2) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}