#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin>>n>>k;
  vector<int> a(n); for (auto &x : a) cin>>x;
  ordered_set os;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    os.insert({a[i], i});
    if (i < k-1) continue;
    os.erase({a[i-k], i-k});
    ans += (ll)os.find_by_order((k+1)/2-1)->first;
  }
  cout<<ans<<"\n";
}
