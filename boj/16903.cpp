#include <bits/stdc++.h>
#define LOG_MAX 30
using namespace std;

struct Trie {
  int cnt;
  Trie *ch[2];
  Trie() : cnt(0) {
    ch[0] = ch[1] = nullptr;
  }
};
int n;
vector<int> a;

void insert(Trie* root, int num) {
  Trie *curr = root;
  for (int i = LOG_MAX; i >= 0; i--) {
    int b = (num >> i) & 1;
    if (curr->ch[b] == nullptr) curr->ch[b] = new Trie();
    curr = curr->ch[b];
    curr->cnt++;
  }
}

void remove(Trie *root, int num) {
  Trie *curr = root;
  for (int i = LOG_MAX; i >= 0; i--) {
    int b = (num >> i) & 1;
    curr = curr->ch[b];
    curr->cnt--;
  }
}

int query(Trie* root, int num) {
  Trie *curr = root;
  int ret = 0;
  for (int i = LOG_MAX; i >= 0; i--) {
    int b = (num >> i) & 1;
    if (curr->ch[1-b] != nullptr && curr->ch[1-b]->cnt > 0 ) {
      curr = curr->ch[1-b];
      ret += (1 << i);
    } else if (curr->ch[b] != nullptr && curr->ch[b]->cnt > 0) {
      curr = curr->ch[b];
    } else {
      printf("dafdsla\n");
      break;
    }
  }
  return ret;
}

int main() {
  Trie* root = new Trie();
  scanf("%d", &n); 
  int q, x;
  while (n--) {
    scanf("%d %d", &q, &x);
    if (q == 1) insert(root, x);
    else if (q == 2) remove(root, x);
    else if (q == 3) printf("%d\n", query(root, x));
  }
}
