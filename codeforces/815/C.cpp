#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int gcd(int a,int b){
  if(b==0)return a;
  else return gcd(b,a%b);
}

void solve() {
  int n, m, cnt = 0;
  int i, j, k;
  string s;
  cin >> n >> m;
  vector<vector<int> > a(n+1, vector<int>(m+1, 0));
  for(i=1 ; i<=n ; i++) {
    cin >> s;
    for(j=0 ; j<m ; j++) 
      if (s[j] == '1') a[i][j+1] = 1, cnt++;
  }

  bool flag = 0;
  int zcnt = 0;
  for(i=1 ; i<=n ; i++) {
    for(j=1 ; j<=m ; j++) {
      int acnt = 0;
      if (a[i][j] == 0) {
        zcnt++;
        for(k=0 ; k<4 ; k++) {
          int ty = i+dy[k], tx = j+dx[k], ty2 = i+dy[(k+1)%4], tx2 = j+dx[(k+1)%4];
          if (ty <= 0 || ty>n || tx<=0 || tx>m ) continue;
          if (a[ty][tx] == 0) flag = 1;
        }
      } else {
        for(k=0 ; k<4 ; k++) {
          int ty = i+dy[k], tx = j+dx[k], ty2 = i+dy[(k+1)%4], tx2 = j+dx[(k+1)%4];
          if (ty <= 0 || ty>n || tx<=0 || tx>m || ty2<=0 || ty2>n || tx2<=0 || tx2 > m) continue;
          if (a[ty][tx] == 0 && a[ty2][tx2] == 0) flag = 1;
        }
      }
    }
  }

  if (zcnt == 0) printf("%d\n", cnt-2);
  else if (flag == 1) printf("%d\n", cnt);
  else printf("%d\n", cnt-1);
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}