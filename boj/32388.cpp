#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
int n;
pdd a[4005], e;
double d[4005];

double pow2(double x) {return x*x;}

double dst(int curr, int next) {
  double d = sqrt(pow2(a[curr].fi-a[next].fi)+pow2(a[curr].se-a[next].se))-2;
  if (next == 0 || next == n+1) d += 1;
  if (curr == 0 || curr == n+1) d += 1;
  if (d < 0) return 0;
  else return d;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>e.fi>>e.se;
  a[0] = {0, 0};
  cin >> n;
  for (int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;
  for (int i = 0; i <= n+1; i++) d[i] = -1;
  d[0] = 0;
  a[n+1] = e;
  priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [dist, curr] = pq.top(); pq.pop();
    if (d[curr] < dist) continue;
    for (int next = 0; next <= n+1; next++) {
      double w = dst(curr, next);
      if (d[next] > d[curr] + w || d[next] == -1) {
        d[next] = d[curr] + w;
        pq.push({d[next], next});
      }
    }
  }
  cout << setprecision(10) << d[n+1] << "\n";
}
