#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

bool prime[MAX], chk[55];
int n, a[55], p[55];
vector<int> ans;

bool dfs(int curr) {
  for (int i = 0; i < n; i++) {
    if (i == curr) continue;
    if (prime[a[curr]+a[i]]) continue;
    if (chk[a[i]]) continue;

    chk[curr] = chk[a[i]] = true;
    if (p[a[i]] == 0 || dfs(p[a[i]])) {
      p[a[i]] = curr;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  prime[0] = prime[1] = true;
  for (int i = 2; i < 2000; i++)
    if (!prime[i])
      for (int j = i*i; j < 2000; j += i)
        prime[j] = true;

  for (int i = 0; i < n; i++) {

  }

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (auto a : ans) cout << a << " ";
  if (ans.size() == 0) cout << "-1";
  cout << "\n";
}
