#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

bool prime[MAX], chk[55];
int n, a[55];
vector<int> ans;

void dfs(int curr, int fp, int cnt) {
  if (curr == n) {
    if (cnt == n) ans.push_back(fp);
    return;
  } else if (chk[curr]) {
    dfs(curr+1, fp, cnt);
    return;
  }

  for (int i = 0; i < n; i++)
    if (i != curr && !chk[i] && !prime[a[curr]+a[i]]) {
      chk[curr] = chk[i] = true;
      dfs(curr+1, curr==0?a[i]:fp, cnt + 2);
      chk[curr] = chk[i] = false;
    }
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

  dfs(0, -1, 0);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (auto a : ans) cout << a << " ";
  if (ans.size() == 0) cout << "-1";
  cout << "\n";
}
