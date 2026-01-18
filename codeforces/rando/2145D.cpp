#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

const int N = 30;
const int MAXK = (N-1)*(N-2)/2;
int dp[N+1][MAXK+5];

void pre() {
  for (int i = 0; i <= N; i++)
    for (int k = 0; k <= MAXK; k++)
      dp[i][k] = -1;
  for (int i = 1; i < N; i++) {
    dp[i][0] = 0;
    for (int k = 1; k < i; k++)
      for (int j = k; j <= MAXK ; j++)
        if (dp[i-1][j-k] >= 0)
          dp[i][j] = k;
  }
}

void f() {
  int n, k; cin>>n>>k;
  if (dp[n][k] < 0) {
    cout<<"0\n";
    return;
  } 
  vector<int> fc;
  for (int i = n; i >= 1; i--) {
    fc.push_back(dp[i][k]);
    k -= dp[i][k];
  }
  for (auto v : fc) cout<<v<<" ";
  cout<<endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int t; cin>>t;
  while(t--) f();
}
