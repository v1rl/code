#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;
typedef pair<i64, i64> PII;

// http://poj.org/problem?id=3585

void solve() {
    int n;
    cin >> n;
    vector<vector<PII>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<i64> v(n + 1);
    auto dfs1 = [&](auto &&self, int x, int p) -> void {
        i64 res = 0;
        for(auto [y, w] : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            if(adj[y].size() != 1) {
                res += min(v[y], w);
            } else {
                res += w;
            }
        }
        v[x] = res;
    };

    dfs1(dfs1, 1, -1);

    vector<i64> dp(n + 1);
    dp[1] = v[1];
    auto dfs2 = [&](auto &&self, int x, int p) -> void {
        for(auto [y, w] : adj[x]) {
            if(y == p) {
                continue;
            }
            if(adj[x].size() == 1) {
                dp[y] = v[y] + w;
            } else if(adj[y].size() == 1) {
                dp[y] = v[y] + min(dp[x] - w, w);
            } else {
                dp[y] = v[y] + min(dp[x] - min(v[y], w), w);
            }
            self(self, y, x);
        }
    };

    dfs2(dfs2, 1, -1);

    i64 x = *max_element(dp.begin() + 1, dp.end());
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}