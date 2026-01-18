#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;
struct T {
  int cnt = 0;
  T *ch[2];
};

void insert(T *trie, int v) {
  T *t = trie;
  t->cnt++;
  for (int i = 29; i >= 0; i--) {
    int b = (v & (1<<i)) > 0;
    if (t->ch[b] == 0) t->ch[b] = new T;
    t->ch[b]->cnt++;
    t = t->ch[b];
  }
}

pii find(T *trie, int v) {
  int ret = 0, next = 0;
  T *t = trie;
  for (int i = 29; i >= 0; i--) {
    int b = (v & (1<<i)) > 0;
    if (t->ch[b] == 0 || t->ch[b]->cnt == 0) {
      ret += (1<<i);
      t = t->ch[1-b];
      next += (1-b) * (1<<i);
    } else {
      t = t->ch[b];
      next += (b) * (1<<i);
    }
  }
  return {ret, next};
}

void erase(T *trie, int v) {
  T *t = trie;
  t->cnt--;
  for (int i = 29; i >= 0; i--) {
    int b = (v & (1<<i)) > 0;
    t->ch[b]->cnt--;
    t = t->ch[b];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  T *trie = new T();
  int n; cin>>n;
  vector<int> a(n);
  for (auto &i : a) {
    cin>>i;
    insert(trie, i);
  }
  int curr = a[0];
  ll ans = 0;
  while (n--) {
    auto [ret, next] = find(trie, curr);
    erase(trie, curr);
    ans += (ll)ret;
    curr = next;
  }
  cout<<ans<<"\n";
}
