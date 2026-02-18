#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
停下来的概率*深度
*/

const int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> arv(n + 1);
    vector<int> dep(n + 1);
    dep[1] = 1;
    arv[1] = 1;

    int ans = 0;
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            arv[y] = arv[x] * qmi(adj[x].size(), mod - 2) % mod;
            dep[y] = dep[x] + 1;
            ans += 1ll * dep[y] * arv[y] % mod * qmi(adj[y].size(), mod - 2) % mod;
            ans %= mod;
            self(self, y, x);
        }
    };

    dfs(dfs, 1, -1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}