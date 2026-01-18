#include <stdio.h>
#include <vector>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int i, j;
    int n, m, k, a;
    int flag = 1, cnt = 0, pivot;
    scanf("%d %d %d", &n, &m, &k);
    vector<bool> visited(k+1, 0);
    pivot = k;
    for(i=1; i<=k; i++) {
      scanf("%d", &a) ;
      visited[a] = true;
      cnt++;
      if (cnt == n*m-2) flag = 0;
      while(visited[pivot] && pivot > 0) {
        cnt--;
        pivot--;
      }
    }
    if (flag) printf("YA\n");
    else printf("TIDAK\n");
  }
}

// 한 5번 정도 틀린 거 같은데 재발 생각좀 하고 짜자...