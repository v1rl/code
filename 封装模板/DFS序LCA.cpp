#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
存dfn序为下标，节点id为值的st表
*/

const int N = 20;

void solve() {
    int n, m, rt;
    cin >> n >> m >> rt;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> dfn(n + 1);
    vector<array<int, N>> st(n + 1);
    int cnt = 0;
    auto dfs = [&](auto &&self, int x, int p) -> void {
        dfn[x] = ++ cnt;
        st[dfn[x]][0] = p;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
        }
    };

    dfs(dfs, rt, 0);

    auto getMin = [&](int x, int y) {
        return dfn[x] < dfn[y] ? x : y;
    };

    for(int j = 1; j < N; j ++) {
        int len = 1 << j;
        int half = len >> 1;
        for(int i = 1; i + len - 1 <= n; i ++) {
            st[i][j] = getMin(st[i][j - 1], st[i + half][j - 1]);
        }
    }
    vector<int> lg(n + 1);
    for(int i = 2; i <= n; i ++) {
        lg[i] = lg[i >> 1] + 1;
    }

    auto lca = [&](int x, int y) {
        if(x == y) {
            return x;
        }
        x = dfn[x], y = dfn[y];
        if(x > y) {
            swap(x, y);
        }
        x ++;
        int j = lg[y - x + 1];
        return getMin(st[x][j], st[y - (1 << j) + 1][j]);
    };

    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

