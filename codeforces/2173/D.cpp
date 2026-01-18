#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void bp(int x, string label) {
  vector<int> s;
  for (; x; x>>=1) s.push_back(x&1);
  reverse(all(s));
  cout<<label<<": ";
  for (auto x: s) cout<<x;
  cout<<"\n";
}

int cons(int x) {
  int mx = 0, cnt = 0;
  while (x) {
    if (x&1) cnt++;
    else {
      mx = max(mx, cnt);
      cnt = 0;
    }
    x>>=1;
  }
  mx = max(mx, cnt);
  return mx;
}

int solve() {
  int n, k; cin>>n>>k;
  int ocnt = 0, zcnt = 0, blen = 0;
  bp(n, "n");
  for (int t = n; t; t>>=1, blen++) t&1?ocnt++:zcnt++;
  if (k > zcnt) return blen + (k-zcnt-1);

  int ans = 0;
  for (int i = 0; i < blen; i++) {
    if ((n&(1<<i)) == 1) continue;
    int t = n;
    for (int j = i, cnt = k-1; j < blen && cnt; j++)
      if (((t>>j)&1) == 0) {
        t += (1<<(j));
        cnt--;
      }
    bp(t, "t");
    ans = max(ans, cons(t));
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) cout<<solve()<<"\n";
}
