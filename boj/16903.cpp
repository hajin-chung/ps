#include <bits/stdc++.h>
#define LOG_MAX 30
using namespace std;

struct Trie {
  int cnt;
  Trie *z;
  Trie *o;
  Trie() : cnt(0), z(nullptr), o(nullptr) {}
};
int n;
vector<int> a;

void insert(Trie* root, int num) {
  Trie *curr = root;
  for (int i = (int)30; i >= 0; i--) {
    if (num & (1 << i)) {
      if (curr->o == nullptr) curr->o = new Trie();
      curr = curr->o;
    } else {
      if (curr->z == nullptr) curr->z = new Trie();
      curr = curr->z;
    }
    curr->cnt++;
    num = num & (~(1<<i));
  }
}

void remove(Trie *root, int num) {
  Trie *curr = root;
  for (int i = (int)30; i >= 0; i--) {
    if (num & (1 << i)) {
      curr = curr->o;
    } else {
      curr = curr->z;
    }
    curr->cnt--;
    num = num & (~(1<<i));
  }
}

int query(Trie* root, int num) {
  Trie *curr = root;
  int ret = 0;
  for (int i = LOG_MAX; i >= 0; i--) {
    if (num & (1 << i)) {
      if (curr->z != nullptr && curr->z->cnt != 0) {
        curr = curr->z;
        ret += (1<<i);
      } else if (curr->o != nullptr && curr->o->cnt != 0) {
        curr = curr->o;
      } else {
        break;
      }
    } else {
      if (curr->o != nullptr && curr->o->cnt != 0) {
        curr = curr->o;
        ret += (1<<i);
      } else if (curr->z != nullptr && curr->z->cnt != 0) {
        curr = curr->z;
      } else {
        break;
      }
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
