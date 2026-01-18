#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

void solve() {
  int n, i;
  int flag = 0;
  int cnt[26][26];
  char c, lc;
  scanf("%d ", &n);
  lc = -1;
  for(i=0 ; i<26 ; i++) for(int j=0 ; j<26 ; j++) cnt[i][j] = 0;

  for(i=1 ;i<=n ; i++) {
    scanf("%c", &c);
    if (i != 1) {
      if (cnt[lc-'a'][c-'a'] != 0 && i - cnt[lc-'a'][c-'a'] >= 2) flag = 1;
      else if(cnt[lc-'a'][c-'a'] == 0) cnt[lc-'a'][c-'a'] = i;
    }
    lc = c;
  }

  if (flag == 1) printf("YES\n");
  else printf("NO\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}