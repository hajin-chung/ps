#include <stdio.h>
#include <vector>
using namespace std;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, i, x;
    int totalGCD = 1, minIdx = 0;
    scanf("%d", &n);
    vector<int> a(n+1, 0);
    for(i=1; i<=n; i++) {
      scanf("%d", &a[i]);
      if (i == 1) totalGCD = a[i];
      else totalGCD = gcd(totalGCD, a[i]);
    }

    for(i=1; i<=n; i++) {
      if (gcd(totalGCD, gcd(a[i], i)) == 1) minIdx = n-i+1;
    }

    if (totalGCD == 1) printf("0\n");
    else if (minIdx < 3) printf("%d\n", minIdx);
    else printf("3\n");
  }
}