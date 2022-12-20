#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, i;
  int flag[101], x, cnt = 0;
  scanf("%d", &n);
  for(i=1 ; i<=100;  i++) flag[i] = 0;
  for(i=1 ; i<=n ; i++) scanf("%d", &x), cnt += (int)(flag[x] == 0), flag[x] = 1;
  if (cnt == 2) printf("%d\n", n/2+1);
  else printf("%d\n", n);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}