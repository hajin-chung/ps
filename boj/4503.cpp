#include <bits/stdc++.h>
#define ENDA (1 << 13) - 1
#define ENDB 0
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> t3i;

char a[30];

void print_binary(int a) {
  // for (int i = 0; i < 13; i++) {
  //   printf("%d", (a & 1 << i) > 0);
  // }
  // printf("(%d)", a);
}

void print_pair_binary(int a, int b) {
  // print_binary(a);
  // printf(" ");
  // print_binary(b);
  // printf("\n");
}

int exchange(int aa, int bb, int ai, int bi) {
  // printf("\nexchange debug\n");
  int ta, tb;
  print_pair_binary(aa, bb);
  // printf("%d %d\n", ai, bi);
  for (int i = 0; i < 3; i++) {
    int tai = (ai + i) % 13;
    int tbi = (bi + i) % 13;
    tb = bb & (1 << tbi);
    // printf("\n%d\n", i);

    // printf("tb = ");
    // print_binary(tb);
    // printf("\n");

    tb |= ((1 << 13) - 1) - (1 << tbi);

    // printf("tb = ");
    // print_binary(tb);
    // printf("\n");

    aa |= 1 << tai;
    // printf("aa = ");
    // print_binary(aa);
    // printf("\n");

    aa &= tb;
    // printf("aa = ");
    // print_binary(aa);
    // printf("\n");
  }
  // printf("========\n\n");
  return aa;
}

int solve() {
  int i, j, na, nb;
  priority_queue<t3i, vector<t3i>, greater<t3i>> pq;
  vector<int> d;
  d.resize(1 << 26);

  na = nb = 0;
  for (i = 0; i < 13; i++) {
    na += a[i] == 'g' ? 1 << i : 0;
    nb += a[i+13] == 'g' ? 1 << i : 0;
  }

  d[na << 13 + nb] = 1;
  pq.push({0, na, nb});
  while (!pq.empty()) {
    auto [dd, aa, bb] = pq.top();
    print_pair_binary(aa, bb);
    pq.pop();
    if (aa == ENDA && bb == ENDB) return dd - 1;
    for (i = 0; i < 13; i++)
      for (j = 0; j < 13; j++) {
        int ta = exchange(aa, bb, i, j);
        int tb = exchange(bb, aa, j, i);
        // printf("%d %d ", i, j);
        print_pair_binary(ta, tb);
        if (d[(ta << 13) + tb] > 0 && d[(ta << 13) + tb] <= dd + 1) continue;
        d[(ta << 13) + tb] = dd + 1;
        pq.push({dd + 1, ta, tb});
      }
  }
  return -1;
}

int main() {
  while (scanf("%s", a) != EOF) {
    printf("%d\n", solve());
    memset(a, 0, sizeof(a));
  }
}

