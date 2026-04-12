#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector f(n + 1, vector(2, 0));
    auto dfs = [&](auto &&self, int x, int p) -> void {
        bool ok = false;
        f[x][0] = 0;
        f[x][1] = 1;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            ok = true;
            self(self, y, x);
            f[x][1] += min(f[y][1], f[y][0]);
            f[x][0] += f[y][1];
        }
    };

    dfs(dfs, 1, -1);
    for(int i = 1; i <= n; i ++) {
        cout << min(f[i][0], f[i][1]) << ' ';
    }
    cout << '\n';
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
