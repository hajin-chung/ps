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
  int n, i, cnt = 0;
  scanf("%d", &n);
  vector<int> a(n+1);
  for(i=1 ; i<=n;i++) {
    scanf("%d", &a[i]);
    if (a[i] != 0) cnt++;
  }

  if (cnt%2==1) {
    printf("-1\n");
    return;
  }

  vector<pii> ans;
  int last = -1;
  i = 1;
  while(i <= n) {
    if (a[i] != 0) {
      if (last != -1) {
        if (a[i] == a[last]) {
          ans.push_back({last, last});
          if (last+1 <= i-2) ans.push_back({last+1, i-2});
          ans.push_back({i-1, i});
        } else {
          ans.push_back({last, i-1});
          ans.push_back({i, i});
        }
        i++;
        last = -1;
      } else if (a[i] == a[i+1]) {
        ans.push_back({i, i+1});
        i+=2;
      } else if(a[i] != a[i+1] && a[i+1] != 0) {
        ans.push_back({i,i}), ans.push_back({i+1, i+1});
        i+=2;
      } else {
        last = i;
        i++;
      }
    } else {
      if (last == -1) 
        ans.push_back({i,i});
      i++;
    }
  }


  int len = ans.size();
  printf("%d\n", len);
  for(i=0 ; i<len ; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}