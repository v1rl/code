#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> in(n + 1), out(n + 1);
    vector<int> fa(n + 1);
    int tsp = 0;
    auto dfs = [&](auto &&self, int x) -> void {
        in[x] = ++tsp;
        for(auto y : adj[x]) {
            if(y == fa[x]) {
                continue;
            }
            fa[y] = x;
            self(self, y);
        }
        out[x] = tsp;
    };
    dfs(dfs, 1);

    auto isParent = [&](int x, int y) {
        if(in[x] <= in[y] && out[x] >= out[y]) {
            return true;
        }
        return false;
    };

    int H, L;
    H = L = pos[0];
    vector<int> ans(n + 1);
    for(int i = 1; i <= n - 1; i ++) {
        int P = pos[i];
        if(isParent(P, H)) {
            while(H != P) {
                ans[H] = i;
                H = fa[H];
            }
        } else if(isParent(H, P) && isParent(P, L)) {
            ;
        } else if(isParent(L, P)) {
            L = P;
        } else {
            while(H != 0) {
                ans[H] = i;
                H = fa[H];
            }
            break;
        }
    }
    while(H != 0) {
        ans[H] = n;
        H = fa[H];
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
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
