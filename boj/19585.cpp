#include <bits/stdc++.h>
using namespace std;

struct Trie {
  bool isWord; 
  vector<pair<char, Trie*>> ch;
  Trie(bool isWord = false) : isWord(isWord) {}
};

void printTrie(Trie *tn, string s) {
  if (tn->isWord) cout << s << "\n";
  for (int i = 0; i < tn->ch.size(); i++) {
    s.push_back(tn->ch[i].first);
    printTrie(tn->ch[i].second, s);
    s.pop_back();
  }
}

Trie *color, *name;

void insert(Trie* root, string s) {
  Trie* tn = root; 
  for (int i = 0; i < s.size(); i++) {
    bool flag = false;
    int idx = 0;
    for (int j = 0; j < tn->ch.size(); j++)
      if (tn->ch[j].first == s[i]) {
        flag = true;
        idx = j; 
        break;
      } 
    if (flag) {
      tn = tn->ch[idx].second;
    } else {
      Trie* ntn = new Trie(false);
      tn->ch.push_back({s[i], ntn});
      tn = ntn;
    }
  }
  tn->isWord = true;
}

bool query(string &s) {
  Trie* tn = color;
  vector<bool> flags;
  flags.resize(s.size(), false);
  for (int i = 0; i < s.size(); i++) {
    if (tn->isWord) flags[i-1] = true;
    bool flag = false;
    int idx = 0;
    for (int j = 0; j < tn->ch.size(); j++)
      if (tn->ch[j].first == s[i]) {
        flag = true;
        idx = j;
        break;
      }
    if (flag) tn = tn->ch[idx].second;
    else break;
  }

  // for (auto f: flags) cout << f << " ";
  // cout << "\n";

  tn = name;
  for (int i = s.size()-1; i >= 0; i--) {
    if (tn->isWord && flags[i]) return true; 
    bool flag = false;
    int idx = 0;
    for (int j = 0; j < tn->ch.size(); j++)
      if (tn->ch[j].first == s[i]) {
        flag = true;
        idx = j;
        break;
      }
    if (flag) tn = tn->ch[idx].second;
    else break;
  }
  return false;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q;
  int i, j;
  string s;

  color = new Trie(false);
  name = new Trie(false);

  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s;
    insert(color, s);
  }
  for (i = 0; i < m; i++) {
    cin >> s;
    reverse(s.begin(), s.end());
    insert(name, s);
  }
  // printTrie(color, "");
  // printTrie(name, "");

  cin >> q;
  for (i = 0; i < q; i++) {
    cin >> s;
    cout << (query(s) ? "Yes" : "No") << "\n";
  }
}
