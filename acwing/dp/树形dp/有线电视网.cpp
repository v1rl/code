#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int B = n * 10;
    vector<vector<PII>> adj(n + 1);
    for(int i = 1; i <= n - m; i ++) {
        int t;
        cin >> t;
        for(int j = 0; j < t; j ++) {
            int y, w;
            cin >> y >> w;
            adj[i].push_back({y, w});
        }
    }

    vector<int> zw(n + 1);
    for(int i = n - m + 1; i <= n; i ++) {
        cin >> zw[i];
    }

    /*
    // f[当前dfs序遍历到i][当前费用j(带偏移量)]
    vector f(n + 1, vector(B + 1, -inf));
    f[1][(n - m) * 10] = 0;
    auto dfs = [&](auto &&self, int x) -> void {
        for(auto [y, w] : adj[x]) {
            if(y >= n - m + 1) {
                for(int j = max(0, zw[y] - w); j <= min(B, B - w + zw[y]); j ++) {
                    f[y][j] = f[x][j + w - zw[y]] + 1;
                }
            } else {
                for(int j = 0; j <= B - w; j ++) {
                    f[y][j] = f[x][j + w];
                }                
            }
            self(self, y);
            for(int j = 0; j <= B; j ++) {
                f[x][j] = max(f[x][j], f[y][j]);
            }
        }
    };

    dfs(dfs, 1);
    int ans = 0;
    for(int j = (n - m) * 10; j <= B; j ++) {
        ans = max(ans, f[1][j]);
    }
    cout << ans << '\n';
    */

    // f[当前dfs序遍历到节点i][当前已连接用户数j]
    vector f(n + 1, vector(m + 1, -inf));
    f[1][0] = 0;
    auto dfs = [&](auto &&self, int x) -> void {
        for(auto [y, w] : adj[x]) {
            if(y >= n - m + 1) {
                for(int j = 1; j <= m; j ++) {
                    f[y][j] = f[x][j - 1] - w + zw[y];
                }
            } else {
                for(int j = 0; j <= m; j ++) {
                    f[y][j] = f[x][j] - w;
                }
            }
            self(self, y);
            for(int j = 0; j <= m; j ++) {
                f[x][j] = max(f[x][j], f[y][j]);
            }
        }
    };
    dfs(dfs, 1);

    for(int j = m; j >= 0; j --) {
        if(f[1][j] >= 0) {
            cout << j << '\n';
            break;
        }
    }
    
/*
    // f[当前子树i][当前已连接用户数j]
    vector f(n + 1, vector(m + 1, -inf));
    // 需要注意，第一维度为子树时，要对所有点进行初始化，而并非仅对根节点
    for(int i = 1; i <= n; i ++) {
        f[i][0] = 0;
    }
    vector<int> siz(n + 1);
    auto dfs = [&](auto &&self, int x) -> void {
        if(x >= n - m + 1) {
            f[x][1] = zw[x];
            siz[x] = 1;
            return;
        }
        for(auto [y, w] : adj[x]) {
            self(self, y);
            for(int j = min(m, siz[x]); j >= 0; j --) {
                for(int k = min(m - j, siz[y]); k >= 0; k --) {
                    f[x][j + k] = max(f[x][j + k], f[y][k] + f[x][j] - w);
                }
            }
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 1);

    for(int j = m; j >= 0; j --) {
        if(f[1][j] >= 0) {
            cout << j << '\n';
            break;
        }
    }
*/
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