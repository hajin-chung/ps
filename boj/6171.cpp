// 우선 w를 기준으로 오름차순 정렬
// dp[i] = i번째 땅 까지 고려했을 때 최선
//       = min(dp[j]+w[i]*max(h[j+1]..h[i])) (j : 0..i-1)
//       max(h[j+1]..h[i]) -> j 가 증가할수록 감
#include <bits/stdc++.h>
#define fi first
#define se second
#define N 50000
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
struct Line {
  ll a, b; // y = a*x+b;
  Line(ll a, ll b) : a(a), b(b) {}
  ll f(ll x) { return a*x+b; }
};
int n;
pll wh[N+1];
ll dp[N+1];
vector<Line> lv;
int pv;

int chk(const Line& a, const Line& b, const Line& c) {
  return (double)(a.b-b.b)/(b.a-a.a) >= (double)(c.b-b.b)/(b.a-c.a);
}

void insert(Line l) {
  while (lv.size() >= pv+2 && chk(lv[lv.size()-2], lv.back(), l)) lv.pop_back();
}

ll query(ll x) {
  while (pv+1 < lv.size() && lv[pv].f(x) <= lv[pv+1].f(x)) pv++;
  return lv[pv].f(x);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  for (int i = 1; i <= n; i++) cin>>wh[i].fi>>wh[i].se;
  for (int i = 1; i <= n; i++) {
    
  }
}
