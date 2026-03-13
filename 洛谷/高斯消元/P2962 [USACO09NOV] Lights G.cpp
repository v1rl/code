#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P2962

int guass(int n, auto &g) {
    for(int x = 1; x <= n; x ++) {
        for(int i = 1; i <= n; i ++) {
            if(i < x && g[i][i] == 1) {
                continue;
            }
            if(g[i][x] == 1) {
                swap(g[i], g[x]);
                break;
            }
        }

        if(g[x][x] == 0) {
            continue;
        }

        for(int i = 1; i <= n; i ++) {
            if(i != x && g[i][x] == 1) {
                g[i] ^= g[x];
            }
        }
    }

    int ans = 40;
    vector<int> col(n + 1);
    auto dfs = [&](auto &&self, int res, int x) -> void {
        if(res > ans) {
            return;
        }
        if(x == 0) {
            ans = min(ans, res);
            return;
        }

        if(g[x][x] == 0) {
            col[x] = 0;
            self(self, res, x - 1);
            col[x] = 1;
            self(self, res + 1, x - 1);
        } else {
            int s = 0;
            for(int i = x; i <= n; i ++) {
                s ^= (col[i] & g[x][i]);
            }
            if((g[x][n + 1] ^ s) & 1) {
                self(self, res + 1, x - 1);
            } else {
                self(self, res, x - 1);
            }
        }
    };

    dfs(dfs, 0, n);
    return ans;
}

const int N = 35;

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n + 1, bitset<N + 2>());
    for(int i = 1; i <= n; i ++) {
        g[i][i] = 1;
        g[i][n + 1] = 1;
    }

    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }

    cout << guass(n, g) << '\n';
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