#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

typedef uint64_t ll;

const int N = 1e6;
int trie[N+5][26];
int cnt[N+5];
int nodes = 1;

void insert(string &s) {
  int u = 1;
  for (char c : s) {
    int v = c - 'a';
    if (!trie[u][v]) trie[u][v] = ++nodes;
    u = trie[u][v];
    cnt[u]++;
  }
}

ll count(string s) {
  int u = 1;
  ll sum = 0;
  for (auto c : s) {
    int v = c - 'a';
    if (!trie[u][v]) break;
    u = trie[u][v];
    sum += cnt[u];
  }
  return sum;
}

void f() {
  int n; cin>>n;
  vector<string> a(n);
  for (auto &s : a) cin>>s;

  for (auto s : a) insert(s);
  ll sum = 0;
  for (auto &s : a) sum += s.size();
  ll ans = sum*2*n;
  for (auto &s : a) {
    reverse(all(s));
    ans -= 2*count(s);
  }
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  f();
}
