#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Structure to represent a line: f(x) = p*x + q
struct Line {
    ll p, q;
    ll eval(ll x) const { return p * x + q; }
};

// Li Chao Tree Node
struct LiChaoNode {
    Line line;
    LiChaoNode* left;
    LiChaoNode* right;
    LiChaoNode(Line l = {0, LLONG_MIN}) : line(l), left(nullptr), right(nullptr) {}
};

// Li Chao Tree Structure
struct LiChaoTree {
    LiChaoNode* root;
    ll X_MIN, X_MAX;

    LiChaoTree(ll min_x, ll max_x) : root(nullptr), X_MIN(min_x), X_MAX(max_x) {}

    void insert(Line new_line) {
        insert(root, new_line, X_MIN, X_MAX);
    }

    ll query(ll x) const {
        return query(root, x, X_MIN, X_MAX);
    }

private:
    void insert(LiChaoNode*& node, Line new_line, ll l, ll r) {
        if (!node) {
            node = new LiChaoNode(new_line);
            return;
        }
        ll mid = l + (r - l) / 2;
        ll current = node->line.eval(mid);
        ll incoming = new_line.eval(mid);
        if (incoming < current) { // Change to > for maximum queries
            swap(node->line, new_line);
            current = incoming;
        }
        if (new_line.eval(l) < node->line.eval(l)) { // Change to > for maximum queries
            insert(node->left, new_line, l, mid);
        }
        if (new_line.eval(r) < node->line.eval(r)) { // Change to > for maximum queries
            insert(node->right, new_line, mid + 1, r);
        }
    }

    ll query(const LiChaoNode* node, ll x, ll l, ll r) const {
        if (!node) return LLONG_MAX; // Change to LLONG_MIN for maximum queries
        ll res = node->line.eval(x);
        ll mid = l + (r - l) / 2;
        if (x <= mid && node->left) {
            res = min(res, query(node->left, x, l, mid)); // Change to max for maximum queries
        }
        else if (x > mid && node->right) {
            res = min(res, query(node->right, x, mid + 1, r)); // Change to max for maximum queries
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n; n--;
    vector<ll> s(n + 1, 0);
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        s[i] = s[i - 1] + x;
    }
    vector<ll> p(n), q(n);
    for(int i = 0; i < n; i++) cin >> q[i] >> p[i];
    
    // Determine X_MIN and X_MAX based on s[i]
    ll X_MIN = 0;
    ll X_MAX = s[n];
    
    // Initialize Li Chao Tree
    LiChaoTree cht(X_MIN, X_MAX);
    
    ll dp = 0;
    // Insert the first line
    cht.insert(Line{p[0], -s[0] * p[0] + q[0] + dp});
    
    for(int i = 1; i <= n; i++){
        dp = cht.query(s[i]);
        if(i < n){
            cht.insert(Line{p[i], -s[i] * p[i] + q[i] + dp});
        }
    }
    cout << dp << "\n";
}


