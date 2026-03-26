#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }
    vector f(n + 1, vector(m + 1, -1));

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    auto dfs = [&](auto &&self, int x, int y) {
        if(f[x][y] != -1) {
            return f[x][y];
        }
        int mx = 1;
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if(g[nx][ny] <= g[x][y]) {
                continue;
            }
            mx = max(mx, self(self, nx, ny) + 1);
        }
        return f[x][y] = mx;
    };

    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            mx = max(mx, dfs(dfs, i, j));
        }
    }
    cout << mx << '\n';
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
