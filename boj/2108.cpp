#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> a;
vector<int> frq;
int cnt[8005];
int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  double sum = 0;
  int mf = 0, mn = 4005, mx = 0;
  scanf("%d", &n); a.resize(n); 
  for (auto &x : a) {
    cin >> x;
    cnt[x+4000]++;
    sum += (double)x;
    if (cnt[mf+4000] < cnt[x+4000]) mf = x;
    mn = min(mn, x);
    mx = max(mx, x);
  }
  for (auto x : a) if (cnt[x+4000] == cnt[mf+4000]) frq.push_back(x);
  sort(all(frq));
  sort(all(a));
  cout << (int)(sum/n+0.5) << "\n";
  cout << a[n/2] << "\n";
  if (frq.size() == 1) cout << frq[0] << "\n";
  else cout << frq[1] << "\n";
  cout << mx-mn << "\n";
}
