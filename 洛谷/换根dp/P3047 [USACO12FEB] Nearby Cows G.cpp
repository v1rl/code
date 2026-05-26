#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P3047

/*
in[x][j] 子树x内部（包括x本身）跨j条边的奶牛数
out[x][j] 子树x外部（不包括x本身）跨k条边的奶牛数
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
    }

    vector in(n + 1, vector(k + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= k; j ++) {
            in[i][j] = v[i];
        }
    }

    auto dfs1 = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            for(int j = 1; j <= k; j ++) {
                in[x][j] += in[y][j - 1];
            }
        }
    };

    dfs1(dfs1, 1, -1);

    // vector dp(n + 1, vector(k + 1, 0));
    // dp[1] = in[1];
    // auto dfs2 = [&](auto &&self, int x, int p) -> void {
    //     for(auto y : adj[x]) {
    //         if(y == p) {
    //             continue;
    //         }

    //         dp[y][0] = v[y];
    //         dp[y][1] = in[y][1] + dp[x][0];
    //         for(int j = 2; j <= k; j ++) {
    //             dp[y][j] = in[y][j] + dp[x][j - 1] - in[y][j - 2];
    //         }

    //         self(self, y, x);
    //     }
    // };
    // dfs2(dfs2, 1, -1);

    // for(int i = 1; i <= n; i ++) {
    //     int ans = 0;
    //     for(int j = 0; j <= k; j ++) {
    //         ans = max(ans, dp[i][j]);
    //     }
    //     cout << ans << '\n';
    // }

    vector out(n + 1, vector(k + 1, 0));
    auto dfs2 = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }

            out[y][0] = 0;
            out[y][1] = in[x][0];
            for(int j = 2; j <= k; j ++) {
                out[y][j] = in[x][j - 1] + out[x][j - 1] - in[y][j - 2];
            }

            self(self, y, x);
        }
    };
    dfs2(dfs2, 1, -1);

    for(int i = 1; i <= n; i ++) {
        cout << in[i][k] + out[i][k] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}