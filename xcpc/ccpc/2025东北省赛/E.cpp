#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;
const int mod = 1e9 + 7;

vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);
    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }
}

int C(int a, int b) {
    if(a < b) {
        return 0;
    }
    return 1ll * fact[a] * infact[a - b] % mod * infact[b] % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector f(n + 1, vector(m + 1, 0));
    vector g(n + 1, vector(m + 1, 0));
    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        f[x][0] = 1;
        g[x][0] = w[x];
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }

            self(self, y, x);

            vector<int> nf(m + 1);
            vector<int> ng(m + 1);

            for(int j = min(m, siz[x] - 1); j >= 0; j --) {
                for(int k = min(m - j, siz[y] - 1); k >= 0; k --) {
                    nf[j + k] = (nf[j + k] + 1ll * f[x][j] * f[y][k] % mod * C(j + k, j) % mod) % mod;
                    ng[j + k] = (ng[j + k] + (1ll * g[x][j] * f[y][k] % mod + 1ll * g[y][k] * f[x][j] % mod) % mod * C(j + k, j) % mod) % mod; 

                    if(j + k < m) {
                        nf[j + k + 1] = (nf[j + k + 1] + 1ll * f[x][j] * f[y][k] % mod * C(j + k + 1, j) % mod) % mod;
                        ng[j + k + 1] = (ng[j + k + 1] + 1ll * g[x][j] * f[y][k] % mod * C(j + k + 1, j) % mod) % mod;
                    }
                }
            }

            f[x] = move(nf);
            g[x] = move(ng);
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 1, -1);
    cout << g[1][m] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init(5000);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}