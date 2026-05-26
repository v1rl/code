#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

/*
in[x] 以x为根的子树内部的贡献（包括x）
out[x] 以x为跟的子树外部的贡献（不包括x）
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    // vector<int> siz(n + 1, 1);
    // vector<i64> sum(n + 1, 1);
    // auto dfs1 = [&](auto &&self, int x, int p) -> void {
    //     for(auto y : adj[x]) {
    //         if(y == p) {
    //             continue;
    //         }
    //         self(self, y, x);
    //         siz[x] += siz[y];
    //         sum[x] += sum[y] + siz[y];
    //     }
    // };
    // dfs1(dfs1, 1, -1);


    // i64 ans = sum[1];
    // auto dfs2 = [&](auto &&self, int x, int p) -> void {
    //     for(auto y : adj[x]) {
    //         if(y == p) {
    //             continue;
    //         }
    //         sum[y] = sum[x] + n - 2 * siz[y];
    //         ans = max(ans, sum[y]);
    //         self(self, y, x);
    //     }
    // };
    // dfs2(dfs2, 1, -1);

    // cout << ans << '\n';

    vector<int> siz(n + 1, 1);
    vector<i64> in(n + 1, 1);
    auto dfs1 = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
            in[x] += in[y] + siz[y];
        }
    };
    dfs1(dfs1, 1, -1);

    i64 ans = in[1];
    vector<i64> out(n + 1);
    auto dfs2 = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            out[y] = in[x] - (in[y] + siz[y]) + out[x] + n - siz[y];
            self(self, y, x);
        }
        ans = max(ans, in[x] + out[x]);
    };
    dfs2(dfs2, 1, -1);

    cout << ans << '\n';
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