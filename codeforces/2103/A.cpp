#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;

void f() {
  int n; cin>>n;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    int x; cin>>x;
    st.insert(x);
  }
  cout<<st.size()<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin>>t;
  while(t--) f();
}
