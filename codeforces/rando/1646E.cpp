#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
const int N = 1e6;
const int M = 20;
int sv[N+1], uv[M+1], pr[N+1];
bool st[N*M+1];

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void pre() {
  sv[1] = 0;
  for (int i = 2; i*i <= N; i++) {
    if (sv[i] != 0) continue;
    for (int j = i*i; j <= N; j*=i) {
      sv[j] = 1;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (pr[i] != 0) continue;
    for (int j = i; j <= N; j++)
      pr[j] = i;
  }
}

int fg(int x) {
  int g = 0;
  while (x > 1) {
    int cnt = 0, t = x;
    while (t > 1) {
      cnt++;
      t /= pr[x];
    }
    x = t;
    if (g == 0) g = cnt;
    else g = gcd(g, cnt);
  }
  return g;
}

int lg(int x, int n) {
  int cnt = 0;
  while (n/x) {
    n/=x;
    cnt++;
  }
  return cnt;
}

void solve() {
  ll n, m; cin>>n>>m;

  uv[0] = 0;
  for (int i = 1; i <= M; i++) {
    uv[i] = uv[i-1];
    for (int j = 1; j <= m; j++) {
      if (st[i*j] == 0) uv[i]++;
      st[i*j] = 1;
    }
  }

  ll ans = 1;
  for (int i = 2; i <= n; i++) 
    if (!sv[i]) 
      ans += uv[lg(i, n)];
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  solve();
}
