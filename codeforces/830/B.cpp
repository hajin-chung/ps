#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, i;
    int mn = 0;
    char x;
    scanf("%d ", &n);    
    vector<int> a(n+2, 0);
    for(i=1; i<=n; i++) {
      scanf("%c", &x);
      a[i] = x-'0';
    }
    for(i=1; i<n; i++) {
      if (a[i] == (mn+1)%2 && a[i+1] == mn%2) {
        mn++;
      } 
    }
    printf("%d\n", mn);
  }
}