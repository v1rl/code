#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意题目特殊的数据范围
*/

void solve() {
    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<array<int, 2>>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back({y, c});
    }

    vector<int> st(n + 1);
    auto dfs = [&](auto &&self, int x, int cnt, int sum) -> void {
        if(cnt > l) {
            return;
        }
        if(cnt == l && sum >= s && sum <= t) {
            st[x] = true;
        }
        for(auto [y, w] : adj[x]) {
            self(self, y, cnt + 1, sum + w);
        }
    };

    dfs(dfs, 1, 0, 0);
    for(int i = 1; i <= n; i ++) {
        if(st[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}