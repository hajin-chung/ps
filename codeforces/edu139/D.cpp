#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#define MAX 10000000
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

vector<int> s(MAX+1, 0);

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);

  if (gcd(a, b) != 1) {
    printf("0\n");
    return;
  }

  if (a%2 == b%2) {
    printf("1\n");
    return;
  }

  int c = abs(a-b);

  if (c == 1) {
    printf("-1\n");
    return;
  }

  vector<int> d;
  if (s[c] == 1) d.push_back(c);
  while(s[c] != 1) {
    d.push_back(s[c]);
    c /= s[c];
  }

  int mx = max(a, b);
  int mn = MAX;

  int len = d.size();
  for(int i=0 ; i<len ; i++) {
    int t = d[i] * (int)(mx/d[i] + 1);
    if (mn > t-mx)  {
      mn = t-mx;
    }
  }
  if (len == 0) {
    mn = c * (mx/c + 1) - mx;
  }

  printf("%d\n", mn);
}

int main() {
  int t;
  for(ll i=2 ; i<=MAX; i++) {
    if (s[i] == 0) {
      s[i] = 1;
      for(ll j = i*i ;j<=MAX; j+=i) s[j] = i;
    }
  }
  scanf("%d", &t);
  while(t--) solve();
}