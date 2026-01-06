#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> a(26);

    vector g(n, vector(m + 1, '0'));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
            if(g[i][j] != '.' && g[i][j] != '#') {
                a[g[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    vector<int> st(26);
    queue<array<int, 2>> q;
    q.push({0, 0});
    vector dist(n, vector(m, inf));
    dist[0][0] = 0;

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(g[nx][ny] == '#') {
                continue;
            }
            if(dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        if(g[x][y] != '.' && !st[g[x][y] - 'a']) {
            st[g[x][y] - 'a'] = true;
            for(auto [nx, ny] : a[g[x][y] - 'a']) {
                if(dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << (dist[n - 1][m - 1] == inf ? -1 : dist[n - 1][m - 1]) << '\n';

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
