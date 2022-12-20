#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

void solve() {
  int m, i, j, flag = 1;
  int yy, xx, is2 = 0;
  vector<vector<int> > board, visited, visited2;
  char c[200005];

  scanf("%d", &m);
  board.resize(3, vector<int>(m+1, 0));
  visited.resize(3, vector<int>(m+1, 0));
  visited2.resize(3, vector<int>(m+1, 0));
  for(i=1 ; i<=2;  i++) {
    for(j=1 ; j<=m+4 ; j++) c[j] = 0;
    scanf("%s", &c[1]);
    for(j=1 ; j<=m ; j++) 
      if (c[j] == 'B') board[i][j] = 1;
  }

  if (board[1][1] == 1) {
    yy = xx = 1; 
    if (board[2][1] == 1) {
      is2 = 1;
    }
  } else {
    yy = 2;
    xx = 1;
  }

  while(xx != m) {
    visited[yy][xx] = 1;
    if (visited[2-(yy+1)%2][xx] == 0 && board[2-(yy+1)%2][xx] == 1) {
      yy = 2-(yy+1)%2;
    } else if (board[yy][xx+1] == 1) {
      xx++;
    } else {
      flag = 0;
      break;
    }
  }

  if (flag == 1) {
    printf("YES\n");
    return;
  } else if (is2 == 0 && flag == 0) {
    printf("NO\n");
    return;
  }

  yy = 2;
  xx = 1;
  flag = 1;
  while(xx != m) {
    visited2[yy][xx] = 1;
    if (visited2[2-(yy+1)%2][xx] == 0 && board[2-(yy+1)%2][xx] == 1) {
      yy = 2-(yy+1)%2;
      continue;
    }
    if (board[yy][xx+1] == 1) {
      xx++;
      continue;
    } 
    flag = 0;
    break;
  }
  if (flag == 0) printf("NO\n");
  else printf("YES\n");

  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}