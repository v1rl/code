#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1171

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector g(n, vector(n, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }

    vector f(n, vector(1 << n, inf));

    /*
    auto dfs = [&](auto &&self, int s, int cur) -> int {
        if(s == (1 << n) - 1) {
            return g[cur][0];
        }

        if(f[cur][s] != inf) {
            return f[cur][s];
        }

        for(int i = 0; i < n; i ++) {
            if(~s >> i & 1) {
                f[cur][s] = min(f[cur][s], g[cur][i] + self(self, s | (1 << i), i));
            }
        }

        return f[cur][s];
    };

    cout << dfs(dfs, 1, 0);
    */

    f[0][1] = 0;
    for(int s = 0; s < (1 << n); s ++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(~s >> j & 1) {
                    int ns = s | (1 << j);
                    f[j][ns] = min(f[j][ns], g[i][j] + f[i][s]);
                }
            }
        }
    }

    int ans = inf;
    for(int i = 0; i < n; i ++) {
        ans = min(ans, f[i][(1 << n) - 1] + g[i][0]);
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
