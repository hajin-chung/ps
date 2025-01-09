#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct T { 
  int cnt;
  T *ch[2]; 
};

void insert(T *trie, ll v) {
  T *t = trie;
  t->cnt++;
  while (v) {
    int b = v & 1;
    if (t->ch[b] == 0) t->ch[b] = new T;
    t = t->ch[b];
    t->cnt++;
    v>>=1;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  ll x; T *trie = new T;
  while (n--) {
    cin>>x;
    insert(trie, x);
  }
}
