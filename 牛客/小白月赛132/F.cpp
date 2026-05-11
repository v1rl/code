#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

/*
f[op1][op2][x] 子树x使用过/未使用过,当前点使用/不使用操作的最大路径和
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }


    if(n == 1) {
        cout << (w[1] ^ k) << '\n';
        return;
    }

    vector f(2, vector(2, vector(n + 1, (i64)-1)));
    auto dfs = [&](auto &&self, int x, int p) -> void {
        vector<array<i64, 2>> vec;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            f[1][1][x] = max(f[1][1][x], f[1][1][y] + (w[x] ^ k));
            vec.push_back({f[0][0][y], y});
        }

        if(vec.empty()) {
            f[0][0][x] = w[x];
            f[1][1][x] = w[x] ^ k;
            return;
        }

        sort(vec.begin(), vec.end(), greater());

        auto [x1, mxId] = vec[0];
        f[0][0][x] = x1 + w[x];

        i64 x2 = inf, x3 = inf;
        for(int i = 1; i < vec.size(); i ++) {
            auto [_, y] = vec[i];
            if(f[1][0][y] != -1) {
                x2 = min(x2, f[1][0][y]);
            }
            x3 = min(x3, f[1][1][y]);
        }

        i64 x4 = f[1][0][mxId];
        if(x4 == -1) {
            x4 = inf;
        }
        i64 x5 = f[1][1][mxId];

        i64 x6 = 0;
        if(vec.size() > 1) {
            x6 = vec[1][0];
        }

        f[1][0][x] = min(min(max(x1, x2), max(x4, x6)), min(max(x1, x3), max(x5, x6))) + w[x];
    };

    dfs(dfs, 1, -1);

    cout << min(f[1][1][1], f[1][0][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
