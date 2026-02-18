#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
f[x][j]：以x为根，保留j个节点的连通块，需要切断的边数。
*/
const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        d[x] ++, d[y] ++;
        adj[x].emplace_back(y);
    } 

    vector f(n + 1, vector(m + 1, inf));
    for(int i = 1; i <= n; i ++) {
        f[i][1] = d[i];
    }

    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto && self, int x) -> void {
        for(auto y : adj[x]) {
            self(self, y);
            for(int j = min(m, siz[x]); j >= 1; j --) {
                for(int k = min(m - j, siz[y]); k >= 1; k --) {
                    f[x][j + k] = min(f[x][j + k], f[y][k] + f[x][j] - 2);
                }
            }
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 1);

    int ans = inf;
    for(int x = 1; x <= n; x ++) {
        ans = min(ans, f[x][m]);
    }
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