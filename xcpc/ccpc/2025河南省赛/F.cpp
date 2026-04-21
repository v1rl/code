#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
    }
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    /*
    vector dist(n, vector(m, array<int, 3>{inf, inf, inf}));
    dist[0][0][0] = 0;
    deque<array<int, 3>> q;
    q.push_front({0, 0, 0});
    while(q.size()) {
        auto [x, y, op] = q.front();
        q.pop_front();

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(op == 0) {
                if(g[nx][ny] == '.') {
                    if(dist[nx][ny][0] == inf) {
                        dist[nx][ny][0] = dist[x][y][0];
                        q.push_front({nx, ny, 0});
                    }
                } else {
                    if(dist[nx][ny][1] == inf) {
                        dist[nx][ny][1] = dist[x][y][0] + 1;
                        q.push_back({nx, ny, 1});
                    }
                }
            } else if(op == 1) {
                if(g[nx][ny] == '.') {
                    if(dist[nx][ny][1] == inf) {
                        dist[nx][ny][1] = dist[x][y][1] + 1;
                        q.push_back({nx, ny, 1});
                    }
                    if(dist[nx][ny][2] == inf) {
                        dist[nx][ny][2] = dist[x][y][1];
                        q.push_front({nx, ny, 2});
                    }
                } else {
                    if(dist[nx][ny][1] == inf) {
                        dist[nx][ny][1] = dist[x][y][1] + 1;
                        q.push_back({nx, ny, 1});
                    }
                }
            } else {
                if(g[nx][ny] == '.') {
                    if(dist[nx][ny][2] == inf) {
                        dist[nx][ny][2] = dist[x][y][2];
                        q.push_front({nx, ny, 2});
                    }
                }
            }
        }
    }

    cout << min({dist[n - 1][m - 1][0], dist[n - 1][m - 1][1], dist[n - 1][m - 1][2]}) << '\n';
    */

    auto work = [&](int sx, int sy) {
        vector dist(n, vector(m, inf));
        queue<array<int, 2>> q;
        q.push({sx, sy});
        dist[sx][sy] = 0;
        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i ++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != '.' || dist[nx][ny] != inf) {
                    continue;
                }
                dist[nx][ny] = 0;
                q.push({nx, ny});
            }
        }

        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(dist[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(q.size()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i ++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != inf) {
                    continue;
                }
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        return dist;
    };


    auto dist1 = work(0, 0);
    auto dist2 = work(n - 1, m - 1);
    int ans = inf;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            ans = min(ans, max(0, dist1[i][j] + dist2[i][j] - 1));
        }
    }
    cout << ans << '\n';
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
