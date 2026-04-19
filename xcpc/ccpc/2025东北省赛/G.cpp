#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    if(n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    vector<int> vec;
    for(int i = 1; i <= n; i ++) {
        if(adj[i].size() % 2 == 1) {
            vec.emplace_back(i);
        }
    }

    vector<array<int, 2>> edges;
    for(int i = 1; i < vec.size(); i += 2) {
        edges.push_back({vec[i], vec[i - 1]});
    }
    cout << edges.size() << '\n';
    for(auto [x, y] : edges) {
        cout << x << ' ' << y << '\n';
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
