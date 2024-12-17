#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long int ll;
struct Trie {
  ll cnt;
  map<char, Trie*> ch;
  Trie() : cnt(0) {}
};
vector<ll> dp;

void insert(Trie *node, string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (node->ch.count(s[i]) == 0) node->ch[s[i]] = new Trie();
    node = node->ch[s[i]];
    node->cnt++;
  }
}

void go(Trie *node, string &s, int offset) {
  for (int i = offset; i < s.size(); i++) {
    if (node->ch.size() == 0) break;
    if (node->ch.count(s[i]) == 0) break;
    node = node->ch[s[i]];
    if (node->cnt > 0) {
      ll pv = (offset == 0 ? 1 : dp[offset-1]);
      dp[i] = (dp[i] + pv*node->cnt)%MOD;
    }
  } 
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  Trie* trie = new Trie();
  int n; cin>>n;
  for (int i = 0; i < n; i++) {
    string s; cin>>s;
    insert(trie, s);
  }
  string w; cin>>w;
  int len = w.size();
  dp.resize(len);
  for (int i = 0; i < len; i++) go(trie, w, i); 
  cout<<dp[len-1]<<"\n";
}
