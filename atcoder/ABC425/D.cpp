#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
模拟，但层数阶段变化后才能将上一层的点更新为黑块'#'
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, '.'));
    vector vis(n, vector(m, 0));
    vector<vector<array<int, 2>>> dep(n * m + 1);

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
            if(g[i][j] == '#') {
                dep[0].push_back({i, j});
            }
        }
    }

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    int cur = 0;
    while(1) {
        for(auto [x, y] : dep[cur]) {
            for(int i = 0; i < 4; i ++) {
                int nx = x + dx[i], ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if(g[nx][ny] == '#' || vis[nx][ny]) {
                    continue;
                }

                int cnt = 0;
                for(int j = 0; j < 4; j ++) {
                    int mx = nx + dx[j], my = ny + dy[j];

                    if(mx < 0 || mx >= n || my < 0 || my >= m) {
                        continue;
                    }
                    if(g[mx][my] == '#') {
                        cnt ++;
                    }
                }

                if(cnt == 1) {
                    vis[nx][ny] = true;
                    dep[cur + 1].push_back({nx, ny});
                }
            }
        }

        cur ++;
        if(dep[cur].empty()) {
            break;
        }
        for(auto [x, y] : dep[cur]) {
            g[x][y] = '#';
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            ans += (g[i][j] == '#');
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}