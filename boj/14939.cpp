#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

int a[15], b[15];

void print() {
  printf("\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j ++) {
      if (b[i] & (1 << j)) printf("O");
      else printf("#");
    }
    printf("\n");
  }
}

void flip(int idx, int mask) {
  for (int i = 0; i < 10; i++)
    if (mask & (1<<i)) {
      if (idx != 0) b[idx-1] ^= (1 << i);
      if (idx != 9) b[idx+1] ^= (1 << i);
      if (i != 0) b[idx] ^= (1 << (i-1));
      if (i != 9) b[idx] ^= (1 << (i+1));
      b[idx] ^= (1 << i);
    }
}

int solve(int mask) {
  int cnt = 0;
  for (int i = 0; i < 10; i++)
    if (mask & (1 << i))
      cnt++;

  for (int i = 0; i < 10; i++)
    b[i] = a[i];

  for (int i = 0; i < 10; i++) {
    flip(i, mask);
    mask = 0;
    for (int j = 0; j < 10; j++)
      if (b[i] & (1 << j)) {
        mask += (1 << j);
        cnt++;
      }
  }

  bool flag = false;
  for (int i = 0; i < 10; i++)
    if (b[9] & (1 << i))
      flag = true;
  if (flag) return INF;
  return cnt;
}

int main() {
  char tmp[15];
  for (int i = 0; i < 10; i++) {
    int r = 0;
    scanf("%s", &tmp);
    for (int j = 0; j < 10; j++)
      if (tmp[j] == 'O')
        r += (1 << j);
    a[i] = r;
  }

  int ans = INF;
  for (int i = 1; i <= (1<<10); i++) ans = min(ans, solve(i));
  if (ans == INF) printf("-1\n");
  else printf("%d\n", ans);
}
