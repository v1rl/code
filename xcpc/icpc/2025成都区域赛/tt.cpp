#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    i64 ans = 0;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> siz(n);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        siz[x] = 1;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(y, x);
            siz[x] += siz[y];
        }
        if (siz[x] >= k) {
            ans += n - siz[x];
        }
        if (n - siz[x] >= k) {
            ans += siz[x];
        }
    } (0, -1);
    
    ans += n;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}