#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    int l, r;
    cin >> l >> r;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
    }

    queue<array<int, 3>> q;
    vector dist(n, vector(m, array<int, 2>{inf, inf}));
    dist[0][0][0] = 0;
    q.push({0, 0, 0});
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
    while(q.size()) {
        auto [x, y, op] = q.front();
        q.pop();

        for(int i = 0; i < 8; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '0') {
                continue;
            }
            if(dist[nx][ny][op ^ 1] != inf) {
                continue;
            }
            dist[nx][ny][op ^ 1] = dist[x][y][op] + 1;
            q.push({nx, ny, op ^ 1});
        }
    }

    auto get = [&](int d) {
        if(d >= inf) {
            return inf;
        }
        int op = (d & 1);
        int ans = (d + r - 1) / r;
        int rem = ans * r - d;
        
        if(l < r) {
            return ans;
        }
        if(rem % 2 == 0) {
            return ans;
        }
        if(l % 2 == 0) {
            return inf;
        } else {
            return ans + 1;
        }
    };

    int ans = min(get(dist[n - 1][m - 1][0]), get(dist[n - 1][m - 1][1]));
    cout << (ans == inf ? -1 : ans) << '\n';
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
