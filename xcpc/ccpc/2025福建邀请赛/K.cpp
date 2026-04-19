#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>>adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<array<i64, 2>> st(n + 1);
    array<i64, 2> mn{inf, inf};
    auto dfs = [&](auto &&self, int x, int p) -> void {
        auto [v, op] = st[x];
        mn[op] = min(mn[op], v);
        for(auto [y, w] : adj[x]) {
            if(y == p) {
                continue;
            }
            st[y] = {w - v, op ^ 1};
            self(self, y, x);
        }
    };

    st[1] = {0, 0};
    dfs(dfs, 1, -1);
    i64 l = 1, r = inf;

    // cout << mn[0] << ' ' << mn[1] << '\n';

    if(mn[0] != inf) {
        l = max(l, -mn[0] + 1);
    }
    r = min(mn[1] - 1, r);
    if(l > r) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        i64 x = l;
        for(int i = 1; i <= n; i ++) {
            auto [v, op] = st[i];
            if(op) {
                cout << -x + v << ' ';
            } else {
                cout << x + v << ' ';
            }
        }
    }
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
