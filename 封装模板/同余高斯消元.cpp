#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://acm.hdu.edu.cn/showproblem.php?pid=5755

const int mod = 3;

pair<int, vector<int>> gauss(int n, auto &g) {
    for(int x = 1; x <= n; x ++) {
        for(int i = 1; i <= n; i ++) {
            if(i < x && g[i][i] != 0) {
                continue;
            }
            if(g[i][x] > 0) {
                swap(g[i], g[x]);
                break;
            }
        }

        if(g[x][x] == 0) {
            continue;
        }

        for(int i = 1; i <= n; i ++) {
            if(i != x && g[i][x] != 0) {
                int d = gcd(g[i][x], g[x][x]);
                int a = g[x][x] / d;
                int b = g[i][x] / d;
                for(int j = min(i, x); j <= n + 1; j ++) {
                    g[i][j] = ((g[i][j] * a - g[x][j] * b) % mod + mod) % mod;
                }
            }
        }
    }

    vector<int> inv(mod + 1);
    inv[1] = 1;
    for(int i = 2; i <= mod; i ++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    int f = 1;
    vector<int> ans(n + 1);
    for(int x = 1; x <= n; x ++) {
        if(g[x][x] == 0) {
            if(g[x][n + 1] == 0) {
                f = 0;
            } else {
                f = -1;
                break;
            }
        } else {
            ans[x] = g[x][n + 1] * inv[g[x][x]] % mod;
        }
    }

    return {f, ans};
}

void solve() {
    int n, m;
    cin >> n >> m;

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    auto cal = [&](int x, int y) {
        return (x - 1) * m + y;
    };

    vector g(n * m + 1, vector(n * m + 2, 0));

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x;
            cin >> x;
            int a = cal(i, j);
            g[a][n * m + 1] = (mod - x) % mod;
        }
    }

    for(int x = 1; x <= n; x ++) {
        for(int y = 1; y <= m; y ++) {
            int a = cal(x, y);
            g[a][a] = 2;
            for(int i = 0; i < 4; i ++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > m) {
                    continue;
                }
                int b = cal(nx, ny);
                g[b][a] = 1;
            }
        }
    }

    auto point = [&](int x) -> PII {
        return {(x - 1) / m + 1, (x - 1) % m + 1};
    };

    auto [f, ans] = gauss(n * m, g);

    int cnt = 0;
    for(int i = 1; i <= n * m; i ++) {
        cnt += ans[i];
    }

    cout << cnt << '\n';
    for(int i = 1; i <= n * m; i ++) {
        for(int j = 0; j < ans[i]; j ++) {
            auto [x, y] = point(i);
            cout << x << ' ' << y << '\n';
        }
    }

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