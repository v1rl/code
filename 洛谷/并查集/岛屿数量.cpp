#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/number-of-islands/description/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
    }

    vector vis(n, vector(m, 0));
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    auto bfs = [&](int sx, int sy) {
        queue<array<int, 2>> q;
        vis[sx][sy] = true;
        q.push({sx, sy});
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
                    continue;
                }
                if(g[nx][ny] == '0') {
                    continue;
                }
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    };

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(!vis[i][j] && g[i][j] == '1') {
                ans ++;
                bfs(i, j);
            }
        }
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
