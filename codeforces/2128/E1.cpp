#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

pair<bool, int> check(int x, int n, int k, const vector<int> &a) {
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    b[i] = (a[i] >= x ? 1 : -1);

  int current_sum = 0;
  for (int i = 0; i < k; i++)
    current_sum += b[i];
  if (current_sum > 0)
    return {true, k-1};

  for (int i = k; i < n; i++) {
    current_sum += b[i] - b[i - k];
    if (current_sum > 0)
      return {true, i};
  }
  return {false, 0};
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int low = 1, high = 0;
  for (int &x : a) {
    cin >> x;
    high = max(high, x);
  }

  int end = 0, ans = 0;
  int l = low, r = high;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    auto cc = check(mid, n, k, a);
    if (cc.fi) {
      if (ans < mid) {
        ans = mid;
        end = cc.se;
      }
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  l = low, r = high;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    auto cc = check(mid, n, k+1, a);
    if (cc.fi) {
      if (ans < mid) {
        ans = mid;
        end = cc.se;
      }
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout<<ans<<" "<<end-k+2<<" "<<end+1<< "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}

