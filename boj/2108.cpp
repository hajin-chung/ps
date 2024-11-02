#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> a;
int cnt[8005];
int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  double sum = 0;
  int frq = 0, mn = 4005, mx = 0;
  scanf("%d", &n); a.resize(n); 
  for (auto &x : a) {
    cin >> x;
    cnt[x+4000]++;
    sum += (double)x;
    if (cnt[frq+4000] < cnt[x+4000]) frq = x;
    mn = min(mn, x);
    mx = max(mx, x);
  }
  sort(all(a));
  cout << (int)(sum/n+0.5) << "\n" << a[n/2] << "\n" << frq << "\n" << mx-mn << "\n";
}
