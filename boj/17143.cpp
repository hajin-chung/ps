#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int s, d, z;
} shark;

int n, m, s;
int a[105][105];
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};
vector<shark> sharks;

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == -1) printf(". ");
      else printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void move_shark(int si) {
  shark S = sharks[si];
}

void move_sharks() {
  int i, j;
  int na[105][105];

  printf("aaaa\n");
  print();

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      na[i][j] = -1;

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i][j] != -1) {
        shark S = sharks[a[i][j]];

        int ny = (n + (i + dy[S.d] * S.s) % n) % n;
        int nx = (m + (j + dx[S.d] * S.s) % m) % m;
        printf("%d %d %d %d %d %d\n", a[i][j], dy[S.d] * S.s, dx[S.d] * S.s, S.d, ny, nx);
        if (na[ny][nx] == -1 || sharks[na[ny][nx]].z < S.z)
          na[ny][nx] = a[i][j];
      }
  printf("nananan\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (na[i][j] == -1) printf(". ");
      else printf("%d ", na[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      a[i][j] = na[i][j];
}

int main() {
  int i, j, k, y, x, sp, d, z;
  int ans = 0;

  scanf("%d %d %d", &n, &m, &s);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      a[i][j] = -1;

  for (i = 0; i < s; i++) {
    scanf("%d %d %d %d %d", &y, &x, &sp, &d, &z);
    y--; x--; d--;
    shark S = {sp, d, z};
    sharks.push_back(S);
    a[y][x] = i;
  }
  printf("\n\n");
  print();
  printf("\n\n");

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      if (a[j][i] != -1) {
        ans += sharks[a[j][i]].z;
        a[j][i] = -1;
        break;
      }

    move_sharks();
  }

  printf("%d\n", ans);
  return 0;
}
