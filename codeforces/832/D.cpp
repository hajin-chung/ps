#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long int ll;

vector<int> a, p, last;
vector<ll> s;
map<int, int> odd, even;
int n, q;

int main() {
  int i, j;

  scanf("%d %d", &n, &q);
  a.resize(n+1);
  p.resize(n+5);
  s.resize(n+1);
  last.resize(n+1, -1); 
  for(i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    p[i] = p[i-1] ^ a[i];
    s[i] = (ll)s[i-1] + (ll)a[i];
    if (i & 1 == 1) {
      if (even.count(p[i])) last[i] = even[p[i]];
      odd[p[i]] = i;
    } else {
      if (odd.count(p[i])) last[i] = odd[p[i]];
      even[p[i]] = i;
    }
    // printf("%d ", p[i]);
  }
  // printf("\n");
  for(i=1; i<=q; i++) {
    int l, r, res;
    scanf("%d %d", &l, &r);
    if (p[r] != p[l-1]) printf("-1\n");
    else if (s[r]-s[l-1] == 0) printf("0\n");
    else if (a[l] == 0 || a[r] == 0) printf("1\n");
    else if ((r-l+1) % 2 == 1) printf("1\n");
    else if (last[r] >= l)  printf("2\n");
    else printf("-1\n");
  }

}