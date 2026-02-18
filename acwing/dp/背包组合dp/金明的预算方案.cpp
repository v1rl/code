#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/
const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1), w(n + 1);
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i ++) {
        int p;
        cin >> v[i] >> w[i] >> p;
        w[i] *= v[i];
        v[i] /= 10;
        adj[p].emplace_back(i);
    }
    m /= 10;

    /*
    vector<int> siz = v;
    vector f(n + 1, vector(m + 1, 0));
    auto dfs = [&](auto &&self, int x) -> void {
        if(x != 0) {
            for(int j = v[x]; j <= m; j ++) {
                f[x][j] = w[x];
            }
        }
        for(auto y : adj[x]) {
            self(self, y);
            siz[x] += siz[y];

            for(int j = min(m, siz[x]); j >= v[x]; j --) {
                for(int k = min(m - j, siz[y]); k >= 0; k --) {
                    f[x][j + k] = max(f[x][j + k], f[y][k] + f[x][j]);
                }
            }
        }
    };
    dfs(dfs, 0);
    cout << f[0][min(m, siz[0])] << '\n';
    */

    /*
    vector<vector<int>> f(n + 1, vector<int>(m + 1, -inf));
    f[0][0] = 0;
    auto dfs = [&](auto&& self, int x) -> void {
        for(auto y : adj[x]) {
            for(int j = v[y]; j <= m; j ++) {
                f[y][j] = f[x][j - v[y]] + w[y];
            }
            self(self, y);
            for(int j = v[y]; j <= m; j ++) {
                f[x][j] = max(f[x][j], f[y][j]);
            }
        }
    };
    */

    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto&& self, int x) -> void {
        for(auto y : adj[x]) {
            for(int j = 0; j <= m; j ++) {
                if(j < v[y]) {
                    f[y][j] = -inf;
                } else {
                    f[y][j] = f[x][j - v[y]] + w[y];
                }
            }
            self(self, y);
            for(int j = v[y]; j <= m; j ++) {
                f[x][j] = max(f[x][j], f[y][j]);
            }
        }
    };
    dfs(dfs, 0);
    cout << f[0][m] << '\n';

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