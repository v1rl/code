#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    int ans = 0;
    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        bool f = true;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
            if(!(siz[y] & 1)) {
                f = false;
            }
        }
        if(x != 1 && (n - siz[x]) % 2 == 0) {
            f = false;
        }
        ans += f;
    };

    dfs(dfs, 1, -1);
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