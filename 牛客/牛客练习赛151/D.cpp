#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;

/*
dp[i][0/1] 表示第i个子树，获得与不获得父节点边的出度时的最大答案
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

    vector f(n + 1, vector(2, 0ll));
    auto dfs = [&](auto &&self, int x, int p) -> void{
        vector<i64> cur;
        i64 s1 = 0;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            cur.emplace_back(f[y][0] - f[y][1]);
            s1 += f[y][1];
        }

        sort(cur.begin(), cur.end(), greater());
        int m = adj[x].size();
        if(x != 1) {
            m --;
        }
        
        for(int c = 0; c < 2; c ++) {
            i64 mx = c * c;
            i64 pre = 0;
            for(int i = 0; i <= m; i ++) {
                if(i != 0) {
                    pre += cur[i - 1];
                }
                i64 res = 1ll * (c + i) * (c + i) + s1 + pre;
                mx = max(mx, res);
            }
            f[x][c] = mx;
        }
    };

    dfs(dfs, 1, -1);

    cout << f[1][0] << '\n';
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
