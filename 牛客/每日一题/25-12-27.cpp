#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意到，如果子树为偶数，断开与否并不会影响剩余部分的奇偶
所以所有大小为偶数的子树都可以断开
*/

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

    if(n & 1) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;
    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto && self, int x, int p) -> void {
        bool f = false;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            f = true;
            self(self, y, x);
            siz[x] += siz[y];
        }
        if(siz[x] % 2 == 0) {
            ans ++;
        }
    };

    dfs(dfs, 1, -1);

    cout << ans - 1 << '\n';
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
