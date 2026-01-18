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
  int n;
  int cnt = 0;
  char c;
  scanf("%d ", &n);
  while(n--) {
    scanf("%c", &c);
    if (c == 'Q') cnt++;
    else if (c == 'A' && cnt > 0) cnt --;
  }

  if (cnt > 0) printf("NO\n");
  else printf("YES\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}