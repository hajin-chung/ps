#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;
int n; 

void count(vector<vector<pii>> &a, vector<int> &ch, vector<bool> &chk, int u, int d, ll &sum) {
  chk[u] = 1;
  ch[u] = 1;
  sum += d;
  for (auto [v, w] : a[u])
    if (!chk[v]) {
      count(a, ch, chk, v, d+w, sum); 
      ch[u] += ch[v];
    }
}

void traverse(vector<vector<pii>> &a, vector<int> &ch, vector<bool> &chk, int u, ll s, ll &mn) {
  chk[u] = 1;
  mn = min(mn, s);
  for (auto [v, w] : a[u])
    if (!chk[v]) {
      int ns = s - w*ch[v] + w*(n-ch[v]);
      traverse(a, ch, chk, v, ns, mn);
    }
}

bool solve() {
  cin>>n;
  if (n == 0) return false;
  vector<vector<pii>> a(n);
  for (int i = 0; i < n-1; i++) {
    int u, v, w; cin>>u>>v>>w;
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  vector<int> ch(n);
  vector<bool> chk(n);
  ll sum = 0;
  count(a, ch, chk, 0, 0, sum);
  ll mn = sum;
  for (int i = 0; i < n; i++) chk[i] = 0;
  traverse(a, ch, chk, 0, sum, mn);
  cout<<mn<<"\n";
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (solve()) {}
}
