#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector hv(n, vector(n, 0));
    vector to(n, vector(n, 0));


    vector<array<int, 2>> g[n][n];
    for(int i = 0; i < m; i ++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x --, y --;
        a --, b --;
        g[x][y].push_back({a, b});
    }

    vector vis(n, vector(n, 0));

    vis[0][0] = true;
    queue<array<int, 2>> q;
    q.push({0, 0});

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for(auto &[a, b] : g[x][y]) {
            hv[a][b] = true;
            if(to[a][b] && !vis[a][b]) {
                q.push({a, b});
                vis[a][b] = true;
            }
        }

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {
                continue;
            }
            if(hv[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            } else {
                to[nx][ny] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            ans += vis[i][j];
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
