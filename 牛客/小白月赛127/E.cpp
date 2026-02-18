#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
对所有边执行遍历
下方节点子树作为一个集合，n-子树-深度作为另一个集合
*/

const int inf = 1e9;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<array<int, 2>> edges;

    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        edges.push_back({x, y});
    }

    vector<int> dep(n + 1), siz(n + 1, 1);
    dep[1] = 1;
    
    auto dfs = [&](auto && self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            dep[y] = dep[x] + 1;
            self(self, y, x);
            siz[x] += siz[y];
        }
    };

    dfs(dfs, 1, -1);

    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += siz[i] - 1;
    }

    for(auto [x, y] : edges) {
        if(dep[x] > dep[y]) {
            swap(x, y);
        }
        ans += 1ll * siz[y] * (n - siz[y] - dep[x]) % mod;
        ans %= mod;
    }

    cout << ans << '\n';
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
