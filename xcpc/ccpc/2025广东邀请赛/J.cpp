#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 1);
    priority_queue<array<i64, 3>, vector<array<i64, 3>>, greater<array<i64, 3>>> heap;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        if(v[i] == 0) {
            heap.push({0, i, 1});
        }
    }

    for(int i = 0; i < k; i ++) {
        int t, c;
        cin >> t >> c;
        for(int j = 0; j < c; j ++) {
            int x;
            cin >> x;
            heap.push({t, x, 1});
        }
    }

    vector<vector<array<int, 2>>> adj(n + 1); 
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    vector<i64> ans(n + 1, -1);
    while(heap.size()) {
        auto [t, x, op] = heap.top();
        heap.pop();

        if(ans[x] != -1) {
            continue;
        }

        if(!op && --v[x] > 0) {
            continue;
        }

        ans[x] = t;
        for(auto [y, w] : adj[x]) {
            heap.push({t + w, y, 0});
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
