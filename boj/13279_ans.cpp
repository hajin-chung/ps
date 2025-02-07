#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 100003;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j > 0; --j) {
            dp[j] = (dp[j] + a[i] * dp[j - 1]) % MOD;
        }
    }
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        cout << dp[k] % MOD << "\n";
    }
}
