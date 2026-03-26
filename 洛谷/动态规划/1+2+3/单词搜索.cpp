#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/word-search/description/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, '0'));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    string s;
    cin >> s;

    vector vis(n, vector(m, 0));

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    auto dfs = [&](auto &&self, int x, int y, int u) {
        if(u == s.size()) {
            return true;
        }
        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(vis[nx][ny]) {
                continue;
            }
            if(s[u] == g[nx][ny]) {
                vis[nx][ny] = true;
                if(self(self, nx, ny, u + 1)) {
                    return true;
                }
                vis[nx][ny] = false;
            }
        }
        return false;
    };

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == s[0]) {
                vis[i][j] = true;
                if(dfs(dfs, i, j, 1)) {
                    cout << "YES" << '\n';
                    return;
                }
                vis[i][j] = false;
            }
        }
    }
    cout << "NO" << '\n';
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
