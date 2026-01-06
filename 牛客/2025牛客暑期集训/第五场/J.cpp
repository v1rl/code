#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int inf = 1e9;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector(m + 1, 0));
    vector dist(n + 1, vector(m + 1, inf));
    queue<array<int, 2>> q;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            if(g[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }


    while(q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            mx = max(mx, dist[i][j]);
        }
    }

    int l = 0, r = mx;
    if(r == inf) {
        r = n * m;
    }

    auto check = [&](int dis) -> bool {
        vector<array<int, 2>> p;
        int a = -inf, c = -inf;
        int b = inf, d = inf;

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(g[i][j] == 0 && dist[i][j] > dis) {
                    a = max(a, i + j), c = max(c, i - j);
                    b = min(b, i + j), d = min(d, i - j);
                    p.push_back({i, j});
                }
            }
        }

        if(p.size() == 1) {
            int tx = p[0][0], ty = p[0][1];
            bool f = true;
            for(auto [x, y] : p) {
                if(abs(x - tx) + abs(y - ty) > dis) {
                    return false;
                }
            }
            return true;
        } else {
            int s1 = a + b + c + d;
            int s2 = a + b - c - d;

            int tx = s1 / 4, ty = s2 / 4;
            // if(dis == 1) {

                // cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
                // for(auto [x, y] : p) {
                //     cout << x << ' ' << y << '\n';
                // }
                // cout << tx << ' ' << ty << '\n';
            // }

            vector<int> txs, tys;
            txs.emplace_back(tx);
            tys.emplace_back(ty);
            for(int i = 1; i <= 1; i ++) {
                txs.emplace_back(tx - 1);
                txs.emplace_back(tx + 1);
            }
            for(int i = 1; i <= 1; i ++) {
                tys.emplace_back(ty - 1);
                tys.emplace_back(ty + 1);
            }

            for(auto tx : txs) {
                for(auto ty : tys) {
                    if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
                    bool f = true;
                    for(auto [x, y] : p) {
                        if(abs(x - tx) + abs(y - ty) > dis) {
                            f = false;
                        }
                    }
                    if(f) return true;
                }
            }
            return false;
        }

    };

    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}